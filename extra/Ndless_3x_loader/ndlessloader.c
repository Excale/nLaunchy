// Marker at the beginning of a program
#define PRGMSIG "PRG"
// Directory where it is installed
#define NDLESS_DIR "/documents/ndless"
typedef void FILE;
struct stat {
    unsigned short st_dev;
    unsigned int st_ino; // 0
    unsigned int st_mode; // see S_ macros above
    unsigned short st_nlink; // 1
    unsigned short st_uid; // 0
    unsigned short st_gid; // 0
    unsigned short st_rdev; // = st_dev
    unsigned int st_size;
    unsigned int st_atime;
    unsigned int st_mtime;
    unsigned int st_ctime;
};
#define fopen ((void*(*)(const char *, const char *))0xAAAAAAAA)
#define _stat ((void (*)(const char *, void *))0xBBBBBBBB)
#define malloc ((void*(*)(unsigned int))0xCCCCCCCC)
#define fread ((void*(*)(void *, unsigned int, unsigned int, FILE *))0xDDDDDDDD)
#define fclose ((void (*)(void *))0xEEEEEEEE)



int main(void) {
    struct stat res_stat;

    //Watchdog
    *(volatile unsigned*)0x90060C00 = 0x1ACCE551;
    *(volatile unsigned*)0x90060008 = 0;
    *(volatile unsigned*)0x90060C00 = 0;


    const char *res_path = NDLESS_DIR "/ndless_resources\0\0\0\0\0\0\0\0";
    FILE * res_file;
    if ( (res_file=fopen(res_path, "rb")) )
    {
        _stat(res_path, &res_stat);
        char *core = malloc(res_stat.st_size);
        fread(core, res_stat.st_size, 1, res_file);
        fclose(res_file);
        char *res_params = "L"; // Dummy filename to tell the installer we are booting or installing, and not running ndless_resources
        unsigned dummy;
        __asm volatile(
            " .arm \n"
            "0: mrc p15, 0, r15, c7, c10, 3 @ test and clean DCache \n"
            " bne 0b \n"
            " mov %0, #0 \n"
            " mcr p15, 0, %0, c7, c7, 0 @ invalidate ICache and DCache \n"
        : "=r" (dummy));
        ((void (*)(int argc, void* argv))(char*)core + sizeof(PRGMSIG))(1, &res_params); // Run the core installation
    }
    return 0;
}
