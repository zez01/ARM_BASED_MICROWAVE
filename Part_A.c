 void part_A (void){
	unsigned char food []=Popcorn;
			keypad_init();
			LCD_init();
			LCD_String(food);
			delayMs(2000);
		LCD_command(0x01);
	
		count_down_edit(0,1);
				LCD_command(0x01);

}