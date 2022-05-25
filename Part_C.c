void part_C (void){
unsigned char food []="Chicken weight?";
unsigned char weight[2];
unsigned char err[]="Err";
float x;
int	min;
int	sec; 
keypad_init();
LCD_init();
LCD_String(food);
delayMs(2000);
LCD_command(0x01);
weight[0] = getkey_real();


while(atoi(weight)<0 || atoi(weight)>9 ){;
LCD_String(err);
delayMs(2000);
LCD_command(0x01);
LCD_String(food);
weight[0] = getkey_real();
LCD_String(weight);
}
LCD_String(weight);
LCD_command(0x01);

x		= atoi(weight)*12;
min	= (int) x/60;
x	  = x/60;
x	 -= min;
x	 *= 60;
sec	= (int) x;
count_down_edit(sec,min);
}