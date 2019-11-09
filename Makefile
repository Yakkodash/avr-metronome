.SUFFIXES:

TARGET  = metronome
MCU     = atmega328p
PROGR   = avrisp
PORT    = /dev/ttyS3

CC      = avr-gcc
OBJCOPY = avr-objcopy
DUDE    = avrdude

CFLAGS  = -Os -DF_CPU=16000000UL -std=gnu99 # -Wall -Werror # -DENABLE_POWERLOSS_DETECT # -DENABLE_EEPROM #
PFLAGS  = -b 19200
FUSES   = -U lfuse:w:0x7F:m # Ceramic resonator, slowly rising power, startup time 16K CK + 14 CK + 65ms

SRCDIR  = src
OBJDIR  = obj
BINDIR  = bin

SOURCES := $(wildcard $(SRCDIR)/*.c)
HEADERS := $(wildcard $(SRCDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONY: all
all: $(BINDIR)/$(TARGET).hex

$(BINDIR)/$(TARGET).hex: $(BINDIR)/$(TARGET).elf $(MAKEFILE_LIST)
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

$(BINDIR)/$(TARGET).elf: $(OBJECTS) $(MAKEFILE_LIST) | $(BINDIR)
	$(CC) -mmcu=$(MCU) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(MAKEFILE_LIST) | $(OBJDIR)
	$(CC) -mmcu=$(MCU) $(CFLAGS) -o $@ -c $<

$(OBJDIR) $(BINDIR):
	mkdir $@

.PHONY: flash
flash: $(BINDIR)/$(TARGET).hex
	$(DUDE) -c $(PROGR) -p $(MCU) -P $(PORT) $(PFLAGS) $(FUSES) -U flash:w:$<

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
