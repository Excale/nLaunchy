HOST_GCC = gcc
GCC = arm-none-eabi-gcc
LD  = arm-none-eabi-ld
GCCFLAGS = -Os -Wall -Wextra -Werror -Wno-attributes -marm -mcpu=arm926ej-s -s -fPIE -ffreestanding -std=gnu1x
LDFLAGS  = -nostdlib -nostartfiles -e nlaunch -PIE -T ldscript
OBJCOPY  = arm-none-eabi-objcopy
TNCN = nlaunch_classic.tns
TNCP = preloader_classic.tns
TNXN = nlaunch_cx.tns
TNXP = preloader_cx.tns
TNXF = firstloader_cx.tns
CFILES    = nlaunch.c patch.c patch_other.c ndless.c
HFILES    = nlaunch.h boot2.h
BUILDTNCO = buildtnco.exe
BUILDIMG  = buildimg.exe

all: classic cx

classic: ../CLASSIC/nlaunch.tnc ../CLASSIC/nlaunch.tno ../CLASSIC/nlaunch.tns

cx: ../CX/nlaunch.tcc ../CX/nlaunch.tco ../CX/nlaunch.tns

../CLASSIC/nlaunch.tnc: $(TNCN) $(TNCP) $(BUILDTNCO)
	./$(BUILDTNCO) -clr $(TNCN) $(TNCP) $@

../CLASSIC/nlaunch.tno: $(TNCN) $(TNCP) $(BUILDTNCO)
	./$(BUILDTNCO) -clr $(TNCN) $(TNCP) $@

../CLASSIC/nlaunch.tns: $(TNCN) $(TNCP) $(BUILDTNCO)
	./$(BUILDTNCO) -clr $(TNCN) $(TNCP) $@

../CX/nlaunch.tcc: $(TNXF) $(BUILDTNCO)
	./$(BUILDTNCO) -cxf $(TNXF) $(TNXF) $@

../CX/nlaunch.tco: $(TNXF) $(BUILDTNCO)
	./$(BUILDTNCO) -cxf $(TNXF) $(TNXF) $@

../CX/nlaunch.tns: $(TNXN) $(TNXP) $(BUILDTNCO)
	./$(BUILDTNCO) -cxr $(TNXN) $(TNXP) $@

buildimg: $(BUILDIMG)

nlaunch_classic.o: $(CFILES) $(HFILES)
	$(GCC) $(GCCFLAGS) -o $@ -c "-DMODEL=0" $<

preloader_classic.o: preloader.c $(HFILES)
	$(GCC) $(GCCFLAGS) -o $@ -c "-DMODEL=0" $<

nlaunch_cx.o: $(CFILES) $(HFILES)
	$(GCC) $(GCCFLAGS) -o $@ -c "-DMODEL=1" $<

preloader_cx.o: preloader.c $(HFILES)
	$(GCC) $(GCCFLAGS) -o $@ -c "-DMODEL=1" $<

firstloader_cx.o: firstloader.c $(HFILES)
	$(GCC) $(GCCFLAGS) -o $@ -c "-DMODEL=1" $<

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
