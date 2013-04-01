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

#define DEBUG 1

typedef void FILE;
struct stat {
    unsigned short st_dev;
    unsigned int   st_ino;
    unsigned int   st_mode;
    unsigned short st_nlink;
    unsigned short st_uid;
    unsigned short st_gid;
    unsigned short st_rdev;
    unsigned int   st_size;
    unsigned int   st_atime;
    unsigned int   st_mtime;
    unsigned int   st_ctime;
};
//! fopen from boot2
#define fopen    ((void *(*)(const char *, const char *))0x118AB7B8)
//! stat from boot2
#define _stat    ((int(*)(const char *, void *))0x11A58CAC)
//! malloc from boot2
#define malloc   ((void *(*)(unsigned int))0x118A9A34)
//! fread from boot2
#define fread    ((unsigned int(*)(void *, unsigned int, unsigned int, FILE *))0x118AB8A4)
//! fclose from boot2
#define fclose   ((int (*)(void *))0x118AB53C)
//! rename from boot2
#define rename   ((int (*)(const char *, const char *))0x11A58A60)
//! display_msg_to_screen from boot2
#define display_msg_to_screen   ((void(*)(short unsigned int *, uint32_t, uint32_t))0x1187F9F8)

void main(void) {
    asm volatile(
        "LDR    R0, =0x119004F8       \n\t"
        "LDR    R1, =0x13E00C1E       \n\t"
        "STR    R1, [R0]              \n\t"
        "MCR    p15, 0, r0, c8, c7, 0 \n\t"
        "LDR    PC, =0x13ECFA74       \n\t"
    );
    struct stat path_stat;
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
    _stat(path, &path_stat);
    char *core = malloc(path_stat.st_size);
    fread(core, path_stat.st_size, 1, res_file);
    fclose(res_file);
    #if DEBUG
    display_msg_to_screen(u"C",0,0);
    #endif
    ((void (*)(void))(char*)core)();
    __builtin_unreachable();
}
