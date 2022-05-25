void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
SCB->CPACR |= 0x00F00000;
}
  int main(){


	LCD_init()   ;
	keypad_init();
	init_portF() ;
	init_portA() ;

	while(1)
	{
		LCD_command(0x01);
			LCD_String("enter your choice") ;
		Check_door() ;
		switch (getkey_real())
			{
				case 'A' : part_A(); break;
				case 'B' : part_B(); break;
				case 'C' : part_C(); break;
				case 'D' : part_D(); break;

				default :{
					LCD_command(0x01);
					LCD_String("error") ;
					delayMs(1000);

				}
			}


	}

}
