# makfile configuration
COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: run-c.elf run-s.elf

run-c.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o main.o buzzer.o switches.o stateMachines.o led.o wdInterruptHandler.o toggle_green-c.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

run-s.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o main.o buzzer.o switches.o stateMachines.o led.o wdInterruptHandler.o toggle_green-s.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load-c: run-c.elf
	msp430loader.sh run.elf

load-s: run-s.elf
	msp430loader.sh run.elf

clean:
	rm -f *.o *.elf *~


led.o: led.c led.h
wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h stateMachines.h
switches.o: switches.h
buzzer.o: buzzer.h
toggle_green-s.o: led.h 
