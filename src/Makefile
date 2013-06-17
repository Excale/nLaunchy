HOST_GCC = gcc
GCC = nspire-gcc
LD  = nspire-ld
GCCFLAGS = -Os -g3 -nostdlib -Wall -W -Wno-attributes -marm -mcpu=arm926ej-s -s -fPIE -ffreestanding -std=gnu1x
LDFLAGS  = -nostdlib -ffreestanding --no-startup --no-ldscript -T ldscript 
OBJCOPY := "$(shell which arm-elf-objcopy 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
TNSC = nlaunch_classic.tns
TNSP = preloader_classic.tns
TNSX = nlaunch_cx.tns
TNSL = preloader_cx.tns
TNSF = firstloader_cx.tns
TNC  = ../CLASSIC/nlaunch.tnc
TNO  = ../CLASSIC/nlaunch.tno
TNSC = ../CLASSIC/nlaunch.tns
TCC  = ../CX/nlaunch.tcc
TCO  = ../CX/nlaunch.tco
TNSX = ../CX/nlaunch.tns
FILES     = nlaunch.c patch.c patch_common.c patch_other.c ndless.c
BUILDTNCO = buildtnco.exe
BUILDIMG  = buildimg.exe
DISTDIR   = ../src
vpath %.tns $(DISTDIR)

all: $(TNSC) $(TNSP) $(TNSX) $(TNSL) $(TNSF) buildtnco $(BUILDIMG) $(TNC)

nlaunch_classic.o: $(FILES)
	$(GCC) $(GCCFLAGS) -o nlaunch_classic.o    -c "-DMODEL=0" $<

preloader_classic.o: preloader.c
	$(GCC) $(GCCFLAGS) -o preloader_classic.o  -c "-DMODEL=0" $<

nlaunch_cx.o: $(FILES)
	$(GCC) $(GCCFLAGS) -o nlaunch_cx.o         -c "-DMODEL=1" $<

preloader_cx.o: preloader.c
	$(GCC) $(GCCFLAGS) -o preloader_cx.o       -c "-DMODEL=1" $<

firstloader_cx.o: firstloader_cx.c
	$(GCC) $(GCCFLAGS) -o firstloader_cx.o     -c "-DMODEL=1" $<

$(TNSC): nlaunch_classic.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNSP): preloader_classic.o
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

$(BUILDIMG):  buildimg.c
	$(HOST_GCC) -Os -s -o $@ $<

buildtnco: $(TNSC) $(TNSP) $(TNSX) $(TNSL) $(TNSF) $(BUILDTNCO)
	./$(BUILDTNCO) -classic $(TNSC) $(TNSP) $(TNC)
	./$(BUILDTNCO) -classic $(TNSC) $(TNSP) $(TNO)
	./$(BUILDTNCO) -classic $(TNSC) $(TNSP) $(TNSC)
	./$(BUILDTNCO) -cpx     $(TNSF) $(TNSF) $(TCC)
	./$(BUILDTNCO) -cpx     $(TNSF) $(TNSF) $(TCO)
	./$(BUILDTNCO) -cx      $(TNSX) $(TNSL) $(TNSX)

clean:
	rm -f *.o *.elf *.tns
	rm -f ../CLASSIC/*.* ../CX/*.*
	rm -f $(BUILDTNCO) $(BUILDIMG)
