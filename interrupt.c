#define SRCPND              ( (volatile unsigned long *)0x4A000000 )
#define INTMOD              ( (volatile unsigned long *)0x4A000004 )
#define INTMSK              ( (volatile unsigned long *)0x4A000008 )
#define PRIORITY            ( (volatile unsigned long *)0x4A00000c )
#define INTPND              ( (volatile unsigned long *)0x4A000010 )
#define INTOFFSET           ( (volatile unsigned long *)0x4A000014 )
#define SUBSRCPND           ( (volatile unsigned long *)0x4A000018 )
#define INTSUBMSK           ( (volatile unsigned long *)0x4A00001c )

#define EINTMASK            ( (volatile unsigned long *)0x560000a4 )
#define EINTPEND            ( (volatile unsigned long *)0x560000a8 )


void init_irq(void)
{
	*EINTMASK &= ~((1<<11)|(1<<19));
	*INTMSK &= ~((1<<0)|(1<<2)|(1<<5)); //使能中断源
	__asm__(
			"mrs r0, cpsr \n"
			"bic r0, r0, #0x80 \n"
			"msr cpsr_c, r0 \n"
			:
			:
	//		:"r0"
			);
}


void handle_int(void)
{
	//判断中断源 
	unsigned long value = *INTOFFSET;
	unsigned long value_1 = *EINTPEND & ((1<<11)|(1<<19));
	switch (value)
	{
		case (0): 
			led_off();
		break;
		
		case (2): 
			led_on();
		break;
		
		case (5):
			switch (value_1)
			{
				case (1<<11): 
					led_off();
				break;
				case (1<<19): 
					led_on();
				break;	
				default:
				break;
			}
			
		break; 
	
		default:
		break;
	}
	//清除中断源
	if(5 == value)
	{
		*EINTPEND |= value_1;
	}
	*SRCPND |= (1<<value);
	*INTPND |= (1<<value);
		
}