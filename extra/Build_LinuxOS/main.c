/*
    Build_LinuxOS - for building a boot2 compatible Linux image
    Copyright (C) 2013  Daniel Tang

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <inttypes.h>
#include "atag.h"

extern const unsigned char initrd[];
extern const unsigned int initrd_size;
extern struct atag atag_list;

void __attribute__((noreturn)) kernel_begin(int zero, int mach, void *param);
void __attribute__((noreturn)) panic(void);

typedef volatile unsigned short	*io16_port;
typedef volatile unsigned int	*io32_port;

int is_cx = 0;
int mach_type = 0;

uint32_t mach_rev;
uint32_t ram_size;
uint64_t serial_num;

#ifdef DEBUG
void nputs(const char *ptr) {
	io32_port serial = (io32_port)0x90020000;
	unsigned char c;

	while ( (c = *ptr++) ) {
		serial[0] = c;
		if (is_cx) {
			while (serial[6] & (1<<5));
		} else {
			while (!(serial[5] & (1<<5)));
		}
	}
}
#else
#define nputs(x)
#endif

void nstrcpy(char *dst, const char *src) {
	while ( (*dst++ = *src++) );
}

void build_atags(void) {
	struct atag *current = &atag_list;

	current->hdr.tag	= ATAG_CORE;
	current->hdr.size	= 2;
	ATAG_NEXT(current);

	current->hdr.tag	= ATAG_MEM;
	current->hdr.size	= 4;
	current->u.mem.start	= 0x10000000;
	current->u.mem.size	= ram_size;
	ATAG_NEXT(current);

	current->hdr.tag	= ATAG_REVISION;
	current->hdr.size	= 3;
	current->u.revision.rev	= mach_rev;
	ATAG_NEXT(current);

	current->hdr.tag	= ATAG_SERIAL;
	current->hdr.size	= 4;
	current->u.serialnr.low	= serial_num;
	current->u.serialnr.high= serial_num>>32;
	ATAG_NEXT(current);

	current->hdr.tag	= ATAG_CMDLINE;
	current->hdr.size	= 2 + ((sizeof(CMDLINE) + 3) / 4);
	nstrcpy(current->u.cmdline, CMDLINE);
	ATAG_NEXT(current);

#ifdef RAMDISK_SIZE
	current->hdr.tag	= ATAG_RAMDISK;
	current->hdr.size	= 5;
	current->u.ramdisk.flags= 0;
	current->u.ramdisk.size	= RAMDISK_SIZE;
	current->u.ramdisk.start= 0;
	ATAG_NEXT(current);
#endif

#ifdef HAVE_INITRD
	current->hdr.tag	= ATAG_INITRD2;
	current->hdr.size	= 4;
	current->u.initrd2.start= (uint32_t)initrd;
	current->u.initrd2.size	= initrd_size;
	ATAG_NEXT(current);
#endif

	current->hdr.tag	= ATAG_NONE;
	current->hdr.size	= 0;
}

#define ADD_BITS(v,r,x,y) do { \
        unsigned len = ((y)-(x)+1); \
        v <<= len; \
        v  |= ((r)>>(x)) & ~(~0<<len); \
    } while (0)

void detect_serialnr() {
	uint64_t raw_serial = *(volatile uint64_t*)0x900A0028;

	ADD_BITS(serial_num, raw_serial, 33, 55);
	ADD_BITS(serial_num, raw_serial, 17, 31);
	ADD_BITS(serial_num, raw_serial, 9, 15);
	ADD_BITS(serial_num, raw_serial, 5, 7);
	ADD_BITS(serial_num, raw_serial, 3, 3);

	mach_rev = (raw_serial>>58) & 0x1F;
}
#undef ADD_BITS

void detect_mach(void) {
	io32_port misc	= (io32_port)0x900A0000,
		clock	= (io32_port)0x900B0000;
	io16_port keypad= (io16_port)0x900000d8;
	unsigned int model = *misc;

	model &= 0x0fff;
	if (model != 0x101 && model != 0x010) {
		nputs("Could not detect calculator model. Panicking.\n");
		panic();
	}

	if (model == 0x101) {
		is_cx = 1;
		ram_size = 0x04000000;
		mach_type = 4443;
		nputs("Detected as CX.\n");
		return;
	}

	if (*keypad & (1<<0)) {
		/* Keypad not plugged in? - probably a clickpad */
		ram_size = 0x02000000;
		mach_type = 4441;
		nputs("Detected as Clickpad.\n");
		goto classic;
	}

	/* Touchpad */
	ram_size = 0x02000000;
	mach_type = 4442;
	nputs("Detected as Touchpad.\n");
	goto classic;

classic:
	/* Workaround for stupid serial timing bug in the kernel */
	/* TODO: fix upstream */
	clock[0] = 0xa1002;
	clock[3] = 4;
	return;
}


int main(void) {
	detect_mach();
	detect_serialnr();
	build_atags();

	nputs("Booting kernel.\n");
	kernel_begin(0, mach_type, &atag_list);
}
