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
static __attribute__((always_inline)) void patch_CAS_3_0_1_1753_extra(void)    { }
static __attribute__((always_inline)) void patch_NCAS_3_0_1_1753_extra(void)   { }
static __attribute__((always_inline)) void patch_CAS_3_0_2_1791_extra(void)    { }
static __attribute__((always_inline)) void patch_NCAS_3_0_2_1791_extra(void)   { }
static __attribute__((always_inline)) void patch_CAS_3_1_0_392_extra(void)     {
    #if NDLESS
    write_ndless3x_loader(1,0);
    #endif
}
static __attribute__((always_inline)) void patch_NCAS_3_1_0_392_extra(void)    {
    #if NDLESS
    write_ndless3x_loader(0,0);
    #endif
}
static __attribute__((always_inline)) void patch_CAS_3_2_0_1212_extra(void)    {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_0_1212_extra(void)   {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CAS_3_2_0_1219_extra(void)    {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_0_1219_extra(void)   {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CAS_3_2_3_1233_extra(void)    {
    put_word(0x10000268, NOP);
}
static __attribute__((always_inline)) void patch_NCAS_3_2_3_1233_extra(void)   {
    put_word(0x10000268, NOP);
}
#elif MODEL==1
static __attribute__((always_inline)) void patch_CXCAS_3_0_1_1753_extra(void)  { }
static __attribute__((always_inline)) void patch_CXNCAS_3_0_1_1753_extra(void) { }
static __attribute__((always_inline)) void patch_CXCAS_3_0_2_1791_extra(void)  { }
static __attribute__((always_inline)) void patch_CXNCAS_3_0_2_1791_extra(void) { }
static __attribute__((always_inline)) void patch_CXCAS_3_0_2_1793_extra(void)  { }
static __attribute__((always_inline)) void patch_CXNCAS_3_0_2_1793_extra(void) { }
static __attribute__((always_inline)) void patch_CXCAS_3_1_0_392_extra(void)   {
    #if NDLESS
    write_ndless3x_loader(3,0);
    #endif
}
static __attribute__((always_inline)) void patch_CXNCAS_3_1_0_392_extra(void)  {
    #if NDLESS
    write_ndless3x_loader(2,0);
    #endif
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1212_extra(void)  {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1212_extra(void) {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1219_extra(void)  {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1219_extra(void) {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_3_1233_extra(void)  {
    put_word(0x10000268, NOP);
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_3_1233_extra(void) {
    put_word(0x10000268, NOP);
}

static __attribute__((always_inline)) void patch_CMNCAS_3_1_0_392_extra(void)  { }
static __attribute__((always_inline)) void patch_CMCAS_3_1_0_392_extra(void)   { }
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1212_extra(void) {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1212_extra(void)  {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1219_extra(void) {
    put_word(0x10000258, NOP);
}
static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1219_extra(void)  {
    put_word(0x10000258, NOP);
}

#endif
