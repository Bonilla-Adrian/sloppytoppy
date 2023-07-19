# Compiler options
CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -Os

# Source files
SRCS = main.c

# Output file name
TARGET = main

all:
    $(CC) $(CFLAGS) $(SRCS) -o $(TARGET).elf

clean:
    rm -f $(TARGET).elf
