/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2015 Excale
 * Copyright (C) 2013-2015 Lionel Debroux
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

#include "patch_other.c"

//! Write new OS filename to the given address.
static __attribute__((always_inline)) void write_osfilename(char * dest) {
    unsigned int i;
    const char * src  = osfilename;
    for (i = 0; i < sizeof(osfilename); i++) {
        *dest++ = *src++;
    }
}

//! Patch the OS.
static __attribute__((always_inline)) void patch_OS(void) {
    uint32_t addr;
    switch (*((volatile uint32_t *)0x10000020)) {
#if MODEL==0
        case 0x1014A9F0:    // TI-NspireCAS-1.1.9170
            patch_CAS_1_1_9170_extra();
            addr = 0x1043C1DC;
        break;
        case 0x1014A9C0:    // TI-Nspire-1.1.9253
            patch_NCAS_1_1_9253_extra();
            addr = 0x103FA604;
        break;
        case 0x10211290:    // TI-Nspire-1.7.2741
            patch_NCAS_1_7_2741_extra();
            addr = 0x105EEFB8;
        break;
        case 0x102132A0:    // TI-NspireCAS-1.7.2741
            patch_CAS_1_7_2741_extra();
            addr = 0x10626158;
        break;
        case 0x10266030:    // TI-Nspire-2.0.1.60
            patch_NCAS_2_0_1_60_extra();
            addr = 0x10649F08;
        break;
        case 0x10266900:    // TI-NspireCAS-2.0.1.60
            patch_CAS_2_0_1_60_extra();
            addr = 0x10680F7C;
        break;
        case 0x10279D70:    // TI-Nspire-2.1.0.631
            patch_NCAS_2_1_0_631_extra();
            addr = 0x10659AD8;
        break;
        case 0x1027A640:    // TI-NspireCAS-2.1.0.631
            patch_CAS_2_1_0_631_extra();
            addr = 0x10690D90;
        break;
        case 0x102ED240:    // TI-Nspire-3.0.1.1753
            patch_NCAS_3_0_1_1753_extra();
            addr = 0x107F6858;
        break;
        case 0x102ED960:    // TI-NspireCAS-3.0.1.1753
            patch_CAS_3_0_1_1753_extra();
            addr = 0x10835258;
        break;
        case 0x102ED6D0:    // TI-Nspire-3.0.2.1791
            patch_NCAS_3_0_2_1791_extra();
            addr = 0x107F5238;
        break;
        case 0x102EDDF0:    // TI-NspireCAS-3.0.2.1791
            patch_CAS_3_0_2_1791_extra();
            addr = 0x10834A70;
        break;
        case 0x102F0FA0:    // TI-Nspire-3.1.0.392
            patch_NCAS_3_1_0_392_extra();
            addr = 0x10825134;
        break;
        case 0x102F16D0:    // TI-NspireCAS-3.1.0.392
            patch_CAS_3_1_0_392_extra();
            addr = 0x10865194;
        break;
        case 0x10341CF0:    // TI-NspireCAS-3.2.0.1212
            patch_NCAS_3_2_0_1212_extra();
            addr = 0x108FD628;
        break;
        case 0x103413D0:    // TI-Nspire-3.2.0.1212
            patch_CAS_3_2_0_1212_extra();
            addr = 0x1093EAE4;
        break;
        case 0x10341480:    // TI-Nspire-3.2.0.1219
            patch_NCAS_3_2_0_1219_extra();
            addr = 0x108FD6D8;
        break;
        case 0x10341DA0:    // TI-NspireCAS-3.2.0.1219
            patch_CAS_3_2_0_1219_extra();
            addr = 0x1093EB94;
        break;
        case 0x10341990:    // TI-Nspire-3.2.3.1233
            patch_NCAS_3_2_3_1233_extra();
            addr = 0x108FDCA8;
        break;
        case 0x103422B0:    // TI-NspireCAS-3.2.3.1233
            patch_CAS_3_2_3_1233_extra();
            addr = 0x1093F178;
        break;
        case 0x10375BB0:    // TI-Nspire-3.6.0.546
            patch_NCAS_3_6_0_546_extra();
            addr = 0x109B9D18;
        break;
        case 0x103765F0:    // TI-NspireCAS-3.6.0.546
            patch_CAS_3_6_0_546_extra();
            addr = 0x109FE684;
        break;
        case 0x1037CDE0:    // TI-Nspire-3.9.0.461
                            // TI-Nspire-3.9.0.463
            patch_NCAS_3_9_0_46x_extra();
            addr = 0x109C6A04;
        break;
        case 0x1037D320:    // TI-NspireCAS-3.9.0.461
                            // TI-NspireCAS-3.9.0.463
            patch_CAS_3_9_0_46x_extra();
            addr = 0x10A0ADD8;
        break;
        case 0x10166DC0:    // TI-NspireCAS-1.1.6925
        case 0x10138FD0:    // TI-Nspire-1.1.7320
        case 0x101476D0:    // TI-Nspire-1.1.8008
        case 0x101494D0:    // TI-NspireCAS-1.1.8408
        case 0x10149470:    // TI-Nspire-1.1.8410
        case 0x1014A9A0:    // TI-Nspire-1.1.9227
        case 0x101934C0:    // TI-NspireCAS-1.2.2344
        case 0x10193530:    // TI-NspireCAS-1.2.2394
        case 0x101919A0:    // TI-Nspire-1.2.2398
        case 0x101A2760:    // TI-NspireCAS-1.3.2406
                            // TI-NspireCAS-1.3.2437
            // Warning: these two OS versions have the same reset vector !
        case 0x101A0C30:    // TI-Nspire-1.3.2407
        case 0x10362CB0:    // TI-NspireCAS-1.4.11643
        case 0x103141A0:    // TI-Nspire-1.4.11653
        case 0x10205E90:    // TI-NspireCAS-1.6.4295
        case 0x10203EA0:    // TI-Nspire-1.6.4379
        case 0x1021A490:    // TI-Nspire-1.7.1.50
        case 0x1021C4A0:    // TI-NspireCAS-1.7.1.50
        case 0x1021C490:    // TI-NspireCAS-1.7.2.59
        case 0x1024FF00:    // TI-Nspire-2.0.1188
        case 0x102507D0:    // TI-NspireCAS-2.0.1188
        case 0x1027ACF0:    // TI-Nspire-2.1.1.38
        case 0x1027B620:    // TI-NspireCAS-2.1.1.38
#elif MODEL==1
        case 0x102ECCD0:    // TI-NspireCX-3.0.1.1753
            patch_CXNCAS_3_0_1_1753_extra();
            addr = 0x107D76E0;
        break;
        case 0x102ED420:    // TI-NspireCXCAS-3.0.1.1753
            patch_CXCAS_3_0_1_1753_extra();
            addr = 0x108324D8;
        break;
        case 0x102ED170:    // TI-NspireCX-3.0.2.1791
                            // TI-NspireCX-3.0.2.1793
            // Warning: these two OS versions have the same reset vector !
            if (*((volatile uint32_t *)0x107D60D0) == 0x6F68702F) {
                patch_CXNCAS_3_0_2_1791_extra();
                addr = 0x107D60D0;
            } else {
                patch_CXNCAS_3_0_2_1793_extra();
                addr = 0x107D60E0;
            }
        break;
        case 0x102ED8C0:    // TI-NspireCXCAS-3.0.2.1791
                            // TI-NspireCXCAS-3.0.2.1793
            // Warning: these two OS versions have the same reset vector !
            if (*((volatile uint32_t *)0x10831D08) == 0x6F68702F) {
                patch_CXCAS_3_0_2_1791_extra();
                addr = 0x10831D08;
            } else {
                patch_CXCAS_3_0_2_1793_extra();
                addr = 0x10831D18;
            }
        break;
        case 0x102F0A10:    // TI-NspireCX-3.1.0.392
            patch_CXNCAS_3_1_0_392_extra();
            addr = 0x10806120;
        break;
        case 0x102F11A0:    // TI-NspireCXCAS-3.1.0.392
            patch_CXCAS_3_1_0_392_extra();
            addr = 0x10862428;
        break;
        case 0x10340F30:    // TI-NspireCX-3.2.0.1212
            patch_CXNCAS_3_2_0_1212_extra();
            addr = 0x108DECE4;
        break;
        case 0x10341880:    // TI-NspireCXCAS-3.2.0.1212
            patch_CXCAS_3_2_0_1212_extra();
            addr = 0x1093C40C;
        break;
        case 0x10340FE0:    // TI-NspireCX-3.2.0.1219
            patch_CXNCAS_3_2_0_1219_extra();
            addr = 0x108DED94;
        break;
        case 0x10341930:    // TI-NspireCXCAS-3.2.0.1219
            patch_CXCAS_3_2_0_1219_extra();
            addr = 0x1093C4BC;
        break;
        case 0x103414F0:    // TI-NspireCX-3.2.3.1233
                            // TI-NspireCX-3.2.4.1237
            // Warning: these two OS versions have the same reset vector !
            if (*((uint32_t *)0x108DF348) == 0x37333231) {
                patch_CXNCAS_3_2_3_1233_extra();
            }
            else {
                patch_CXNCAS_3_2_4_1237_extra();
            }
            addr = 0x108DF368;
        break;
        case 0x10341E40:    // TI-NspireCXCAS-3.2.3.1233
            patch_CXCAS_3_2_3_1233_extra();
            addr = 0x1093CAA0;
        break;
        case 0x10341E30:    // TI-NspireCXCAS-3.2.4.1237
            patch_CXCAS_3_2_4_1237_extra();
            addr = 0x1093CA90;
        break;
        case 0x103454A0:    // TI-NspireCXCAS-3.3.0.538
            patch_CXCAS_3_3_0_538_extra();
            addr = 0x1095CEB0;
        break;
        case 0x10375620:    // TI-NspireCX-3.6.0.546
            patch_CXNCAS_3_6_0_546_extra();
            addr = 0x1099B504;
        break;
        case 0x10376090:    // TI-NspireCXCAS-3.6.0.546
            patch_CXCAS_3_6_0_546_extra();
            addr = 0x109FC0E0;
        break;
        case 0x1037C760:    // TI-NspireCX-3.9.0.461
                            // TI-NspireCX-3.9.0.463
            patch_CXNCAS_3_9_0_46x_extra();
            addr = 0x109A9604;
        break;
        case 0x1037CCC0:    // TI-NspireCXCAS-3.9.0.461
                            // TI-NspireCXCAS-3.9.0.463
            patch_CXCAS_3_9_0_46x_extra();
            addr = 0x10A0A084;
        break;
        case 0x1037D160:    // TI-NspireCX-3.9.1.38
            patch_CXNCAS_3_9_1_38_extra();
            addr = 0x109A9F8C;
        break;
        case 0x1037D6C0:    // TI-NspireCXCAS-3.9.1.38
            patch_CXCAS_3_9_1_38_extra();
            addr = 0x10A0AA0C;
        break;
        case 0x1038C290:    // TI-NspireCX-4.0.3.29
            patch_CXNCAS_4_0_3_29_extra();
            addr = 0x109BE978;
        break;
        case 0x1038C7D0:    // TI-NspireCXCAS-4.0.3.29
            patch_CXCAS_4_0_3_29_extra();
            addr = 0x10A209E4;
        break;

#if 0
        case 0x102DBF20:    // TI-NspireCM-3.1.0.392
            patch_CMNCAS_3_1_0_392_extra();
            addr = 0x108002F8;
        break;
        case 0x102DC6B0:    // TI-NspireCMCAS-3.1.0.392
            patch_CMCAS_3_1_0_392_extra();
            addr = 0x1085C600;
        break;
        case 0x1033C360:    // TI-NspireCM-3.2.0.1212
            patch_CMNCAS_3_2_0_1212_extra();
            addr = 0x108DDAF8;
        break;
        case 0x1033CCB0:    // TI-NspireCMCAS-3.2.0.1212
            patch_CMCAS_3_2_0_1212_extra();
            addr = 0x1093B220;
        break;
        case 0x1033C410:    // TI-NspireCM-3.2.0.1219
            patch_CMNCAS_3_2_0_1219_extra();
            addr = 0x108DDBA8;
        break;
        case 0x1033CD60:    // TI-NspireCMCAS-3.2.0.1219
            patch_CMCAS_3_2_0_1219_extra();
            addr = 0x1093B2D0;
        break;
#endif
#endif
        default:
            // Unknown / unimplemented OS version, don't patch it !
            DISPLAY(U);
            return;
    }
    write_osfilename((char *)addr);
}
