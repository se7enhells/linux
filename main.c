#define GPFCON 0x56000050
#define GPFDAT 0x56000054

int gboot_main()
{
	__asm__ volatile(
		"mov r1, #0x5500\n"
		"str r1, [%0]\n"
		"mov r1, #0x0\n"
		"str r1, [%1]\n"
		:
		:"r"(GPFCON),"r"(GPFDAT)
		:"r1"
	);
	
	return 0;
}
