/*
 * nLaunchy
 *
 * Copyright (C) 2012-2013 nLaunch team
 * Copyright (C) 2013      nLaunch CX guy
 * Copyright (C) 2013-2014 Excale
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

static void write_ndless3x_loader(uint8_t model, uint8_t os) {
    // model: 0=non-CAS ; 1=CAS ; 2=CX non-CAS ; 3=CX CAS
    // os: 0=3.1.0.392 ; 1=3.6.0.546
    #define OFFSET_MODEL 0xCC
    #define OFFSET_OS    0x106
    static const unsigned int ndless3x_load_addr[][4] =  {{0x100A6A7C, 0x100A6D3C, 0x100A6178, 0x100A6460},
                                                          {0x100BE8B4, 0x100BEB6C, 0x100BDED4, 0x100BE1BC}};
    static unsigned char ndless3x_loader[] = {
    0x30, 0x40, 0x2D, 0xE9, 0xB0, 0x30, 0x9F, 0xE5, 0xB0, 0x20, 0x9F, 0xE5, 0xB0, 0x50, 0x9F, 0xE5,
    0xB0, 0x10, 0x9F, 0xE5, 0x00, 0x2C, 0x83, 0xE5, 0x05, 0x50, 0x8F, 0xE0, 0x00, 0x20, 0xA0, 0xE3,
    0x08, 0x20, 0x83, 0xE5, 0x2C, 0xD0, 0x4D, 0xE2, 0x00, 0x2C, 0x83, 0xE5, 0x05, 0x00, 0xA0, 0xE1,
    0x01, 0x10, 0x8F, 0xE0, 0x90, 0x30, 0x9F, 0xE5, 0x33, 0xFF, 0x2F, 0xE1, 0x00, 0x40, 0x50, 0xE2,
    0x1A, 0x00, 0x00, 0x0A, 0x0D, 0x10, 0xA0, 0xE1, 0x05, 0x00, 0xA0, 0xE1, 0x7C, 0x30, 0x9F, 0xE5,
    0x33, 0xFF, 0x2F, 0xE1, 0x14, 0x00, 0x9D, 0xE5, 0x74, 0x30, 0x9F, 0xE5, 0x33, 0xFF, 0x2F, 0xE1,
    0x14, 0x10, 0x9D, 0xE5, 0x01, 0x20, 0xA0, 0xE3, 0x04, 0x30, 0xA0, 0xE1, 0x64, 0xC0, 0x9F, 0xE5,
    0x00, 0x50, 0xA0, 0xE1, 0x3C, 0xFF, 0x2F, 0xE1, 0x04, 0x00, 0xA0, 0xE1, 0x58, 0x30, 0x9F, 0xE5,
    0x33, 0xFF, 0x2F, 0xE1, 0x54, 0x30, 0x9F, 0xE5, 0x28, 0x10, 0x8D, 0xE2, 0x03, 0x30, 0x8F, 0xE0,
    0x04, 0x30, 0x21, 0xE5, 0x7A, 0xFF, 0x17, 0xEE, 0xFD, 0xFF, 0xFF, 0x1A, 0x00, 0x30, 0xA0, 0xE3,
    0x17, 0x3F, 0x07, 0xEE, 0x01, 0x00, 0xA0, 0xE3, 0x04, 0x50, 0x85, 0xE2, 0x35, 0xFF, 0x2F, 0xE1,
    0x00, 0x00, 0xA0, 0xE3, 0x2C, 0xD0, 0x8D, 0xE2, 0x30, 0x80, 0xBD, 0xE8, 0x00, 0x00, 0x06, 0x90,
    0x51, 0xE5, 0xCC, 0x1A, 0xC4, 0x00, 0x00, 0x00, 0xD7, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA,
    0xBB, 0xBB, 0xBB, 0xBB, 0xCC, 0xCC, 0xCC, 0xCC, 0xDD, 0xDD, 0xDD, 0xDD, 0xEE, 0xEE, 0xEE, 0xEE,
    0x7E, 0x00, 0x00, 0x00, 0x2F, 0x64, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x73, 0x2F, 0x6E,
    0x64, 0x6C, 0x65, 0x73, 0x73, 0x2F, 0x6E, 0x64, 0x6C, 0x65, 0x73, 0x73, 0x5F, 0x72, 0x65, 0x73,
    0x6F, 0x75, 0x72, 0x63, 0x65, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x72,
    0x62, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    static const unsigned char ndless3x_loader_model_specific[][4][20] = {{{0x20, 0xA0, 0x37, 0x10, 0x58, 0x20, 0x38, 0x10, 0xF8, 0x48, 0x37, 0x10, 0xC4, 0xA1, 0x37, 0x10, 0x94, 0x98, 0x37, 0x10},
                                                                           {0x50, 0xA7, 0x37, 0x10, 0x88, 0x27, 0x38, 0x10, 0x28, 0x50, 0x37, 0x10, 0xF4, 0xA8, 0x37, 0x10, 0xC4, 0x9F, 0x37, 0x10},
                                                                           {0xE0, 0x78, 0x37, 0x10, 0x18, 0xF9, 0x37, 0x10, 0xB8, 0x21, 0x37, 0x10, 0x84, 0x7A, 0x37, 0x10, 0x54, 0x71, 0x37, 0x10},
                                                                           {0x70, 0x80, 0x37, 0x10, 0xA8, 0x00, 0x38, 0x10, 0x48, 0x29, 0x37, 0x10, 0x14, 0x82, 0x37, 0x10, 0xE4, 0x78, 0x37, 0x10}},
                                                                          {{0xD4, 0xE9, 0x3F, 0x10, 0xCC, 0x6A, 0x40, 0x10, 0x6C, 0x8F, 0x3F, 0x10, 0x78, 0xEB, 0x3F, 0x10, 0x48, 0xE2, 0x3F, 0x10},
                                                                           {0x14, 0xF4, 0x3F, 0x10, 0x0C, 0x75, 0x40, 0x10, 0xAC, 0x99, 0x3F, 0x10, 0xB8, 0xF5, 0x3F, 0x10, 0x88, 0xEC, 0x3F, 0x10},
                                                                           {0x58, 0xC8, 0x3F, 0x10, 0x50, 0x49, 0x40, 0x10, 0xF0, 0x6D, 0x3F, 0x10, 0xFC, 0xC9, 0x3F, 0x10, 0xCC, 0xC0, 0x3F, 0x10},
                                                                           {0xC8, 0xD2, 0x3F, 0x10, 0xC0, 0x53, 0x40, 0x10, 0x60, 0x78, 0x3F, 0x10, 0x6C, 0xD4, 0x3F, 0x10, 0x3C, 0xCB, 0x3F, 0x10}}};

    static const unsigned char ndless3x_loader_os_specific[][8] = {{0x2E, 0x74, 0x6E, 0x73, 0x00, 0x00, 0x00, 0x00},
                                                                   {0x5F, 0x33, 0x2E, 0x36, 0x2E, 0x74, 0x6E, 0x73}};
    unsigned int i;
    for (i = 0; i < sizeof(ndless3x_loader_model_specific[0][0]); i++) {
        ndless3x_loader[i+OFFSET_MODEL] = ndless3x_loader_model_specific[os][model][i];
    }
    for (i = 0; i < sizeof(ndless3x_loader_os_specific[0]); i++) {
        ndless3x_loader[i+OFFSET_OS]    = ndless3x_loader_os_specific[os][i];
    }
    char * dest = (char *)ndless3x_load_addr[os][model];
    for (i = 0; i < sizeof(ndless3x_loader); i++) {
        *dest++ = ndless3x_loader[i];
    }
}
