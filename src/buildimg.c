/*
 * buildimg - helper for nLaunchy
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

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE * oscode_file = NULL;
FILE * fs_file     = NULL;
FILE * output      = NULL;

static void Write32BE (uint32_t in) {
    fputc (((int)(in >> 24)) & 0xFF, output);
    fputc (((int)(in >> 16)) & 0xFF, output);
    fputc (((int)(in >>  8)) & 0xFF, output);
    fputc (((int)(in      )) & 0xFF, output);
    fflush(output);
}

int main(int argc, char * argv[]) {

    if (argc != 4) {
        puts("TI-Nspire.img Builder v1.0\n"
             "Usage: buildimg phoenix.zip filesystem.zip output_file.img\n");
        exit(1);
    }

    oscode_file = fopen(argv[1], "rb");
    if (!oscode_file) {
        perror(argv[1]);
        exit(1);
    }

    fs_file = fopen(argv[2], "rb");
    if (!fs_file) {
        fclose(oscode_file);
        perror(argv[2]);
        exit(1);
    }

    output = fopen(argv[3], "wb");
    if (!output) {
        fclose(fs_file);
        fclose(oscode_file);
        perror(argv[3]);
        exit(1);
    }

    //Write 8000 with dummy size (updated after)
    static const unsigned char p8000[] = { 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00 };
    fwrite(p8000, sizeof(p8000[0]), sizeof(p8000)/sizeof(p8000[0]), output);

    //Write 8040
    static const unsigned char p8040[] = { 0x80, 0x4A, 0x54, 0x49, 0x2D, 0x4E, 0x73, 0x70, 0x69, 0x72, 0x65, 0x20 };
    fwrite(p8040, sizeof(p8040[0]), sizeof(p8040)/sizeof(p8040[0]), output);

    //Write 8010 D
    static const unsigned char p8010[] = { 0x80, 0x12, 0x00, 0x00 };
    fwrite(p8010, sizeof(p8010[0]), sizeof(p8010)/sizeof(p8010[0]), output);

    //Write 80E0 CAS
    static const unsigned char p80E0[] = { 0x80, 0xE1, 0x01 };
    fwrite(p80E0, sizeof(p80E0[0]), sizeof(p80E0)/sizeof(p80E0[0]), output);

    //Write 8020 D
    static const unsigned char p8020[] = { 0x80, 0x28, 0x31, 0x2E, 0x31, 0x2E, 0x30, 0x30, 0x30, 0x30 };
    fwrite(p8020, sizeof(p8020[0]), sizeof(p8020)/sizeof(p8020[0]), output);

    //Write 8020 D
    fwrite(p8020, sizeof(p8020[0]), sizeof(p8020)/sizeof(p8020[0]), output);

    //Write 8080 (0x10000000 ; 4 (==compressed) )
    static const unsigned char p8080[] = { 0x80, 0x88, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04 };
    fwrite(p8080, sizeof(p8080[0]), sizeof(p8080)/sizeof(p8080[0]), output);

    //Write 0320 D
    static const unsigned char p0320[] = { 0x03, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    fwrite(p0320, sizeof(p0320[0]), sizeof(p0320)/sizeof(p0320[0]), output);

    //Write 80F0 D
    static const unsigned char p80F0[] = { 0x80, 0xF4, 0x00, 0x00, 0x00, 0x00 };
    fwrite(p80F0, sizeof(p80F0[0]), sizeof(p80F0)/sizeof(p80F0[0]), output);

    //Write 8210 D
    static const unsigned char p8210[] = { 0x82, 0x14, 0x00, 0x00, 0x00, 0x00 };
    fwrite(p8210, sizeof(p8210[0]), sizeof(p8210)/sizeof(p8210[0]), output);

    //Write 8200 FS
    static const unsigned char p8200[] = { 0x82, 0x0F };
    fwrite(p8200, sizeof(p8200[0]), sizeof(p8200)/sizeof(p8200[0]), output);
    fseek (fs_file, 0, SEEK_END);
    long size_fs = ftell(fs_file);
    Write32BE((uint32_t)size_fs);
    fseek (fs_file, 0, SEEK_SET);
    char * fs_buffer = (char*) malloc (sizeof(char)*size_fs);
    fread (fs_buffer, sizeof(char), size_fs, fs_file);
    fwrite(fs_buffer, sizeof(char), size_fs, output);
    fclose(fs_file);

    //Write 8070 OS
    static const unsigned char p8270[] = { 0x80, 0x7F };
    fwrite(p8270, sizeof(p8270[0]), sizeof(p8270)/sizeof(p8270[0]), output);
    fseek (oscode_file, 0, SEEK_END);
    long size_os = ftell(oscode_file);
    Write32BE((uint32_t)size_os);
    fseek (oscode_file, 0, SEEK_SET);
    char * os_buffer = (char*) malloc (sizeof(char)*size_os);
    fread (os_buffer, sizeof(char), size_os, oscode_file);
    fwrite(os_buffer, sizeof(char), size_os, output);
    fclose(oscode_file);

    //Write 0240 D
    static const unsigned char p0240[] = { 0x02, 0x44, 0x00, 0x00, 0x00, 0x00 };
    fwrite(p0240, sizeof(p0240[0]), sizeof(p0240)/sizeof(p0240[0]), output);

    //Write FFF0
    static const unsigned char pFFF0[] = { 0xFF, 0xF0 };
    fwrite(pFFF0, sizeof(pFFF0[0]), sizeof(pFFF0)/sizeof(pFFF0[0]), output);

    //Update 8000 size
    long filesize = ftell(output);
    fseek(output, 2, SEEK_SET);
    Write32BE((uint32_t)(filesize-6));

    fclose(output);
    puts("Done.");
    return 0;
}
