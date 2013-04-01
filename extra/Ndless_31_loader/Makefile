GCC = nspire-gcc
LD = nspire-ld
GCCFLAGS = -Os -Wall -W -marm
LDFLAGS = 
OBJCOPY := "$(shell which arm-elf-objcopy 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
EXE = ndlessloader.tns
OBJS = $(patsubst %.c,%.o,$(wildcard *.c))
DISTDIR = .
vpath %.tns $(DISTDIR)

all: $(EXE)

ndlessloader.o: ndlessloader.c
	$(GCC) $(GCCFLAGS) -c $<

$(EXE): $(OBJS)
	$(LD) $^ -o $(@:.tns=.elf) $(LDFLAGS)
	mkdir -p $(DISTDIR)
	$(OBJCOPY) -O binary $(@:.tns=.elf) $(DISTDIR)/$@

clean:
	rm -f *.o *.elf
	rm -f $(DISTDIR)/$(EXE)
