all : start.o main.o mmu.o led.o button.o interrupt.o
	arm-linux-ld -Tgboot.lds -o gboot.elf $^
	arm-linux-objcopy -O binary gboot.elf gboot.bin 


%.o : %.S
	arm-linux-gcc -g -c $^

%.o : %.c
	arm-linux-gcc -c $^

