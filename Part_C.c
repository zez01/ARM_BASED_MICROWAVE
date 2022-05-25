void part_C (void){
unsigned char food_c []="Chicken weight?";
unsigned char weight_c[2];
unsigned char err_c[]="Err";


float x;
int	min,w;
int	sec; 
    keypad_init();
    LCD_init();
err:LCD_String(food_c);
    delayMs(2000);
    LCD_command(0x01);
    weight_c[0] &=0x0;  
	  weight_c[0] = getkey_real();
	  w=atoi(weight_c);


if( w>9 ){  //error
LCD_command(0x01);
LCD_String(err_c);
delayMs(2000);
LCD_command(0x01);

	goto err ;
}

LCD_String(weight_c);
delayMs(2000);
LCD_command(0x01);

x		= atoi(weight_c)*12;
min	= (int) x/60;
x	  = x/60;
x	 -= min;
x	 *= 60;
sec	= (int) x;
count_down_edit(sec,min);
}
