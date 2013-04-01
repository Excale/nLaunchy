#include <os.h>
#include "ndless.h"

// OS-specific
extern char _binary_ndless_installer_bin_3_1_0_ncas_tmp_o_start[];
extern char _binary_ndless_installer_bin_3_1_0_ncas_tmp_o_end[];
extern char _binary_ndless_installer_bin_3_1_0_cas_tmp_o_start[];
extern char _binary_ndless_installer_bin_3_1_0_cas_tmp_o_end[];
extern char _binary_ndless_installer_bin_3_1_0_ncascx_tmp_o_start[];
extern char _binary_ndless_installer_bin_3_1_0_ncascx_tmp_o_end[];
extern char _binary_ndless_installer_bin_3_1_0_cascx_tmp_o_start[];
extern char _binary_ndless_installer_bin_3_1_0_cascx_tmp_o_end[];

// OS-specific
static char* const os_patch_data_addrs[] = {
    _binary_ndless_installer_bin_3_1_0_ncas_tmp_o_start,
    _binary_ndless_installer_bin_3_1_0_cas_tmp_o_start,
    _binary_ndless_installer_bin_3_1_0_ncascx_tmp_o_start,
    _binary_ndless_installer_bin_3_1_0_cascx_tmp_o_start,
};
// OS-specific
static char* const os_patch_data_end_addrs[] = {
    _binary_ndless_installer_bin_3_1_0_ncas_tmp_o_end,
    _binary_ndless_installer_bin_3_1_0_cas_tmp_o_end,
    _binary_ndless_installer_bin_3_1_0_ncascx_tmp_o_end,
    _binary_ndless_installer_bin_3_1_0_cascx_tmp_o_end,
};

static void freados(void * ptr, size_t count, FILE * stream) {
    if (fread(ptr, 1, count, stream) != count)
        ut_panic("can't fread from OS file");
}

static void fwriteos(const void *ptr, size_t count, FILE *stream) {
    if (fwrite(ptr, 1, count, stream) != count)
        ut_panic("can't fwrite to OS file");
}

static void fseekos(FILE *stream, long int offset, int origin) {
    if (fseek(stream, offset, origin))
        ut_panic("can't fseek in OS file");
}

static int ftellos(FILE *stream) {
    int r = ftell(stream);
    if (r == -1)
        ut_panic("can't ftell in OS file");
    return r;
}

static void fcloseos(FILE *stream) {
    if (fclose(stream))
        ut_panic("can't fclose OS file");
}

static const char zipped_file_header[] = "\x50\x4B\x03\x04\x0A\x00\x00\x00\x00\x00\xCA\x89\x0E\x3F\x07\xDF\x3A\xED\x1A\x6B\x6D\x00\x1A\x6B\x6D\x00";

static char ospath[] = "/phoenix/install/TI-Nspire.tnc";

// The installation makes the OS miss a fclose().
// It's ospath on OS startup, and is a problem for persistent():
// persistent()'s truncate() will fail if the file is open twice
static void cleanup_file_leak(void) {
    PCFD fd = NU_Open(ospath, 0, 0); // any file will do to get a fd
    if (fd < 0) ut_panic("can't NU_Open OS file");
    NU_Close(fd - 1); // the FILE* is unknown, this is an heuristic
    NU_Close(fd);
}

