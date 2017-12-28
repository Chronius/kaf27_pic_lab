PORT=/dev/ttyUSB0
MCU=32MX320F128H

CC = xc32-gcc

LDFLAGS=-mprocessor=$(MCU) -T uno.ld
CFLAGS=-mprocessor=$(MCU) -mno-smart-io  -w  -fno-exceptions  -ffunction-sections  -fdata-sections  -g  -mdebugger  -Wcast-align  -fno-short-double -I include/
DEPFLAGS=-MD -MP -MF ./dep/$(@F).o.d 

SOURCE_DIR:=./src

ASRC=	$(SOURCE_DIR)/portable/PIC32MX/port_asm.S
SRC = 	$(SOURCE_DIR)/portable/PIC32MX/port.c \
	main.c \
	$(wildcard ./src/*.c)

OBJ = $(SRC:.c=.o) $(ASRC:.S=.o)
OBJ_DIR = $(addprefix ./obj/,$(OBJ))

all: flash

clean: 
	rm ./obj/*.o
	rm ./dep/*.d
	rm *.elf
	rm *.hex

$(ASRC:.S=.o): $(ASRC)
	$(CC) $(CFLAGS) -c $(<) -o ./obj/$(@F)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o ./obj/$(@F) $(<)

blinky.elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $(@) $(addprefix ./obj/, $(^F))

blinky.lss: blinky.elf
	xc32-objdump -h -S $(<) > $(@)

blinky.hex: blinky.elf
	xc32-objcopy -O ihex $(<) $(@)

flash: blinky.hex
	./serial_reset.sh $(PORT)
	avrdude -C avrdude.pic32.conf -c stk500v2 -p $(MCU) -P $(PORT) -b 115200 -U flash:w:$(<)

update_rom: 
	./serial_reset.sh $(PORT)
	avrdude -C avrdude.pic32.conf -c stk500v2 -p $(MCU) -P $(PORT) -b 115200 -U flash:w:blinky.hex
