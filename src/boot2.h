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
 
#ifndef  __BOOT2_H__
#define  __BOOT2_H__

//! Build options: MODEL:[0=CLASSIC,1=CX]
/** Set in Makefile
#define MODEL  0 */

#if MODEL==0
  #define M(x,y) x
#elif MODEL==1
  #define M(x,y) y
#endif

//! cx_load_function      from boot2
#define cx_load_function      ((int (*)(uint32_t))M(,0x1187EEE0))
//! display_msg_to_screen from boot2
#define display_msg_to_screen ((void (*)(M(const char *, short unsigned int *), uint32_t, uint32_t))M(0x11801C94,0x1187F9F8))
//! download_mode         from boot2
#define download_mode         ((void (*)(void))M(0x118012BC,0x1187E280))
//! fopen    from boot2
#define fopen    ((void *(*)(const char *, const char *))M(0x11856590,0x118AB7B8))
//! fseek    from boot2
#define fseek    ((void *(*)(void *, long int, int))M(0x11856808,0x118ABA98))
//! fclose   from boot2
#define fclose   ((int (*)(void *))M(0x1185634C,0x118AB53C))
//! fread    from boot2
#define fread    ((unsigned int (*)(void *, unsigned int, unsigned int, FILE *))M(0x118566CC,0x118AB8A4))
//! HW_reset from boot2
#define hw_reset ((void(*)(void))M(0x11831008,0x118C62BC))
//! load_os  from boot2
#define load_os  ((int (*)(uint32_t))M(0x11802B10,0x11AB7810))
//! malloc   from boot2
#define malloc   ((void *(*)(unsigned int))M(0x11854E9C,0x118A9A34))
//! mkdir    from boot2
#define mkdir    ((int (*)(const char *))M(0x118589F8,0x11A5772C))
//! purge_files from boot2
#define purge_files       ((void(*)(const char *, int))M(0x1192ACF4,0x11AB994C))
//! rename   from boot2
#define rename   ((int (*)(const char *, const char *))M(0x11859D08,0x11A58A60))
//! stat     from boot2
#define stat     ((int (*)(const char *, void *))M(0x11859F5C,0x11A58CAC))
//! strcpy   from boot2
#define strcpy   ((int (*)(char *, const char *))M(0x11857A44,0x118AC2A0))
//! unlink   from boot2
#define unlink   ((int (*)(const char *))M(0x1185A238,0x11A58F88))

#endif