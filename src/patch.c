/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2014 Excale
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

#include "patch_common.c"
#include "patch_other.c"

//! Patch the OS.
static __attribute__((always_inline)) void patch_OS(void) {
    switch (*((volatile uint32_t *)0x10000020)) {
#if MODEL==0
        case 0x1014A9F0:    // TI-NspireCAS-1.1.9170/phoenix.raw
            patch_CAS_1_1_9170_extra();
            patch_CAS_1_1_9170_common();
        break;
        case 0x1014A9C0:    // TI-Nspire-1.1.9253/phoenix.raw
            patch_NCAS_1_1_9253_extra();
            patch_NCAS_1_1_9253_common();
        break;
        case 0x10211290:    // TI-Nspire-1.7.2741/phoenix.raw
            patch_NCAS_1_7_2741_extra();
            patch_NCAS_1_7_2741_common();
        break;
        case 0x102132A0:    // TI-NspireCAS-1.7.2741/phoenix.raw
            patch_CAS_1_7_2741_extra();
            patch_CAS_1_7_2741_common();
        break;
        case 0x10266030:    // TI-Nspire-2.0.1.60/phoenix.raw
            patch_NCAS_2_0_1_60_extra();
            patch_NCAS_2_0_1_60_common();
        break;
        case 0x10266900:    // TI-NspireCAS-2.0.1.60/phoenix.raw
            patch_CAS_2_0_1_60_extra();
            patch_CAS_2_0_1_60_common();
        break;
        case 0x10279D70:    // TI-Nspire-2.1.0.631/phoenix.raw
            patch_NCAS_2_1_0_631_extra();
            patch_NCAS_2_1_0_631_common();
        break;
        case 0x1027A640:    // TI-NspireCAS-2.1.0.631/phoenix.raw
            patch_CAS_2_1_0_631_extra();
            patch_CAS_2_1_0_631_common();
        break;
        case 0x102ED240:    // TI-Nspire-3.0.1.1753/phoenix.raw
            patch_NCAS_3_0_1_1753_extra();
            patch_NCAS_3_0_1_1753_common();
        break;
        case 0x102ED960:    // TI-NspireCAS-3.0.1.1753/phoenix.raw
            patch_CAS_3_0_1_1753_extra();
            patch_CAS_3_0_1_1753_common();
        break;
        case 0x102ED6D0:    // TI-Nspire-3.0.2.1791/phoenix.raw
            patch_NCAS_3_0_2_1791_extra();
            patch_NCAS_3_0_2_1791_common();
        break;
        case 0x102EDDF0:    // TI-NspireCAS-3.0.2.1791/phoenix.raw
            patch_CAS_3_0_2_1791_extra();
            patch_CAS_3_0_2_1791_common();
        break;
        case 0x102F0FA0:    // TI-Nspire-3.1.0.392/phoenix.raw
            patch_NCAS_3_1_0_392_extra();
            patch_NCAS_3_1_0_392_common();
        break;
        case 0x102F16D0:    // TI-NspireCAS-3.1.0.392/phoenix.raw
            patch_CAS_3_1_0_392_extra();
            patch_CAS_3_1_0_392_common();
        break;
        case 0x103413D0:    // TI-Nspire-3.2.0.1212/phoenix.raw
            patch_CAS_3_2_0_1212_extra();
            patch_CAS_3_2_0_1212_common();
        break;
        case 0x10341CF0:    // TI-NspireCAS-3.2.0.1212/phoenix.raw
            patch_NCAS_3_2_0_1212_extra();
            patch_NCAS_3_2_0_1212_common();
        break;
        case 0x10341480:    // TI-Nspire-3.2.0.1219/phoenix.raw
            patch_NCAS_3_2_0_1219_extra();
            patch_NCAS_3_2_0_1219_common();
        break;
        case 0x10341DA0:    // TI-NspireCAS-3.2.0.1219/phoenix.raw
            patch_CAS_3_2_0_1219_extra();
            patch_CAS_3_2_0_1219_common();
        break;
        case 0x10341990:    // TI-Nspire-3.2.3.1233/phoenix.raw
            patch_NCAS_3_2_3_1233_extra();
            patch_NCAS_3_2_3_1233_common();
        break;
        case 0x103422B0:    // TI-NspireCAS-3.2.3.1233/phoenix.raw
            patch_CAS_3_2_3_1233_extra();
            patch_CAS_3_2_3_1233_common();
        break;
        case 0x10375BB0:    // TI-Nspire-3.6.0.546/phoenix.raw
            patch_NCAS_3_6_0_546_extra();
            patch_NCAS_3_6_0_546_common();
        break;
        case 0x103765F0:    // TI-NspireCAS-3.6.0.546/phoenix.raw
            patch_CAS_3_6_0_546_extra();
            patch_CAS_3_6_0_546_common();
        break;
        case 0x10166DC0:    // TI-NspireCAS-1.1.6925/phoenix.raw
        case 0x10138FD0:    // TI-Nspire-1.1.7320/phoenix.raw
        case 0x101476D0:    // TI-Nspire-1.1.8008/phoenix.raw
        case 0x101494D0:    // TI-NspireCAS-1.1.8408/phoenix.raw
        case 0x10149470:    // TI-Nspire-1.1.8410/phoenix.raw
        case 0x1014A9A0:    // TI-Nspire-1.1.9227/phoenix.raw
        case 0x101934C0:    // TI-NspireCAS-1.2.2344/phoenix.raw
        case 0x10193530:    // TI-NspireCAS-1.2.2394/phoenix.raw
        case 0x101919A0:    // TI-Nspire-1.2.2398/phoenix.raw
        case 0x101A2760:    // TI-NspireCAS-1.3.2406/phoenix.raw
                            // TI-NspireCAS-1.3.2437/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
        case 0x101A0C30:    // TI-Nspire-1.3.2407/phoenix.raw
        case 0x10362CB0:    // TI-NspireCAS-1.4.11643/phoenix.raw
        case 0x103141A0:    // TI-Nspire-1.4.11653/phoenix.raw
        case 0x10205E90:    // TI-NspireCAS-1.6.4295/phoenix.raw
        case 0x10203EA0:    // TI-Nspire-1.6.4379/phoenix.raw
        case 0x1021A490:    // TI-Nspire-1.7.1.50/phoenix.raw
        case 0x1021C4A0:    // TI-NspireCAS-1.7.1.50/phoenix.raw
        case 0x1021C490:    // TI-NspireCAS-1.7.2.59/phoenix.raw
        case 0x1024FF00:    // TI-Nspire-2.0.1188/phoenix.raw
        case 0x102507D0:    // TI-NspireCAS-2.0.1188/phoenix.raw
        case 0x1027ACF0:    // TI-Nspire-2.1.1.38/phoenix.raw
        case 0x1027B620:    // TI-NspireCAS-2.1.1.38/phoenix.raw
#elif MODEL==1
        case 0x102ECCD0:    // TI-NspireCX-3.0.1.1753/phoenix.raw
            patch_CXNCAS_3_0_1_1753_common();
            patch_CXNCAS_3_0_1_1753_extra();
        break;
        case 0x102ED420:    // TI-NspireCXCAS-3.0.1.1753/phoenix.raw
            patch_CXCAS_3_0_1_1753_common();
            patch_CXCAS_3_0_1_1753_extra();
        break;
        case 0x102ED170:    // TI-NspireCX-3.0.2.1791/phoenix.raw
                            // TI-NspireCX-3.0.2.1793/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
            if (*((uint32_t *)0x107D60D0) == 0x6F68702F) {
                patch_CXNCAS_3_0_2_1791_common();
                patch_CXNCAS_3_0_2_1791_extra();
            } else {
                patch_CXNCAS_3_0_2_1793_common();
                patch_CXNCAS_3_0_2_1793_extra();
            }
        break;
        case 0x102ED8C0:    // TI-NspireCXCAS-3.0.2.1791/phoenix.raw
                            // TI-NspireCXCAS-3.0.2.1793/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
            if (*((uint32_t *)0x10831D08) == 0x6F68702F) {
                patch_CXCAS_3_0_2_1791_common();
                patch_CXCAS_3_0_2_1791_extra();
            } else {
                patch_CXCAS_3_0_2_1793_common();
                patch_CXCAS_3_0_2_1793_extra();
            }
        break;
        case 0x102F0A10:    // TI-NspireCX-3.1.0.392/phoenix.raw
            patch_CXNCAS_3_1_0_392_common();
            patch_CXNCAS_3_1_0_392_extra();
        break;
        case 0x102F11A0:    // TI-NspireCXCAS-3.1.0.392/phoenix.raw
            patch_CXCAS_3_1_0_392_extra();
            patch_CXCAS_3_1_0_392_common();
        break;
        case 0x10340F30:    // TI-NspireCX-3.2.0.1212/phoenix.raw
            patch_CXNCAS_3_2_0_1212_extra();
            patch_CXNCAS_3_2_0_1212_common();
        break;
        case 0x10341880:    // TI-NspireCXCAS-3.2.0.1212/phoenix.raw
            patch_CXCAS_3_2_0_1212_extra();
            patch_CXCAS_3_2_0_1212_common();
        break;
        case 0x10340FE0:    // TI-NspireCX-3.2.0.1219/phoenix.raw
            patch_CXNCAS_3_2_0_1219_extra();
            patch_CXNCAS_3_2_0_1219_common();
        break;
        case 0x10341930:    // TI-NspireCXCAS-3.2.0.1219/phoenix.raw
            patch_CXCAS_3_2_0_1219_extra();
            patch_CXCAS_3_2_0_1219_common();
        break;
        case 0x103414F0:    // TI-NspireCX-3.2.3.1233/phoenix.raw
                            // TI-NspireCX-3.2.4.1237/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
            if (*((uint32_t *)0x108DF348) == 0x37333231) {
                patch_CXNCAS_3_2_3_1233_extra();
                patch_CXNCAS_3_2_3_1233_common();
            }
            else {
                patch_CXNCAS_3_2_4_1237_extra();
                patch_CXNCAS_3_2_4_1237_common();
            }
        break;
        case 0x10341E40:    // TI-NspireCXCAS-3.2.3.1233/phoenix.raw
            patch_CXCAS_3_2_3_1233_extra();
            patch_CXCAS_3_2_3_1233_common();
        break;
        case 0x10341E30:    // TI-NspireCXCAS-3.2.4.1237/phoenix.raw
            patch_CXCAS_3_2_4_1237_extra();
            patch_CXCAS_3_2_4_1237_common();
        break;
        case 0x103454A0:    // TI-NspireCXCAS-3.3.0.538/phoenix.raw
            patch_CXCAS_3_3_0_538_extra();
            patch_CXCAS_3_3_0_538_common();
        break;
        case 0x10375620:    // TI-NspireCX-3.6.0.546/phoenix.raw
            patch_CXNCAS_3_6_0_546_extra();
            patch_CXNCAS_3_6_0_546_common();
        break;
        case 0x10376090:    // TI-NspireCXCAS-3.6.0.546/phoenix.raw
            patch_CXCAS_3_6_0_546_extra();
            patch_CXCAS_3_6_0_546_common();
        break;


        case 0x102DBF20:    // TI-NspireCM-3.1.0.392/phoenix.raw
            patch_CMNCAS_3_1_0_392_extra();
            patch_CMNCAS_3_1_0_392_common();
        break;
        case 0x102DC6B0:    // TI-NspireCMCAS-3.1.0.392/phoenix.raw
            patch_CMCAS_3_1_0_392_extra();
            patch_CMCAS_3_1_0_392_common();
        break;
        case 0x1033C360:    // TI-NspireCM-3.2.0.1212/phoenix.raw
            patch_CMNCAS_3_2_0_1212_extra();
            patch_CMNCAS_3_2_0_1212_common();
        break;
        case 0x1033CCB0:    // TI-NspireCMCAS-3.2.0.1212/phoenix.raw
            patch_CMCAS_3_2_0_1212_extra();
            patch_CMCAS_3_2_0_1212_common();
        break;
        case 0x1033C410:    // TI-NspireCM-3.2.0.1219/phoenix.raw
            patch_CMNCAS_3_2_0_1219_extra();
            patch_CMNCAS_3_2_0_1219_common();
        break;
        case 0x1033CD60:    // TI-NspireCMCAS-3.2.0.1219/phoenix.raw
            patch_CMCAS_3_2_0_1219_extra();
            patch_CMCAS_3_2_0_1219_common();
        break;
#endif
        default:
            // Unknown / unimplemented OS version, don't patch it !
        DISPLAY(U);
        break;
    }
}
