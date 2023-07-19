# Compiler options
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
AS              = msp430-elf-as

# Source files
SRCS = main.c

# Output file name
TARGET = main

all:
	$(CC) $(CFLAGS) $(AS) $(SRCS) -o $(TARGET).elf

clean:
	rm -f $(TARGET).elf
