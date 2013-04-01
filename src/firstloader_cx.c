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

//! HW_reset from boot2
#define boot2_HW_reset ((void(*)(void))0x118C62BC)
//! mkdir from boot2
#define mkdir    ((int (*)(const char *))0x11A5772C)
//! rename from boot2
#define rename   ((int (*)(const char *, const char *))0x11A58A60)
//! display_msg_to_screen from boot2
#define display_msg_to_screen   ((void(*)(short unsigned int *, uint32_t, uint32_t))0x1187F9F8)

void main(void) {
    const char *preloader_path = "/documents/nlaunch/preloader.tns";
    display_msg_to_screen(u"Y",0,0);
    *(volatile unsigned*)0x90060C00 = 0x1ACCE551;
    *(volatile unsigned*)0x90060008 = 0;
    *(volatile unsigned*)0x90060C00 = 0;
    mkdir("/phoenix/install/");
    rename(preloader_path, (char *)0x118D9DA4);
    display_msg_to_screen(u"Z",0,0);
    boot2_HW_reset();
    __builtin_unreachable();
}