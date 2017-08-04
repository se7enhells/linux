
int gboot_main()
{  
#ifdef MMU_ON
	mmu_init(); //初始化 MMU
#endif

	led_init();
	button_init();//中断源初始化
	init_irq();

	while(1);
	
	return 0;
}
