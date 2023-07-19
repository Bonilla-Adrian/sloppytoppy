# Compiler options
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

# Source files
SRCS = main.c

# Output file name
TARGET = main

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET).elf

clean:
	rm -f $(TARGET).elf
buzzer.c: buzzer.h
main.c: buzzer.h
