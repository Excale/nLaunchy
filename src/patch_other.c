/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013 nLaunch CX guy
 * Copyright (C) 2013 Excale
 * Copyright (C) 2013 Lionel Debroux
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
    write_ndless3x_loader(1,0);
    #endif
    put_word(0x100B19EC, 0xEAFFFFFE);
}
static __attribute__((always_inline)) void patch_NCAS_3_1_0_392_extra(void)    {
    #if NDLESS
    write_ndless3x_loader(0,0);
    #endif
    put_word(0x100B172C, 0xEAFFFFFE);
}

static __attribute__((always_inline)) void patch_CAS_3_2_0_1212_extra(void)    {
    put_word(0x10000258, NOP);
    put_byte(0x10084A63, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_0_1212_extra(void)   {
    put_word(0x10000258, NOP);
    put_byte(0x10084B13, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_2_0_1219_extra(void)    {
    put_word(0x10000258, NOP);
    put_byte(0x10084A63, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_0_1219_extra(void)   {
    put_word(0x10000258, NOP);
    put_byte(0x10084B13, 0xEA);
}

static __attribute__((always_inline)) void patch_CAS_3_2_3_1233_extra(void)    {
    put_word(0x10000268, NOP);
    put_byte(0x10084E8B, 0xEA);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_3_1233_extra(void)   {
    put_word(0x10000268, NOP);
    put_byte(0x10084F3B, 0xEA);
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
    write_ndless3x_loader(3,0);
    #endif
    put_word(0x100B1108, 0xEAFFFFFE);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_1_0_392_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(2,0);
    #endif
    put_word(0x100B0E24, 0xEAFFFFFE);
}

static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1212_extra(void)  {
    put_word(0x10000258, NOP);
    put_byte(0x10084273, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1212_extra(void) {
    put_word(0x10000258, NOP);
    put_byte(0x100842F3, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1219_extra(void)  {
    put_word(0x10000258, NOP);
    put_byte(0x10084273, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1219_extra(void) {
    put_word(0x10000258, NOP);
    put_byte(0x100842F3, 0xEA);
}

static __attribute__((always_inline)) void patch_CXCAS_3_2_3_1233_extra(void)  {
    put_word(0x10000268, NOP);
    put_byte(0x1008469B, 0xEA);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_3_1233_extra(void) {
    put_word(0x10000268, NOP);
    put_byte(0x1008471B, 0xEA);
}

static __attribute__((always_inline)) void patch_CMCAS_3_1_0_392_extra(void)   {
    put_byte(0x10076913, 0xEA);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_1_0_392_extra(void)  {
    put_byte(0x10076983, 0xEA);
}

static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1212_extra(void)  {
    put_word(0x10000258, NOP);
    put_byte(0x100801AF, 0xEA);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1212_extra(void) {
    put_word(0x10000258, NOP);
    put_byte(0x1008022F, 0xEA);
}

static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1219_extra(void)  {
    put_word(0x10000258, NOP);
    put_byte(0x100801AF, 0xEA);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1219_extra(void) {
    put_word(0x10000258, NOP);
    put_byte(0x1008022F, 0xEA);
}

#endif
