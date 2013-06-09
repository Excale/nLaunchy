CC	:= arm-none-eabi-gcc
LD	:= arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy

CFLAGS	:= -Os -Wall
LDFLAGS	:= -nostdlib

OBJS	:= startup.o
OBJS	+= $(patsubst %.c,%.o,$(wildcard *.c))

OUTPUT	:= phoenix.bin

all: $(OUTPUT)

%.o: %.S
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(OUTPUT): $(OBJS)
	$(LD) -T./ldscript $^ -o $(@:.bin=.elf) $(LDFLAGS)
	$(OBJCOPY) -O binary $(@:.bin=.elf) $@

clean:
	rm -f *.o *.elf
	rm -f $(OUTPUT)
