/*
 * nLaunchy v2.1
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013 nLaunch CX guy
 * Copyright (C) 2013 Excale
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 */

#include <stdint.h>

// ================================================================================================
// Definitions
// ================================================================================================

//! Build options: MODEL:[0=CLASSIC,1=CX], DEBUG:[0-3], NDLESS[0,1=Include Ndless Loader]
/** Set in Makefile
#define MODEL  0 */
#define DEBUG  2
#define NDLESS 1
//! End of build options

#if MODEL==0
  #define M(x,y) x
#elif MODEL==1
  #define M(x,y) y
#endif
#if DEBUG>1
  #define DISPLAY(x) display_msg_to_screen(M(#x,u## #x), 0, 0)
#elif DEBUG>0
  #define DISPLAY(x) display_msg_to_screen(M(" ",u" ") , 0 ,0)
#else
  #define DISPLAY(x)
#endif
#if DEBUG>2
  #define EMIT_NOP asm volatile("NOP\n\t")
#else
  #define EMIT_NOP
#endif


/**
 * \brief The hex value of a NOP instruction.
 * \note E1A00000 is usually used for NOP, but we use 00000000 to work around compiler weirdness.
 */
#define NOP 0x00000000

//! HW_reset from boot2
#define boot2_HW_reset ((void(*)(void))M(0x11831008,0x118C62BC))
//! load_os from boot2
#define boot2_load_os  ((int (*)(uint32_t))M(0x11802B10,0x11AB7810))
//! rename from boot2
#define boot2_rename   ((int (*)(const char *, const char *))M(0x11859D08,0x11A58A60))
//! fopen from boot2
#define boot2_fopen    ((void *(*)(const char *, const char *))M(0x11856590,0x118AB7B8))
//! fclose from boot2
#define boot2_fclose   ((int (*)(void *))M(0x1185634C,0x118AB53C))
//! unlink from boot2
#define boot2_unlink   ((int (*)(const char *))M(0x1185A238,0x11A58F88))
//! mkdir from boot2
#define boot2_mkdir M(,((int (*)(const char *))M(,0x11A5772C)))
//! purge_temp_files from boot2
#define boot2_purge_files       ((void(*)(const char*, int))M(0x1192ACF4,0x11AB994C))
//! display_msg_to_screen from boot2
#define display_msg_to_screen   ((void(*)(M(const char *, short unsigned int *), uint32_t, uint32_t))M(0x11801C94,0x1187F9F8))
//! OS path from boot2
#define OSPATH   M(0x11953920,0x118D9DA4)
//! temp OS path from boot2
#define TEMPPATH M(0x11952E6C,0x118D940C)
//! nLaunch path
#define NLAUNCHPATH M(OSPATH,"/phoenix/install/nlaunch.tns")

// ================================================================================================
// Variables
// ================================================================================================
static uint32_t os_version = 0;
static uint8_t  do_install_resources = 0;
static const char osfilename[] = "/phoenix/install/phoenix.tns";
static const char osupdatefilename[] = "/documents/nlaunch/phoenix.tns";
static const char osoldfilename[] = "/documents/nlaunch/phoenix.old.tns";
static const char nlaunchupdatefilename[] = "/documents/nlaunch/nlaunch.tns";
typedef void FILE;


// ================================================================================================
// Functions
// ================================================================================================
static __attribute__((always_inline)) uint32_t get_word(uint32_t absaddr) {
    return *((uint32_t *)absaddr);
}

static __attribute__((always_inline)) void put_word(uint32_t absaddr, uint32_t long_in) {
    *((uint32_t *)absaddr) = long_in;
}

static __attribute__((always_inline)) void put_byte(uint32_t absaddr, uint8_t short_in) {
    *((uint8_t  *)absaddr) = short_in;
}

//! Write new OS filename to the given address.
static __attribute__((noinline)) void write_osfilename(uint32_t address) {
    unsigned int i;
    char * src  = (char *)osfilename;
    char * dest = (char *)address;
    for (i = 0; i < sizeof(osfilename); i++) {
        *dest++ = *src++;
    }
    EMIT_NOP;
}

//! Make the launcher reboot-proof.
static __attribute((always_inline)) void make_reboot_proof(void) {
    FILE * nlaunchfile;
    if ((nlaunchfile = boot2_fopen((char *)NLAUNCHPATH, "r"))) {
        boot2_fclose(nlaunchfile);
        if ((nlaunchfile = boot2_fopen((char *)nlaunchupdatefilename, "r"))) {
            boot2_fclose(nlaunchfile);
            boot2_unlink((char *)NLAUNCHPATH);
            boot2_rename((char *)nlaunchupdatefilename, (char *)NLAUNCHPATH);
            boot2_HW_reset();
            __builtin_unreachable();
        }
    } else {
        boot2_rename((char *)TEMPPATH, (char *)NLAUNCHPATH);
        do_install_resources = 1;
    }
    EMIT_NOP;
}

//! Update the OS if needed.
static __attribute((always_inline)) void update_OS(void) {
    FILE * osfile;
    if ((osfile = boot2_fopen((char *)osupdatefilename, "r"))) {
        boot2_fclose(osfile);
        boot2_rename((char *)osfilename, (char *)osoldfilename);
        boot2_rename((char *)osupdatefilename, (char *)osfilename);
        do_install_resources = 1;
    }
    EMIT_NOP;
}

