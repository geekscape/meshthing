# This is a prototype Makefile. Modify it according to your needs.
# You should at least check the settings for
# DEVICE ....... The AVR device you compile for
# CLOCK ........ Target AVR clock rate in Hertz
# OBJECTS ...... The object files created from your source files. This list is
#                usually the same as the list of source files with suffix ".o".
# PROGRAMMER ... Options to avrdude which define the hardware you use for
#                uploading to the AVR and the interface where this hardware
#                is connected.
# FUSES ........ Parameters for avrdude to flash the fuses appropriately.

DEVICE     = atmega256rfr2
CLOCK      = 16000000
PROGRAMMER = -c usbasp -P usb
#PROGRAMMER = -c STK500v1 -P /dev/ttyACM0 -b 19200
#PROGRAMMER = -c STK500v2 -P /dev/ttyUSB2

OBJECTS    = SerialTest.o
# FUSES      = -U hfuse:w:0xd9:m -U lfuse:w:0x24:m
##FUSES      = -U hfuse:w:0xd2:m -U lfuse:w:0xff:m
# update that line with this when programmer is back up:
# FUSES      = -U hfuse:w:0xd7:m -U lfuse:w:0xff:m
FUSES      = -U hfuse:w:0xd8:m -U lfuse:w:0xef:m

# Tune the lines below only if you know what you are doing:

#AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE) -B 10 -D -F
AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE) -v -B 10 
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -I. -ffunction-sections

# symbolic targets:
all:	SerialTest.hex

.c.o:
	$(COMPILE) -c $< -o $@
	@$(COMPILE) -MM  $< > $*.d

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:SerialTest.hex:i

dirty: all
	$(AVRDUDE) -D -U flash:w:SerialTest.hex:i

fuse:
	$(AVRDUDE) $(FUSES)

# Xcode uses the Makefile targets "", "clean" and "install"
install: flash fuse

# if you use a bootloader, change the command below appropriately:
load: all
	bootloadHID SerialTest.hex

clean:
	rm -f SerialTest.hex main.elf $(OBJECTS) $(OBJECTS:.o=.d)

# file targets:
main.elf: $(OBJECTS)
	$(COMPILE) -o main.elf $(OBJECTS) -lm -Wl,--gc-sections

SerialTest.hex: main.elf
	rm -f SerialTest.hex
	avr-objcopy -j .text -j .data -O ihex main.elf SerialTest.hex
	avr-size -C --mcu=$(DEVICE) main.elf
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	main.elf
	avr-objdump -d main.elf

cpp:
	$(COMPILE) -E main.c

# include generated header dependencies
-include $(OBJECTS:.o=.d)

