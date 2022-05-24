nt atoi();
 int portf_data(void );
 unsigned char getkey_real(void);
unsigned char getkey_real_modify(char*to_print)
{
	//unsigned char string[] ="5od sambosa";
  unsigned char ch ; 
	unsigned char  err[]="error ";
	
	//LCD_String(string);
	// delayMs(1000);
	
	keypad_init() ; 
	
	while (1)
	{
		

		if ((portf_data()&0X10)!= 0x10){
		return 'r';
		}
		if ((portf_data()&0X01)!= 0x01){              
		return 'g';
		}
		ch=keypad_getkey();
		if(((ch-'0')<0 || (ch-'0')>9)&& ch!=0 ){
			LCD_command(0x01);
			LCD_String(err);
			delayMs(2000);
      LCD_command(0x01);
			LCD_String(to_print);
			continue ;
			
}
		if (ch !=0)break;
	
		
	}
	return ch  ;
	
}
unsigned char getkey_real(void)
{
	
  unsigned char ch ; 
	
	
	keypad_init() ; 
	
	while (1)
	{
		
		
		ch=keypad_getkey();
		if (ch !=0)break;
	
		
	}
	return ch  ;
}