// Returns TRUE if it's an update
static BOOL persistent(BOOL only_uninstall) {
    nl_relocdata((unsigned*)os_patch_data_addrs, sizeof(os_patch_data_addrs)/sizeof(os_patch_data_addrs[0]));
    nl_relocdata((unsigned*)os_patch_data_end_addrs, sizeof(os_patch_data_end_addrs)/sizeof(os_patch_data_end_addrs[0]));
    unsigned patch_data_size = os_patch_data_end_addrs[ut_os_version_index] - os_patch_data_addrs[ut_os_version_index];
    unsigned new_pkfile_size =  sizeof(zipped_file_header) - 1 + patch_data_size;

    FILE *f = fopen(ospath, "r+b");
    if (!f) ut_panic("can't open OS file");

    // Insert before boot2.cer, read at OS startup, or at the end of the zip file
    // Search the position
    int c;
    unsigned current_pkfile_size = 0;
    do {
        c = fgetc(f);
        if (c == EOF)
            ut_panic("can't skip the OS file header");
    } while(c != 0x1A);
    while (1) {
        unsigned sig;
        freados(&sig, sizeof(sig), f);
        if (sig == 0x04034B50) { // local file header
            fseekos(f, 18 - 4, SEEK_CUR);
            unsigned short filename_len, extra_field_len;
            unsigned int compressed_size;
            freados(&compressed_size, sizeof(compressed_size), f);
            fseekos(f, 4, SEEK_CUR);
            freados(&filename_len, sizeof(filename_len), f);
            freados(&extra_field_len, sizeof(extra_field_len), f);
            char filename[20];
            if (filename_len >= sizeof(filename)) // it may be us
                filename_len = sizeof(filename) - 1;
            if (!fgets(filename, filename_len, f))
                ut_panic("can't fgets in OS file");
            if (!strcmp(filename, "boot2.cer")) {
                fseekos(f, -(filename_len + 30), SEEK_CUR);
                break;
            } else if (!strcmp(filename, "ndless")) {
                current_pkfile_size = compressed_size + sizeof(zipped_file_header) - 1;
                fseekos(f, -(filename_len + 30), SEEK_CUR);
                break;
            } else {
                fseekos(f, extra_field_len + compressed_size, SEEK_CUR);
            }
        } else if (sig == 0x02014B50) { // central directory
            fseekos(f, -4, SEEK_CUR);
            break;
        } else {
            ut_panic("bad OS file format");
        }
    }

    long destpos = ftellos(f);
    #define CHUNK_SIZE (1024*100)
    void *shift_buf = malloc(CHUNK_SIZE);
    if (!shift_buf) ut_panic("can't malloc shift_buf for uninstallation");

    if (only_uninstall || new_pkfile_size < current_pkfile_size) {
        // Uninstall by reducing the file: shift the content from destpos chunk by chunk
        unsigned uninst_size = only_uninstall ? current_pkfile_size : current_pkfile_size - new_pkfile_size;
        long curpos = destpos + uninst_size;
        while (1) {
            fseekos(f, curpos, SEEK_SET);
            size_t can_read_size = fread(shift_buf, 1, CHUNK_SIZE, f);
            if (can_read_size) {
                fseekos(f, curpos - uninst_size, SEEK_SET);
                fwriteos(shift_buf, can_read_size, f);
            }
            if (can_read_size != CHUNK_SIZE) break;
            curpos += CHUNK_SIZE;
        }
        fseekos(f, 0, SEEK_END);
        unsigned osfile_size = ftellos(f) - uninst_size;
        fcloseos(f);
        if (truncate(ospath, osfile_size))
            ut_panic("can't truncate");
        f = fopen(ospath, "r+b");
        if (!f) ut_panic("can't reopen OS file");
    }

    if (only_uninstall) {
        fclose(f);
        free(shift_buf);
        return FALSE;
    }

    if (new_pkfile_size > current_pkfile_size) {
        // Extend the file: shift the content from the end chunk by chunk
        unsigned insert_size =  new_pkfile_size - current_pkfile_size;
        fseekos(f, -CHUNK_SIZE, SEEK_END);
        long curpos = ftellos(f);
        while (curpos >= destpos) {
            fseekos(f, curpos, SEEK_SET);
            freados(shift_buf, CHUNK_SIZE, f);
            fseekos(f, curpos + insert_size, SEEK_SET);
            fwriteos(shift_buf, CHUNK_SIZE, f);
            curpos -= CHUNK_SIZE;
        }
        if (curpos + CHUNK_SIZE - destpos) {
            fseekos(f, destpos, SEEK_SET);
            freados(shift_buf, curpos + CHUNK_SIZE - destpos, f);
            fseekos(f, destpos + insert_size, SEEK_SET);
            fwriteos(shift_buf, curpos + CHUNK_SIZE - destpos, f);
        }
    }
    free(shift_buf);

    // Write the header
    fseekos(f, destpos, SEEK_SET);
    fwriteos(zipped_file_header, sizeof(zipped_file_header) - 1, f);
    fseekos(f, -(sizeof(zipped_file_header) - 1) + 18, SEEK_CUR); // compressed size
    fwriteos(&patch_data_size, sizeof(patch_data_size), f);
    fseekos(f, 4, SEEK_CUR); // skip the uncompressed size
    // write the payload
    fwriteos(os_patch_data_addrs[ut_os_version_index], patch_data_size, f);
    fcloseos(f);
    return (current_pkfile_size != 0);
}

