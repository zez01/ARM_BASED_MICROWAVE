#include  "Io.h"
#include "tm4c123gh6pm.h"
#include "keypad.c"
#include "macros.c"
#include "LCD initialization.c"
#include "Functions.c"
#include "P___S.c"
#include "Get_Key_Modified.c"
//#include "count down .c"
#include "Part_A.c"
#include "Part_B.c"
#include "Part_C.c"
#include "Part_D.c"
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
