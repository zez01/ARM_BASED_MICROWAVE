void part_B (void){
unsigned char food_b []="Beef weight?";
unsigned char weight_b[2];
unsigned char err_b[]="Err";
float x;
int	min,w;
int	sec; 
    keypad_init();
    LCD_init();
err:LCD_String(food_b);
    delayMs(2000);
    LCD_command(0x01);
    weight_b[0] &=0x0;  
	  weight_b[0] = getkey_real();
    w=atoi(weight_b);

if( w>9 ){  //error
LCD_command(0x01);
LCD_String(err_b);
delayMs(2000);
LCD_command(0x01);
goto err ;
}

LCD_String(weight_b);
delayMs(2000);
LCD_command(0x01);

x		= atoi(weight_b)*30;
min	= (int) x/60;
x	  = x/60;
x	 -= min;
x	 *= 60;
sec	= (int) x;
count_down_edit(sec,min);
}