// OS-specific
// Call to the dialog box display telling that the format isn't recognized.
static unsigned const ploader_hook_addrs[] = {0x10009984, 0x1000995C, 0x10009924, 0x10009924};

// OS-specific
static unsigned const init_task_return_addrs[] = {0x10001548, 0x10001548, 0x10001510, 0x10001510};

// OS-specific
static unsigned const api100_task_return_addrs[] = {0x100777A0, 0x10077708, 0x10076E9C, 0x10076e2c};

// OS-specific
static unsigned const end_of_init_addrs[] = {0X100104F0, 0x10010478, 0x100104BC, 0x1001046C};

int main(int __attribute__((unused)) argc, char* argv[]) {
    ut_debug_trace(INSTTR_INS_ENTER);
    ut_read_os_version_index();
    BOOL installed = FALSE;

    struct next_descriptor *installed_next_descriptor = ut_get_next_descriptor();
    if (installed_next_descriptor) {
        if (*(unsigned*)installed_next_descriptor->ext_name == 0x534C444E) // 'NDLS'
            installed = TRUE;
        else
            ut_panic("unknown N-ext");
    }

    if (argv[0][0] != '/') { // not ndless_resources run
        ints_setup_handlers();
        sc_setup();
    }

    if (!installed) {
        HOOK_INSTALL(ploader_hook_addrs[ut_os_version_index], plh_hook);
        HOOK_INSTALL(end_of_init_addrs[ut_os_version_index], plh_startup_hook);
        lua_install_hooks();
    }

    //NU_TASK *current_task  = TCC_Current_Task_Pointer();
    //char *task_name = ((char*)current_task) + 16;
    /*if (!strcmp(task_name, "API-100.")) { // Installation over USB
        BOOL is_update = persistent(FALSE);
        show_msgbox("Ndless", is_update ? "Ndless successfully updated!\nThe device will now reboot.\n*Always* keep 'ndless/ndless_resources.tns'." : "Ndless successfully installed!\n*Always* keep 'ndless/ndless_resources.tns'.");
        if (is_update) ut_calc_reboot();
        // simulate cleanup function prolog and return to it, required for OS reception not to be broken afterwards
        // current_task + 0x64 contain a resource expected in r4
        __asm volatile("ldr r4, [%1,#0x64]; adr lr, 0f; stmfd sp!, {r4-r8,r10,lr}; sub sp, sp, #0x1C; mov pc, %0; 0:" : : "r" (api100_task_return_addrs[ut_os_version_index]), "r" (current_task));
        TCC_Terminate_Task(current_task);
    }
    else { // either OS startup or ndless_resources.tns run
        if (installed) { // ndless_resources.tns run: uninstall
            //if (show_msgbox_2b("Ndless", "Do you really want to uninstall Ndless?\nThe device will reboot.", "Yes", "No") == 2)
                return 0;
            //persistent(TRUE);
            //ut_calc_reboot();
        }
        cleanup_file_leak();
        // Continue OS startup
        // Simulate the prolog of the thread function for correct function return. Set r4 to a dummy variable, written to by a sub-function that follows.
        //__asm volatile("add lr, pc, #8; stmfd sp!, {r4-r6,lr}; sub sp, sp, #0x18; mov r4, sp; mov pc, %0" : : "r" (init_task_return_addrs[ut_os_version_index]));
    //}
    // never reached*/
    return 0;
}
