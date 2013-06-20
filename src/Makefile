HOST_GCC = gcc
GCC = nspire-gcc
LD  = nspire-ld
GCCFLAGS = -Os -g3 -nostdlib -Wall -W -Wno-attributes -marm -mcpu=arm926ej-s -s -fPIE -ffreestanding -std=gnu1x
LDFLAGS  = -nostdlib -ffreestanding --no-startup --no-ldscript -T ldscript 
OBJCOPY := "$(shell which arm-elf-objcopy 2>/dev/null)"
ifeq (${OBJCOPY},"")
	OBJCOPY := arm-none-eabi-objcopy
endif
TNCN = nlaunch_classic.tns
TNCP = preloader_classic.tns
TNXN = nlaunch_cx.tns
TNXP = preloader_cx.tns
TNXF = firstloader_cx.tns
FILES     = nlaunch.c patch.c patch_common.c patch_other.c ndless.c
BUILDTNCO = buildtnco.exe
BUILDIMG  = buildimg.exe
DISTDIR   = ../src
vpath %.tns $(DISTDIR)

all: classic cx

classic: $(TNCP) $(TNCN) $(BUILDTNCO)
	./$(BUILDTNCO) -clr $(TNCN) $(TNCP) ../CLASSIC/nlaunch.tnc
	./$(BUILDTNCO) -clr $(TNCN) $(TNCP) ../CLASSIC/nlaunch.tno
	./$(BUILDTNCO) -clr $(TNCN) $(TNCP) ../CLASSIC/nlaunch.tns

cx:      $(TNXF) $(TNXP) $(TNXN) $(BUILDTNCO)
	./$(BUILDTNCO) -cxf $(TNXF) $(TNXF) ../CX/nlaunch.tcc
	./$(BUILDTNCO) -cxf $(TNXF) $(TNXF) ../CX/nlaunch.tco
	./$(BUILDTNCO) -cxr $(TNXN) $(TNXP) ../CX/nlaunch.tns

buildimg: $(BUILDIMG)

nlaunch_classic.o: $(FILES)
	$(GCC) $(GCCFLAGS) -o nlaunch_classic.o    -c "-DMODEL=0" $<

preloader_classic.o: preloader.c
	$(GCC) $(GCCFLAGS) -o preloader_classic.o  -c "-DMODEL=0" $<

nlaunch_cx.o: $(FILES)
	$(GCC) $(GCCFLAGS) -o nlaunch_cx.o         -c "-DMODEL=1" $<

preloader_cx.o: preloader.c
	$(GCC) $(GCCFLAGS) -o preloader_cx.o       -c "-DMODEL=1" $<

firstloader_cx.o: firstloader.c
	$(GCC) $(GCCFLAGS) -o firstloader_cx.o     -c "-DMODEL=1" $<

$(TNCN): nlaunch_classic.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNCP): preloader_classic.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNXN): nlaunch_cx.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNXP): preloader_cx.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(TNXF): firstloader_cx.o
	$(LD) $(LDFLAGS) $^ -o $(@:.tns=.elf)
	$(OBJCOPY) -O binary   $(@:.tns=.elf) $@

$(BUILDTNCO): buildtnco.c
	$(HOST_GCC) -Os -s -o $@ $<

$(BUILDIMG):  buildimg.c
	$(HOST_GCC) -Os -s -o $@ $<

clean:
	rm -f *.o *.elf *.tns
	rm -f ../CLASSIC/*.* ../CX/*.*
	rm -f $(BUILDTNCO) $(BUILDIMG)
