/*
 * nLaunchy v2.4
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2014 Excale
 * Copyright (C) 2013      Lionel Debroux
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
static uint8_t    do_install_resources = 0;
static const char osfilename[] =            "/phoenix/install/phoenix.tns";
static const char nlaunchupdatefilename[] = "/documents/nlaunch/nlaunch.tns";
static const char osupdatefilename[] =      "/documents/nlaunch/phoenix.tns";
#if MULTIOS
static       char osmultiupdatefilename[] = "/documents/nlaunch/phoenix_0.tns";
#endif
static const char osoldfilename[] =         "/documents/nlaunch/phoenix.old.tns";
static const char linuxloaderfilename[] =   "/documents/linux/linuxloader.tns";


// ================================================================================================
// Functions
// ================================================================================================
static __attribute__((always_inline)) void put_word(uint32_t absaddr, uint32_t long_in) {
    *((uint32_t *)absaddr) = long_in;
}

static __attribute__((always_inline)) void put_byte(uint32_t absaddr, uint8_t short_in) {
    *((uint8_t  *)absaddr) = short_in;
}

//! Update nLaunchy if needed.
static __attribute__((always_inline)) void update_nlaunch(void) {
    FILE * nlaunchfile;
    if ((nlaunchfile = fopen(nlaunchupdatefilename, "r"))) {
        fclose(nlaunchfile);
        unlink(NLAUNCHPATH);
        rename(nlaunchupdatefilename, NLAUNCHPATH);
        RESET();
    }
}

//! Launch download mode.
static __attribute__((always_inline)) void launch_download_mode(void) {
    DISPLAY(D);
    #if MODEL==1
    cx_load_function(3);
    #endif
    __asm volatile(
        "LDR    R4, =" M("0x11952E40","0x118D932C") "\n"
    );
    download_mode();
    RESET();
}

//! Update the OS if needed.
static __attribute__((always_inline)) void update_OS(void) {
    uint8_t keypad = *(volatile uint16_t*)0x900E001C;
    keypad &= (1<<7);
    if ((!keypad) ^ MODEL) {
        launch_download_mode();
        __builtin_unreachable();
    }

    FILE * osfile;
    if ((osfile = fopen(osupdatefilename, "r"))) {
        fclose(osfile);
        if ((osfile = fopen(osfilename, "r"))) {
        fclose(osfile);
            if (rename(osfilename, osoldfilename)) {
                DISPLAY(K);
                return;
            }
        }
        rename(osupdatefilename, osfilename);
        do_install_resources = 1;
    }
}

//! Install the OS's resources.
static __attribute__((always_inline)) void install_resources(void) {
    if (do_install_resources) {
        FILE * osfile;
        FILE * nlaunchfile;
        if ( (nlaunchfile = fopen(NLAUNCHPATH, "r")) && (osfile = fopen(osfilename, "r")) ) {
            purge_dir("/phoenix", 0);
            purge_dir("/ti84"   , 0);
            fclose(osfile);
            fclose(nlaunchfile);
        } else {
            DISPLAY(C);
        }

        strcpy(NLAUNCHPATH, osfilename);
        rename(NLAUNCHPATH, TEMPPATH);
        //DISPLAY(X);
        put_byte(M(0x1192C220,0x11ABBA54), 0x09);
        __asm volatile(
            "LDR    R0, =" M("0x11952E6C","0x118D940C") "\n"
            "LDR    R1, =" M("0x1192C2C8","0x11AB9730") "\n"
            "LDR    R9, =" M("0x11952E6C","0x118D940C") "\n"
            "MOV    LR, PC                               \n"
            "LDR    PC, =" M("0x1192C120","0x11ABB96C") "\n"
        );
        //DISPLAY(Y);
        rename(TEMPPATH, NLAUNCHPATH);
        //DISPLAY(Z);
        RESET();
    }
}

//! Load the OS.
static __attribute__((always_inline)) void load_OS(void) {

    uint16_t keypad = *(volatile uint16_t*)0x900E001C;
    keypad &= (1<<9);
    strcpy(NLAUNCHPATH, ((!keypad) ^ MODEL) ? linuxloaderfilename : osfilename);

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
    put_word(0x900B0000, 0x00001002);
    put_word(0x900B000C, 0x00000004);
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
    put_word(0x900B0000, 0x0030A002);
    put_word(0x900B000C, 0x00000004);
    #endif
    if (load_os(1)) {
        DISPLAY(F);
        HANG();
    }
}

//! Purge logs.
static __attribute__((always_inline)) void purge_logs(void) {
    #if PURGE_LOGS
    purge_dir("/logs", 0);
    #endif
}

#include "patch.c"

//! Jump to OS, without return.
static __attribute__((always_inline, noreturn)) void launch_OS(void) {
    __asm volatile(
        "LDR    PC, =0x10000000 \n"
    );
    __builtin_unreachable();
}

int main(void) {

        DISPLAY(1);
    update_nlaunch();
        DISPLAY(2);
    update_OS();
        DISPLAY(3);
    install_resources();
        DISPLAY(4);
    load_OS();
        DISPLAY(5);
    purge_logs();
        DISPLAY(6);
    patch_OS();
        DISPLAY(7);
    launch_OS();
}
