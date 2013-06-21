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

//! Build options: MODEL:[0=CLASSIC,1=CX], DEBUG:[0-2], NDLESS[0,1=Include Ndless Loader]
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

//! temp OS path from boot2
#define TEMPPATH    (char *)M(0x11952E6C,0x118D940C)
//! nLaunch path
#define NLAUNCHPATH (char *)M(0x11953920,0x118D9DA4)
//! file pointer from boot2
#define FILEPOINTER (void *)M(0x11A6D4A8,0x11BFFCC0)

typedef void FILE;


#endif