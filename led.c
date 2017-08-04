#define GPFCON ( (volatile unsigned long*)0x56000050 )
#define GPFDAT ( (volatile unsigned long*)0x56000054 )

#define GPF4_msk (3<<(4*2)) 
#define GPF5_msk (3<<(5*2))
#define GPF6_msk (3<<(6*2))

#define GPF4_int (1<<(4*2)) 
#define GPF5_int (1<<(5*2))
#define GPF6_int (1<<(6*2))
void led_init(void)  
{
	*GPFCON &= ~(GPF4_msk|GPF5_msk|GPF6_msk);
	*GPFCON |= GPF4_int|GPF5_int|GPF6_int;
}

void led_on()
{
	*GPFDAT &= ~((1<<4)|(1<<5)|(1<<6));  
}

void led_off()
{
	*GPFDAT |= (1<<4)|(1<<5)|(1<<6);  
}