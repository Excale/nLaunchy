HOST_GCC = gcc
GCC = nspire-gcc
LD  = nspire-ld
GCCFLAGS = -Os -nostdlib -Wall -W -Wno-attributes -marm -mcpu=arm926ej-s -s -fPIE -ffreestanding -std=gnu11
LDFLAGS  = -nostdlib -ffreestanding --no-startup --no-ldscript -T ldscript 
OBJCOPY := "$(shell which arm-elf-objcopy 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
TNSC = nlaunch_classic.tns
TNSX = nlaunch.tns
TNSF = firstloader_cx.tns
TNSL = preloader_cx.tns
TNC  = nlaunch.tnc
TNO  = nlaunch.tno
TCC  = nlaunch.tcc
TCO  = nlaunch.tco
FILES     = nlaunch.c patch.c patch_common.c patch_other.c ndless.c
BUILDTNCO = buildtnco.exe
BUILDIMG  = buildimg.exe
DISTDIR   = ../src
vpath %.tns $(DISTDIR)

all: $(TNSC) $(TNSX) $(TNSL) $(BUILDTNCO) $(BUILDIMG) $(TNC)

nlaunch_classic.o: $(FILES)
	$(GCC) $(GCCFLAGS) -o nlaunch_classic.o -c "-DMODEL=0" $<
	
preloader_cx.o: preloader_cx.c
	$(GCC) $(GCCFLAGS) -o preloader_cx.o    -c "-DMODEL=1" $<

firstloader_cx.o: firstloader_cx.c
	$(GCC) $(GCCFLAGS) -o firstloader_cx.o  -c "-DMODEL=1" $<

nlaunch_cx.o:      $(FILES)
	$(GCC) $(GCCFLAGS) -o nlaunch_cx.o      -c "-DMODEL=1" $<

$(TNSC): nlaunch_classic.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNSX): nlaunch_cx.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNSL): preloader_cx.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNSF): firstloader_cx.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(BUILDTNCO): buildtnco.c
	$(HOST_GCC) -Os -s -o $@ $<

$(BUILDIMG): buildimg.c
	$(HOST_GCC) -Os -s -o $@ $<

$(TNC): $(TNSC) $(TNSF) $(TNSL) $(BUILDTNCO)
	./$(BUILDTNCO) -classic nlaunch_classic.tns nlaunch.tno
	./$(BUILDTNCO) -classic nlaunch_classic.tns nlaunch.tnc
	./$(BUILDTNCO) -cpx     firstloader_cx.tns  nlaunch.tco
	./$(BUILDTNCO) -cpx     firstloader_cx.tns  nlaunch.tcc
	./$(BUILDTNCO) -cx      preloader_cx.tns    preloader.tns

clean:
	rm -f *.o *.elf *.tns
	rm -f $(DISTDIR)/$(TNC) $(DISTDIR)/$(TNO) $(DISTDIR)/$(TCC) $(DISTDIR)/$(TCO)
	rm -f $(BUILDTNCO)
	rm -f $(BUILDIMG)
