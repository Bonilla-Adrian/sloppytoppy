# Compiler options
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

# Source files
SRCS = main.c

# Output file name
TARGET = main

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET).elf

clean:
	rm -f $(TARGET).elf
