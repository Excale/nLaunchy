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

#include "patch_common.c"
#include "patch_other.c"

//! Patch the OS.
static __attribute__((always_inline)) void patch_OS(void) {
    switch (*((volatile uint32_t *)0x10000020)) {
#if MODEL==0
        case 0x10166dc0:    // TI-NspireCAS-1.1.6925/phoenix.raw
        break;
        case 0x10138fd0:    // TI-Nspire-1.1.7320/phoenix.raw
        break;
        case 0x101476d0:    // TI-Nspire-1.1.8008/phoenix.raw
        break;
        case 0x101494d0:    // TI-NspireCAS-1.1.8408/phoenix.raw
        break;
        case 0x10149470:    // TI-Nspire-1.1.8410/phoenix.raw
        break;
        case 0x1014a9f0:    // TI-NspireCAS-1.1.9170/phoenix.raw
            patch_CAS_1_1_9170_extra();
            patch_CAS_1_1_9170_common();
        break;
        case 0x1014a9a0:    // TI-Nspire-1.1.9227/phoenix.raw
        break;
        case 0x1014a9c0:    // TI-Nspire-1.1.9253/phoenix.raw
            patch_NCAS_1_1_9253_extra();
            patch_NCAS_1_1_9253_common();
        break;
        case 0x101934c0:    // TI-NspireCAS-1.2.2344/phoenix.raw
        break;
        case 0x10193530:    // TI-NspireCAS-1.2.2394/phoenix.raw
        break;
        case 0x101919a0:    // TI-Nspire-1.2.2398/phoenix.raw
        break;
        case 0x101a2760:    // TI-NspireCAS-1.3.2406/phoenix.raw
                            // TI-NspireCAS-1.3.2437/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
        break;
        case 0x101a0c30:    // TI-Nspire-1.3.2407/phoenix.raw
        break;
        case 0x10362cb0:    // TI-NspireCAS-1.4.11643/phoenix.raw
        break;
        case 0x103141a0:    // TI-Nspire-1.4.11653/phoenix.raw
        break;
        case 0x10205e90:    // TI-NspireCAS-1.6.4295/phoenix.raw
        break;
        case 0x10203ea0:    // TI-Nspire-1.6.4379/phoenix.raw
        break;
        case 0x10211290:    // TI-Nspire-1.7.2741/phoenix.raw
            patch_NCAS_1_7_2741_extra();
            patch_NCAS_1_7_2741_common();
        break;
        case 0x102132a0:    // TI-NspireCAS-1.7.2741/phoenix.raw
            patch_CAS_1_7_2741_extra();
            patch_CAS_1_7_2741_common();
        break;
        case 0x1021a490:    // TI-Nspire-1.7.1.50/phoenix.raw
        break;
        case 0x1021c4a0:    // TI-NspireCAS-1.7.1.50/phoenix.raw
        break;
        case 0x1021c490:    // TI-NspireCAS-1.7.2.59/phoenix.raw
        break;
        case 0x1024ff00:    // TI-Nspire-2.0.1188/phoenix.raw
        break;
        case 0x102507d0:    // TI-NspireCAS-2.0.1188/phoenix.raw
        break;
        case 0x10266030:    // TI-Nspire-2.0.1.60/phoenix.raw
            patch_NCAS_2_0_1_60_extra();
            patch_NCAS_2_0_1_60_common();
        break;
        case 0x10266900:    // TI-NspireCAS-2.0.1.60/phoenix.raw
            patch_CAS_2_0_1_60_extra();
            patch_CAS_2_0_1_60_common();
        break;
        case 0x10279d70:    // TI-Nspire-2.1.0.631/phoenix.raw
            patch_NCAS_2_1_0_631_extra();
            patch_NCAS_2_1_0_631_common();
        break;
        case 0x1027a640:    // TI-NspireCAS-2.1.0.631/phoenix.raw
            patch_CAS_2_1_0_631_extra();
            patch_CAS_2_1_0_631_common();
        break;
        case 0x1027acf0:    // TI-Nspire-2.1.1.38/phoenix.raw
        break;
        case 0x1027b620:    // TI-NspireCAS-2.1.1.38/phoenix.raw
        break;
        case 0x102ed240:    // TI-Nspire-3.0.1.1753/phoenix.raw
            patch_NCAS_3_0_1_1753_extra();
            patch_NCAS_3_0_1_1753_common();
        break;
        case 0x102ed960:    // TI-NspireCAS-3.0.1.1753/phoenix.raw
            patch_CAS_3_0_1_1753_extra();
            patch_CAS_3_0_1_1753_common();
        break;
        case 0x102ed6d0:    // TI-Nspire-3.0.2.1791/phoenix.raw
            patch_NCAS_3_0_2_1791_extra();
            patch_NCAS_3_0_2_1791_common();
        break;
        case 0x102eddf0:    // TI-NspireCAS-3.0.2.1791/phoenix.raw
            patch_CAS_3_0_2_1791_extra();
            patch_CAS_3_0_2_1791_common();
        break;
        case 0x102f0fa0:    // TI-Nspire-3.1.0.392/phoenix.raw
            patch_NCAS_3_1_0_392_extra();
            patch_NCAS_3_1_0_392_common();
        break;
        case 0x102f16d0:    // TI-NspireCAS-3.1.0.392/phoenix.raw
            patch_CAS_3_1_0_392_extra();
            patch_CAS_3_1_0_392_common();
        break;
        case 0x103413d0:    // TI-Nspire-3.2.0.1212/phoenix.raw
            patch_CAS_3_2_0_1212_extra();
            patch_CAS_3_2_0_1212_common();
        break;
        case 0x10341cf0:    // TI-NspireCAS-3.2.0.1212/phoenix.raw
            patch_NCAS_3_2_0_1212_extra();
            patch_NCAS_3_2_0_1212_common();
        break;
        case 0x10341480:    // TI-Nspire-3.2.0.1219/phoenix.raw
            patch_NCAS_3_2_0_1219_extra();
            patch_NCAS_3_2_0_1219_common();
        break;
        case 0x10341da0:    // TI-NspireCAS-3.2.0.1219/phoenix.raw
            patch_CAS_3_2_0_1219_extra();
            patch_CAS_3_2_0_1219_common();
        break;
        case 0x10341990:    // TI-Nspire-3.2.3.1233/phoenix.raw
            patch_NCAS_3_2_3_1233_extra();
            patch_NCAS_3_2_3_1233_common();
        break;
        case 0x103422b0:    // TI-NspireCAS-3.2.3.1233/phoenix.raw
            patch_CAS_3_2_3_1233_extra();
            patch_CAS_3_2_3_1233_common();
        break;
#elif MODEL==1
        case 0x102eccd0:    // TI-NspireCX-3.0.1.1753/phoenix.raw
            patch_CXNCAS_3_0_1_1753_common();
            patch_CXNCAS_3_0_1_1753_extra();
        break;
        case 0x102ed420:    // TI-NspireCXCAS-3.0.1.1753/phoenix.raw
            patch_CXCAS_3_0_1_1753_common();
            patch_CXCAS_3_0_1_1753_extra();
        break;
        case 0x102ed170:    // TI-NspireCX-3.0.2.1791/phoenix.raw
                            // TI-NspireCX-3.0.2.1793/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
            if (*((uint32_t *)0x10831D08) == 0x6F68702F) {
                patch_CXNCAS_3_0_2_1791_common();
                patch_CXNCAS_3_0_2_1791_extra();
            } else {
                patch_CXNCAS_3_0_2_1793_common();
                patch_CXNCAS_3_0_2_1793_extra();
            }
        break;
        case 0x102ed8c0:    // TI-NspireCXCAS-3.0.2.1791/phoenix.raw
                            // TI-NspireCXCAS-3.0.2.1793/phoenix.raw
            // Warning: these two OS versions have the same reset vector !
            if (*((uint32_t *)0x107D60D0) == 0x6F68702F) {
                patch_CXCAS_3_0_2_1791_common();
                patch_CXCAS_3_0_2_1791_extra();
            } else {
                patch_CXCAS_3_0_2_1793_common();
                patch_CXCAS_3_0_2_1793_extra();
            }
        break;
        case 0x102f0a10:    // TI-NspireCX-3.1.0.392/phoenix.raw
            patch_CXNCAS_3_1_0_392_common();
            patch_CXNCAS_3_1_0_392_extra();
        break;
        case 0x102f11a0:    // TI-NspireCXCAS-3.1.0.392/phoenix.raw
            patch_CXCAS_3_1_0_392_extra();
            patch_CXCAS_3_1_0_392_common();
        break;
        case 0x10340f30:    // TI-NspireCX-3.2.0.1212/phoenix.raw
            patch_CXNCAS_3_2_0_1212_extra();
            patch_CXNCAS_3_2_0_1212_common();
        break;
        case 0x10341880:    // TI-NspireCXCAS-3.2.0.1212/phoenix.raw
            patch_CXCAS_3_2_0_1212_extra();
            patch_CXCAS_3_2_0_1212_common();
        break;
        case 0x10340fe0:    // TI-NspireCX-3.2.0.1219/phoenix.raw
            patch_CXNCAS_3_2_0_1219_extra();
            patch_CXNCAS_3_2_0_1219_common();
        break;
        case 0x10341930:    // TI-NspireCXCAS-3.2.0.1219/phoenix.raw
            patch_CXCAS_3_2_0_1219_extra();
            patch_CXCAS_3_2_0_1219_common();
        break;
        case 0x103414f0:    // TI-NspireCX-3.2.3.1233/phoenix.raw
            patch_CXNCAS_3_2_3_1233_extra();
            patch_CXNCAS_3_2_3_1233_common();
        break;
        case 0x10341e40:    // TI-NspireCXCAS-3.2.3.1233/phoenix.raw
            patch_CXCAS_3_2_3_1233_extra();
            patch_CXCAS_3_2_3_1233_common();
        break;
        
        
        case 0x102dbf20:    // TI-NspireCM-3.1.0.392/phoenix.raw
            patch_CMNCAS_3_1_0_392_extra();
            patch_CMNCAS_3_1_0_392_common();
        break;
        case 0x102dc6b0:    // TI-NspireCMCAS-3.1.0.392/phoenix.raw
            patch_CMCAS_3_1_0_392_extra();
            patch_CMCAS_3_1_0_392_common();
        break;
        case 0x1033c360: // TI-NspireCM-3.2.0.1212/phoenix.raw
            patch_CMNCAS_3_2_0_1212_extra();
            patch_CMNCAS_3_2_0_1212_common();
        break;
        case 0x1033ccb0: // TI-NspireCMCAS-3.2.0.1212/phoenix.raw
            patch_CMCAS_3_2_0_1212_extra();
            patch_CMCAS_3_2_0_1212_common();
        break;
        case 0x1033c410: // TI-NspireCM-3.2.0.1219/phoenix.raw
            patch_CMNCAS_3_2_0_1219_extra();
            patch_CMNCAS_3_2_0_1219_common();
        break;
        case 0x1033cd60: // TI-NspireCMCAS-3.2.0.1219/phoenix.raw
            patch_CMCAS_3_2_0_1219_extra();
            patch_CMCAS_3_2_0_1219_common();
        break;
#endif
        default:
            // Unknown OS version, don't patch it !
        DISPLAY(U);
        break;
    }
}
