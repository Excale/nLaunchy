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

#include "nlaunch.h"

void main(void) {
    asm volatile(
        "LDR    R0, =0x119004F8       \n\t"
        "LDR    R1, =0x13E00C1E       \n\t"
        "STR    R1, [R0]              \n\t"
        "MCR    p15, 0, r0, c8, c7, 0 \n\t"
        "LDR    PC, =0x13ECFA74       \n\t"
    );
    struct _stat path_stat;
    const char *path = "/phoenix/install/nlaunch.tns";
    #if DEBUG
    display_msg_to_screen(u"A",0,0);
    #endif
    *(volatile unsigned*)0x90060C00 = 0x1ACCE551;
    *(volatile unsigned*)0x90060008 = 0;
    *(volatile unsigned*)0x90060C00 = 0;

    unsigned dummy;
    __asm volatile(
        " .arm \n"
        "0: mrc p15, 0, r15, c7, c10, 3 @ test and clean DCache \n"
        " bne 0b \n"
        " mov %0, #0 \n"
        " mcr p15, 0, %0, c7, c7, 0 @ invalidate ICache and DCache \n"
    : "=r" (dummy));

    fclose((void *)0x11BFFCC0);
    rename((char *)0x118D940C, (char *)0x118D9DA4);
    rename("/documents/nlaunch/nlaunch.tns", path);

    #if DEBUG
    display_msg_to_screen(u"B",0,0);
    #endif

    FILE * res_file;
    res_file=fopen(path, "rb");
    stat(path, &path_stat);
    char *core = malloc(path_stat.st_size);
    fread(core, path_stat.st_size, 1, res_file);
    fclose(res_file);
    #if DEBUG
    display_msg_to_screen(u"C",0,0);
    #endif
    ((void (*)(void))(char*)core)();
    __builtin_unreachable();
}
