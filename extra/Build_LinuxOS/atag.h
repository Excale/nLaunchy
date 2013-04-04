/*
    Taken from http://www.simtec.co.uk/products/SWLINUX/files/booting_article.html
    This file is BSD Licensed.
*/

/* list of possible tags */
#define ATAG_NONE       0x00000000
#define ATAG_CORE       0x54410001
#define ATAG_MEM        0x54410002
#define ATAG_VIDEOTEXT  0x54410003
#define ATAG_RAMDISK    0x54410004
#define ATAG_INITRD2    0x54420005
#define ATAG_SERIAL     0x54410006
#define ATAG_REVISION   0x54410007
#define ATAG_VIDEOLFB   0x54410008
#define ATAG_CMDLINE    0x54410009

/* structures for each atag */

#define ATAG_NEXT(a) (a) = (struct atag *)((uint32_t*)(a) + (a)->hdr.size)

struct atag_header {
	uint32_t size; /* length of tag in words including this header */
	uint32_t tag;  /* tag type */
};

struct atag_core {
	uint32_t flags;
	uint32_t pagesize;
	uint32_t rootdev;
};

struct atag_mem {
	uint32_t     size;
	uint32_t     start;
};

struct atag_videotext {
	uint8_t		     x;
	uint8_t		     y;
	uint16_t	     video_page;
	uint8_t		     video_mode;
	uint8_t		     video_cols;
	uint16_t	     video_ega_bx;
	uint8_t		     video_lines;
	uint8_t		     video_isvga;
	uint16_t	     video_points;
};

struct atag_ramdisk {
	uint32_t flags;
	uint32_t size;
	uint32_t start;
};

struct atag_initrd2 {
	uint32_t start;
	uint32_t size;
};

struct atag_serialnr {
	uint32_t low;
	uint32_t high;
};

struct atag_revision {
	uint32_t rev;
};

struct atag_videolfb {
	uint16_t	     lfb_width;
	uint16_t	     lfb_height;
	uint16_t	     lfb_depth;
	uint16_t	     lfb_linelength;
	uint32_t	     lfb_base;
	uint32_t	     lfb_size;
	uint8_t		     red_size;
	uint8_t		     red_pos;
	uint8_t		     green_size;
	uint8_t		     green_pos;
	uint8_t		     blue_size;
	uint8_t		     blue_pos;
	uint8_t		     rsvd_size;
	uint8_t		     rsvd_pos;
};

struct atag {
	struct atag_header hdr;
	union {
		struct atag_core	 core;
		struct atag_mem		 mem;
		struct atag_videotext	 videotext;
		struct atag_ramdisk	 ramdisk;
		struct atag_initrd2	 initrd2;
		struct atag_serialnr	 serialnr;
		struct atag_revision	 revision;
		struct atag_videolfb	 videolfb;
		char			cmdline[1];
	} u;
};
