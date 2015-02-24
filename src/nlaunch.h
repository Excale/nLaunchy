/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2015 Excale
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

#ifndef __NLAUNCH_H__
#define __NLAUNCH_H__

#include <stdint.h>

//! Build options: MODEL:[0=CLASSIC,1=CX], DEBUG:[0-2], NDLESS[0,1=Include Ndless Loader], OVERCLOCK[0,1=Overclock some OSes], PURGE_LOGS[0,1=Purge logs]
/** Set in Makefile
#define MODEL  0 */
#define DEBUG  2
#define MULTIOS 0
#define NDLESS 1
#define OVERCLOCK 0
#define PURGE_LOGS 1
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

#define RESET() hw_reset(); \
                __builtin_unreachable();
#define HANG()  while(1) {} \
                __builtin_unreachable();

typedef void FILE;

//! temp OS path
#define TEMPPATH    (char *)M(0x11952E6C,0x118D940C)
//! nLaunch path
#define NLAUNCHPATH (char *)M(0x11953920,0x118D9DA4)
//! file pointer
#define FILEPOINTER (FILE *)M(0x11A6D4A8,0x11BFFCC0)

#include "boot2.h"


#endif
