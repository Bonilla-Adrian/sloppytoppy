# Compiler options
CPU             = msp430g2553
CFLAGS          = -I../h -I../include

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
