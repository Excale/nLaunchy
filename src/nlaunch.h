/*
 * nLaunchy
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
 
#ifndef NLAUNCH_H
#define NLAUNCH_H

#include <stdint.h>
#include "boot2.h"

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

/**
 * \brief The hex value of a NOP instruction.
 * \note E1A00000 is usually used for NOP, but we use 00000000 to work around compiler weirdness.
 */
#define NOP 0x00000000

//! OS path from boot2
#define OSPATH   M(0x11953920,0x118D9DA4)
//! temp OS path from boot2
#define TEMPPATH M(0x11952E6C,0x118D940C)
//! nLaunch path
#define NLAUNCHPATH M(OSPATH,"/phoenix/install/nlaunch.tns")

typedef void FILE;
struct _stat {
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


#endif