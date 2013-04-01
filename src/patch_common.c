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

#if MODEL==0
static __attribute__((always_inline)) void patch_CAS_1_1_9170_common(void) {
    write_osfilename(0x1043C1DC); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_1_1_9253_common(void) {
    write_osfilename(0x103FA604); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_1_7_2741_common(void) {
    write_osfilename(0x10626158); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_1_7_2741_common(void) {
    write_osfilename(0x105EEFB8); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_2_0_1_60_common(void) {
    write_osfilename(0x10680F7C); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_2_0_1_60_common(void) {
    write_osfilename(0x10649F08); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_2_1_0_631_common(void) {
    write_osfilename(0x10690D90); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_2_1_0_631_common(void) {
    write_osfilename(0x10659AD8); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_3_0_1_1753_common(void) {
    write_osfilename(0x10835258); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_3_0_1_1753_common(void) {
    write_osfilename(0x107F6858); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_3_0_2_1791_common(void) {
    write_osfilename(0x10834A70); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_3_0_2_1791_common(void) {
    write_osfilename(0x107F5238); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_3_1_0_392_common(void) {
    write_osfilename(0x10865194); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_3_1_0_392_common(void) {
    write_osfilename(0x10825134); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_3_2_0_1212_common(void) {
    write_osfilename(0x1093EAE4); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_3_2_0_1212_common(void) {
    write_osfilename(0x108FD628); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_3_2_0_1219_common(void) {
    write_osfilename(0x1093EB94); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_3_2_0_1219_common(void) {
    write_osfilename(0x108FD6D8); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_CAS_3_2_3_1233_common(void) {
    write_osfilename(0x1093F178); // Change OS filename to load resources correctly
}

static __attribute__((always_inline)) void patch_NCAS_3_2_3_1233_common(void) {
    write_osfilename(0x108FDCA8); // Change OS filename to load resources correctly
}
#elif MODEL==1
static __attribute__((always_inline)) void patch_CXCAS_3_0_1_1753_common(void) {
    write_osfilename(0x108324D8); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_0_1_1753_common(void) {
    write_osfilename(0x107D76E0); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXCAS_3_0_2_1791_common(void) {
    write_osfilename(0x10831D08); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_0_2_1791_common(void) {
    write_osfilename(0x107D60D0); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXCAS_3_0_2_1793_common(void) {
    write_osfilename(0x10831D18); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_0_2_1793_common(void) {
    write_osfilename(0x107D60E0); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXCAS_3_1_0_392_common(void) {
    write_osfilename(0x10862428); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_1_0_392_common(void) {
    write_osfilename(0x10806120); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1212_common(void) {
    write_osfilename(0x1093C40C); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1212_common(void) {
    write_osfilename(0x108DECE4); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_0_1219_common(void) {
    write_osfilename(0x1093C4BC); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_0_1219_common(void) {
    write_osfilename(0x108DED94); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXCAS_3_2_3_1233_common(void) {
    write_osfilename(0x1093CAA0); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CXNCAS_3_2_3_1233_common(void) {
    write_osfilename(0x108DF368); // Change OS filename to load resources correctly
}


static __attribute__((always_inline)) void patch_CMNCAS_3_1_0_392_common(void) {
	write_osfilename(0x108002F8); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CMCAS_3_1_0_392_common(void) {
	write_osfilename(0x1085C600); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1212_common(void) {
	write_osfilename(0x108DDAF8); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1212_common(void) {
	write_osfilename(0x1093B220); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CMNCAS_3_2_0_1219_common(void) {
	write_osfilename(0x108DDBA8); // Change OS filename to load resources correctly
}
static __attribute__((always_inline)) void patch_CMCAS_3_2_0_1219_common(void) {
	write_osfilename(0x1093B2D0); // Change OS filename to load resources correctly
}
#endif
