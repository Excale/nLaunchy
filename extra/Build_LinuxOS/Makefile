CC	:= arm-none-eabi-gcc
LD	:= arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy

CFLAGS	:= -Os -Wall #-DDEBUG
LDFLAGS	:= -nostdlib

OBJS	:= startup.o kernel.o
OBJS	+= $(patsubst %.c,%.o,$(wildcard *.c))

OUTPUT	:= phoenix.bin

ifndef KERNEL
$(warning KERNEL not specified)
endif

ifndef CMDLINE
$(warning CMDLINE not specified)
else
CFLAGS	+= -DCMDLINE='"$(CMDLINE)"'
endif

ifdef RAMDISK_SIZE
CFLAGS	+= -DRAMDISK_SIZE="$(RAMDISK_SIZE)/1024"
endif

all: $(OUTPUT)

ifdef INITRD
OBJS	+= initrd.o
CFLAGS	+= -DHAVE_INITRD

initrd.o: $(INITRD)
	$(LD) -r -b binary -o $@ $^
	$(OBJCOPY) --rename-section .data=.payload.initrd $@
endif

%.o: %.S
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

kernel.o: $(KERNEL)
	$(LD) -r -b binary -o $@ $^
	$(OBJCOPY) --rename-section .data=.payload.kernel $@

$(OUTPUT): $(OBJS)
	$(LD) -T./ldscript $^ -o $(@:.bin=.elf) $(LDFLAGS)
	$(OBJCOPY) -O binary $(@:.bin=.elf) $@

clean:
	rm -f *.o *.elf
	rm -f $(OUTPUT)
