/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2014 Excale
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

#if MODEL==0
static __attribute__((always_inline)) void put_byte(uint32_t absaddr, uint8_t short_in) {
    *((uint8_t  *)absaddr) = short_in;
}
#endif

void main(void) {
    static const char nlaunchupdatefilename[] = "/documents/nlaunch/nlaunch.tns";
    unsigned dummy;
    __asm volatile(
        " .arm \n"
        "0: mrc p15, 0, r15, c7, c10, 3 @ test and clean DCache \n"
        " bne 0b \n"
        " mov %0, #0 \n"
        " mcr p15, 0, %0, c7, c7, 0 @ invalidate ICache and DCache \n"
    : "=r" (dummy));
    *(volatile unsigned*)0x90060C00 = 0x1ACCE551;
    *(volatile unsigned*)0x90060008 = 0;
    *(volatile unsigned*)0x90060C00 = 0;
    
    #if MODEL==0
    put_byte(0x1181FD6B, 0xEA);
    #endif
    DISPLAY(Y);
    mkdir("/phoenix/install/");
    rename(nlaunchupdatefilename, NLAUNCHPATH);
    DISPLAY(Z);
    RESET();
}