/*
 * nLaunchy v2.2b
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

#include "nlaunch.h"

// ================================================================================================
// Variables
// ================================================================================================
static uint32_t os_version = 0;
static uint8_t  do_install_resources = 0;
static const char osfilename[] = "/phoenix/install/phoenix.tns";
static const char osupdatefilename[] = "/documents/nlaunch/phoenix.tns";
static const char osoldfilename[] = "/documents/nlaunch/phoenix.old.tns";
static const char linuxloaderfilename[] = "/documents/linux/linuxloader.tns";
static const char nlaunchupdatefilename[] = "/documents/nlaunch/nlaunch.tns";


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

//! Make the launcher reboot-proof.
static __attribute((always_inline)) void make_reboot_proof(void) {
    FILE * nlaunchfile;
    if ((nlaunchfile = fopen((char *)NLAUNCHPATH, "r"))) {
        fclose(nlaunchfile);
        if ((nlaunchfile = fopen((char *)nlaunchupdatefilename, "r"))) {
            fclose(nlaunchfile);
            unlink((char *)NLAUNCHPATH);
            rename((char *)nlaunchupdatefilename, (char *)NLAUNCHPATH);
            hw_reset();
            __builtin_unreachable();
        }
    } else {
        rename((char *)TEMPPATH, (char *)NLAUNCHPATH);
        do_install_resources = 1;
    }
}

//! Update the OS if needed.
static __attribute((always_inline)) void update_OS(void) {
    FILE * osfile;
    if ((osfile = fopen((char *)osupdatefilename, "r"))) {
        fclose(osfile);
        if( rename((char *)osfilename, (char *)osoldfilename) ) {
            rename((char *)osupdatefilename, (char *)osfilename);
            do_install_resources = 1;
        } else
        {
            #if DEBUG
            DISPLAY(K);
            #endif
        }
    }
}

//! Install the OS's resources.
static __attribute__((always_inline)) void install_resources(void) {
    if (do_install_resources) {
        FILE * osfile;
        FILE * nlaunchfile;
        M(,FILE * nlaunchfile2;)
        if ( (osfile = fopen((char *)osfilename, "r")) && (nlaunchfile = fopen((char *)OSPATH, "r")) M(,&& (nlaunchfile2 = fopen((char *)NLAUNCHPATH, "r"))) ) {
            purge_files("/phoenix", 0);
            purge_files("/ti84"   , 0);
            fclose(osfile);
            fclose(nlaunchfile);
            M(,fclose(nlaunchfile2);)
        }

        strcpy( (char *)OSPATH, osfilename);

        rename((char *)OSPATH, (char *)TEMPPATH);
        put_word(M(0x1192C220,0x11ABBA54), 0xE1A00009);
        asm volatile(
            "LDR    R0, =" M("0x11952E6C","0x118D940C") "\n\t"
            "LDR    R1, =" M("0x1192C2C8","0x11AB9730") "\n\t"
            "LDR    R9, =" M("0x11952E6C","0x118D940C") "\n\t"
            "MOV    LR, PC                               \n\t"
            "LDR    PC, =" M("0x1192C120","0x11ABB96C") "\n\t"
        );
        rename((char *)TEMPPATH, (char *)OSPATH);
        hw_reset();
        __builtin_unreachable();
    }
}

//! Load the OS.
static __attribute__((always_inline)) void load_OS(void) {

    unsigned short keypad = *(volatile unsigned short*)0x900E001C;
    keypad &= (1<<9); /* TAB key */
    strcpy( (char *)OSPATH, ((!keypad) ^ MODEL)? linuxloaderfilename : osfilename );
        
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
    if ( load_os(1) ) {
        #if DEBUG
        DISPLAY(F);
        #endif
        while(1) {}
        __builtin_unreachable();
    }
}
//! Detect the OS version.
static __attribute__((always_inline)) void detect_OS_version(void) {
    os_version = get_word(0x10000020);
}

#include "patch.c"

//! Jump to OS, without return.
static __attribute__((always_inline, noreturn)) void launch_OS(void) {
    asm volatile(
        "LDR    PC, =0x10000000    \n\t"
    );
    __builtin_unreachable();
}

int main(void) {

    {
        int dummy;
        // Invalidate caches
        asm volatile(
        "0: mrc p15, 0, r15, c7, c10, 3 @ test and clean DCache \n"
        " bne 0b \n"
        " mov %0, #0 \n"
        " mcr p15, 0, %0, c7, c7, 0 @ invalidate ICache and DCache\n"
        : "=r" (dummy));
        *(volatile unsigned*)0x90060C00 = 0x1ACCE551;
        *(volatile unsigned*)0x90060008 = 0;
        *(volatile unsigned*)0x90060C00 = 0;
    }
    
    #if MODEL==0
        asm volatile(
            "ADD    R1, PC, #0x10   \n\t"
            "LDR    R0, =0x11F10000 \n\t"
            "LDR    R2, =0x2000     \n\t"
            "MOV    LR, PC          \n\t"
            "LDR    PC, =0x11856CCC \n\t"
            "LDR    PC, =0x11F10000 \n\t"
        );
        put_byte(0x1181FD6B, 0xEA);
        put_word(0x1180091C, NOP);
        fclose((void *)0x11A6D4A8);
    #endif

        DISPLAY(1);
    make_reboot_proof();
        DISPLAY(2);
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
