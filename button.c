#define GPFCON ( (volatile unsigned long*)0x56000050 )
#define GPFDAT ( (volatile unsigned long*)0x56000054 )

#define GPGCON ( (volatile unsigned long*)0x56000060 )
#define GPGDAT ( (volatile unsigned long*)0x56000064 )

#define GPF0_msk  (3<<(0*2)) 
#define GPF2_msk  (3<<(2*2))
#define GPG3_msk  (3<<(3*2))
#define GPG11_msk (3<<(11*2))

#define GPF0_int  (2<<(0*2)) 
#define GPF2_int  (2<<(2*2))
#define GPG3_int  (2<<(3*2))
#define GPG11_int (2<<(11*2))


void button_init(void)  
{	
	*GPFCON &= ~(GPF0_msk|GPF2_msk);
	*GPFCON |=  GPF0_int|GPF2_int;
	*GPGCON &= ~(GPG3_msk|GPG11_msk);
	*GPGCON |=  GPG3_int|GPG11_int;
}