//! Install the OS's resources.
static __attribute__((always_inline)) void install_resources(void) {
    if (do_install_resources) {
        FILE * osfile;
        FILE * nlaunchfile;
        M(,FILE * nlaunchfile2;)
        if ( (osfile = boot2_fopen((char *)osfilename, "r")) && (nlaunchfile = boot2_fopen((char *)OSPATH, "r")) M(,&& (nlaunchfile2 = boot2_fopen((char *)NLAUNCHPATH, "r"))) ) {
            boot2_purge_files("/phoenix", 0);
            boot2_purge_files("/ti84"   , 0);
            boot2_fclose(osfile);
            boot2_fclose(nlaunchfile);
            M(,boot2_fclose(nlaunchfile2);)
        }

        write_osfilename(OSPATH);

        boot2_rename((char *)OSPATH, (char *)TEMPPATH);
        put_word(M(0x1192C220,0x11ABBA54), 0xE1A00009);
        asm volatile(
            "LDR    R0, =" M("0x11952E6C","0x118D940C") "\n\t"
            "LDR    R1, =" M("0x1192C2C8","0x11AB9730") "\n\t"
            "LDR    R9, =" M("0x11952E6C","0x118D940C") "\n\t"
            "MOV    LR, PC                               \n\t"
            "LDR    PC, =" M("0x1192C120","0x11ABB96C") "\n\t"
        );
        boot2_rename((char *)TEMPPATH, (char *)OSPATH);
        boot2_HW_reset();
        __builtin_unreachable();
    }
    EMIT_NOP;
}

//! Load the OS.
static __attribute__((always_inline)) void load_OS(void) {
    write_osfilename(OSPATH);
    #if MODEL==0
    put_word(0x11800970, 0xE12FFF1E);
    put_byte(0x11802293, 0xEA);
    put_word(0x118023E4, NOP);
    put_word(0x118023F4, NOP);
    put_word(0x11802404, NOP);
    put_word(0x11802424, NOP);
    put_word(0x11802930, NOP);
    put_word(0x11802970, NOP);
    put_word(0x11802AC4, NOP);
    #elif MODEL==1
    put_word(0x1187D33C, 0xE12FFF1E);
    put_word(0x11AB6E4C, 0xE59F3000);
    put_word(0x11AB6E50, 0xEA000000);
    put_word(0x11AB6E54, 0x11AB9B14);
    put_byte(0x11AB6EC7, 0xEA);
    put_word(0x11AB6F48, NOP);
    put_word(0x11AB6F68, NOP);
    put_word(0x11AB6F88, NOP);
    put_word(0x11AB6FB8, NOP);
    put_byte(0x11AB71AB, 0xEA);
    put_word(0x11AB7420, 0xEA000092);
    put_word(0x11AB76BC, NOP);
    #endif
    boot2_load_os(1);
    EMIT_NOP;
}
//! Detect the OS version.
static __attribute__((always_inline)) void detect_OS_version(void) {
    os_version = get_word(0x10000020);
    #if DEBUG
    if ( os_version<0x10000000 || os_version> M(0x12000000,0x14000000) ) {
        DISPLAY(F);
    }
    #endif
    EMIT_NOP;
}

//! Check for dualboot request
static __attribute__((always_inline)) void check_dualboot(void) {
    unsigned short kp = *(volatile unsigned short*)0x900E001C;
    kp &= (1<<9); /* TAB key */
    if ((!kp) ^ MODEL) {
        boot2_rename((char *)osoldfilename, (char *)osupdatefilename);
        DISPLAY(X);
    }
}

#include "patch.c"

//! Jump to OS, without return.
static __attribute__((always_inline, noreturn)) void launch_OS(void) {
    EMIT_NOP;
    asm volatile(
        "LDR    PC, =0x10000000    \n\t"
    );
    __builtin_unreachable();
}

int main(void) {

    #if MODEL==0
        put_word(M(0x11801204,0x1187E1C0), NOP);
        asm volatile(
            "ADD    R1, PC, #0x48                        \n\t"
            "LDR    R0, =0x11F10000                      \n\t"
            "LDR    R2, =0x1000                          \n\t"
            "MOV    LR, PC                               \n\t"
            "LDR    PC, =" M("0x11856CCC","0x118AC558") "\n\t"
            "LDR    R1, =0xE51FF004                      \n\t"
            "LDR    R0, =" M("0x11801244","0x1187E208") "\n\t"
            "STR    R1, [R0]                             \n\t"
            "LDR    R1, =0x11F10000                      \n\t"
            "LDR    R0, =" M("0x11801248","0x1187E20C") "\n\t"
            "STR    R1, [R0]                             \n\t"
            "LDR    R1, =0x1ACCE551                      \n\t"
            "LDR    R0, =0x90060C00                      \n\t"
            "STR    R1, [R0]                             \n\t"
            "LDR    R0, =0x90060008                      \n\t"
            "MOV    R1, #0                               \n\t"
            "STR    R1, [R0]                             \n\t"
            "LDR    R0, =0x90060C00                      \n\t"
            "STR    R1, [R0]                             \n\t"
            "LDR    PC, =0x11800000                      \n\t"
        );
    #endif

    {
        int dummy;
        // Invalidate caches
        asm volatile(
        "0: mrc p15, 0, r15, c7, c10, 3 @ test and clean DCache \n"
        " bne 0b \n"
        " mov %0, #0 \n"
        " mcr p15, 0, %0, c7, c7, 0 @ invalidate ICache and DCache\n"
        : "=r" (dummy));
    }

        DISPLAY(1);
    make_reboot_proof();
        DISPLAY(2);
    check_dualboot();
    update_OS();
        DISPLAY(3);
    install_resources();
        DISPLAY(4);
    load_OS();
        DISPLAY(5);
    detect_OS_version();
        DISPLAY(6);
    patch_OS();
        DISPLAY(7);
    launch_OS();
}
