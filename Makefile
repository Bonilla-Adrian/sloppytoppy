CC = msp430-elf-gcc
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I. -I../h -L/opt/ti/msp430_gcc/include
OBJS = main.o buzzer.o melody.o buttons.o
TARGET = rickroll.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

load: $(TARGET)
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
