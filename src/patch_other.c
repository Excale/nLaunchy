/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2015 Excale
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

#if NDLESS
    #include "ndless.c"
#endif
#if MODEL==0
static __attribute__((always_inline)) void patch_CAS_1_1_9170_extra(void)      { }
static __attribute__((always_inline)) void patch_NCAS_1_1_9253_extra(void)     { }

static __attribute__((always_inline)) void patch_CAS_1_7_2741_extra(void)      { }
static __attribute__((always_inline)) void patch_NCAS_1_7_2741_extra(void)     { }

static __attribute__((always_inline)) void patch_CAS_2_0_1_60_extra(void)      { }
static __attribute__((always_inline)) void patch_NCAS_2_0_1_60_extra(void)     { }

static __attribute__((always_inline)) void patch_CAS_2_1_0_631_extra(void)     { }
static __attribute__((always_inline)) void patch_NCAS_2_1_0_631_extra(void)    { }

static __attribute__((always_inline)) void patch_CAS_3_0_1_1753_extra(void)    {
    put_byte(0x100791A3, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_0_1_1753_extra(void)   {
    put_byte(0x10079243, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_0_2_1791_extra(void)    {
    put_byte(0x100791A3, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_0_2_1791_extra(void)   {
    put_byte(0x10079243, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_1_0_392_extra(void)     {
    #if NDLESS
    write_ndless3x_loader(1, 0);
    #endif
    put_word(0x100B19EC, 0xEAFFFFFE);
}
static __attribute__((always_inline)) void patch_NCAS_3_1_0_392_extra(void)    {
    #if NDLESS
    write_ndless3x_loader(0, 0);
    #endif
    put_word(0x100B172C, 0xEAFFFFFE);
}

static __attribute__((always_inline)) void patch_CAS_3_2_0_1212_extra(void)    {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x10084A63, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_0_1212_extra(void)   {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x10084B13, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_2_0_1219_extra(void)    {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x10084A63, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_0_1219_extra(void)   {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x10084B13, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_2_3_1233_extra(void)    {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x10084E8B, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_3_1233_extra(void)   {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x10084F3B, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_6_0_546_extra(void) {
    #if NDLESS
    write_ndless3x_loader(1, 1);
    #else
    put_word(0x100BEB6C, 0xE12FFF1E);
    #endif
    put_byte(0x1008E157, 0xEA);
    put_word(0x10136418, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_NCAS_3_6_0_546_extra(void) {
    #if NDLESS
    write_ndless3x_loader(0, 1);
    #else
    put_word(0x100BE8B4, 0xE12FFF1E);
    #endif
    put_byte(0x1008E1FB, 0xEA);
    put_word(0x10135DF4, 0xE12FFF1E);
}

static __attribute__((always_inline)) void patch_CAS_3_9_0_46x_extra(void) {
    #if NDLESS
    write_ndless3x_loader(1, 2);
    #else
    put_word(0x100BE598, 0xE12FFF1E);
    #endif
    put_byte(0x1008817B, 0xEA);
    put_word(0x10111584, NOP);
    put_word(0x1013C894, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_NCAS_3_9_0_46x_extra(void) {
    #if NDLESS
    write_ndless3x_loader(0, 2);
    #else
    put_word(0x100BE7D0, 0xE12FFF1E);
    #endif
    put_byte(0x1008870B, 0xEA);
    put_word(0x10111788, NOP);
    put_word(0x1013C764, 0xE12FFF1E);
}

#elif MODEL==1

static __attribute__((always_inline)) void patch_CXCAS_3_0_1_1753_extra(void)  {
    put_byte(0x100788C7, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_0_1_1753_extra(void) {
    put_byte(0x10078937, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_0_2_1791_extra(void)  {
    put_byte(0x100788C7, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_0_2_1791_extra(void) {
    put_byte(0x10078937, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_0_2_1793_extra(void)  {
    put_byte(0x100788CF, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_0_2_1793_extra(void) {
    put_byte(0x1007893F, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_1_0_392_extra(void)   {
    #if NDLESS
    write_ndless3x_loader(1,0);
    #endif
    put_word(0x100B1108, 0xEAFFFFFE);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_1_0_392_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(0,0);
    #endif
    put_word(0x100B0E24, 0xEAFFFFFE);
}

static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1212_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x10084273, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1212_extra(void) {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x100842F3, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1219_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x10084273, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1219_extra(void) {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x100842F3, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_2_3_1233_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x1008469B, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_3_1233_extra(void) {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x1008471B, 0xEA);
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_4_1237_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x1008469B, 0xEA);
}

static __attribute__((always_inline)) void patch_CXNCAS_3_2_4_1237_extra(void) {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x1008471B, 0xEA);
}
static __attribute__((always_inline)) void patch_CXCAS_3_3_0_538_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000268, NOP);
    #endif
    put_byte(0x10085F57, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_6_0_546_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(1, 1);
    #else
    put_word(0x100BE1BC, 0xE12FFF1E);
    #endif
    put_byte(0x1008D7A7, 0xEA);
    put_word(0x10135E8C, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_6_0_546_extra(void) {
    #if NDLESS
    write_ndless3x_loader(0, 1);
    #else
    put_word(0x100BDED4, 0xE12FFF1E);
    #endif
    put_byte(0x1008D81B, 0xEA);
    put_word(0x10135838, 0xE12FFF1E);
}

static __attribute__((always_inline)) void patch_CXCAS_3_9_0_46x_extra(void)  {
    put_word(0x100BDBDC, 0xE12FFF1E);
    put_byte(0x100877BF, 0xEA);
    put_word(0x1013C2F4, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_9_0_46x_extra(void) {
    put_word(0x100BDDE4, 0xE12FFF1E);
    put_byte(0x10087D1F, 0xEA);
    put_word(0x1013C19C, 0xE12FFF1E);
}

static __attribute__((always_inline)) void patch_CXCAS_3_9_1_38_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(1, 2);
    #else
    put_word(0x100BD88C, 0xE12FFF1E);
    #endif
    put_byte(0x1008746F, 0xEA);
    put_word(0x10111778, NOP);
    put_word(0x1013BB08, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_9_1_38_extra(void) {
    #if NDLESS
    write_ndless3x_loader(0, 2);
    #else
    put_word(0x100BDA94, 0xE12FFF1E);
    #endif
    put_byte(0x100879CF, 0xEA);
    put_word(0x1011194C, NOP);
    put_word(0x1013B9B0, 0xE12FFF1E);
}

static __attribute__((always_inline)) void patch_CXCAS_4_0_3_29_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(1, 3);
    #else
    put_word(0x100C2174, 0xE12FFF1E);
    #endif
    put_byte(0x1008B74B, 0xEA);
    put_word(0x10117F7C, NOP);
    put_word(0x10147F50, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_CXNCAS_4_0_3_29_extra(void) {
    #if NDLESS
    write_ndless3x_loader(0, 3);
    #else
    put_word(0x100C235C, 0xE12FFF1E);
    #endif
    put_byte(0x1008BC8F, 0xEA);
    put_word(0x1011812C, NOP);
    put_word(0x10147DD0, 0xE12FFF1E);
}

static __attribute__((always_inline)) void patch_CXCAS_4_2_0_532_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(1, 4);
    #else
    put_word(0x100C5D40, 0xE12FFF1E);
    #endif
    put_byte(0x1008D647, 0xEA);
    put_word(0x1014E1B8, 0xE12FFF1E);
}
static __attribute__((always_inline)) void patch_CXNCAS_4_2_0_532_extra(void) {
    #if NDLESS
    write_ndless3x_loader(0, 4);
    #else
    put_word(0x100C5F24, 0xE12FFF1E);
    #endif
    put_byte(0x1008DB8B, 0xEA);
    put_word(0x1014E008, 0xE12FFF1E);
}

#if 0
static __attribute__((always_inline)) void patch_CMCAS_3_1_0_392_extra(void)   {
    put_byte(0x10076913, 0xEA);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_1_0_392_extra(void)  {
    put_byte(0x10076983, 0xEA);
}

static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1212_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x100801AF, 0xEA);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1212_extra(void) {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x1008022F, 0xEA);
}

static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1219_extra(void)  {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x100801AF, 0xEA);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1219_extra(void) {
    #if OVERCLOCK
    put_word(0x10000258, NOP);
    #endif
    put_byte(0x1008022F, 0xEA);
}
#endif

#endif
