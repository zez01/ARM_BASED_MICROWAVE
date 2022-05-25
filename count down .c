void count_down_edit(int x,int y){
int number_1 =x;
int number_2 =y;
int i;
	int jj;
	int pp ;
	int sss ;
unsigned char string_1[3];
unsigned char colon[2]={':'};
unsigned char string_2[3];
while(number_2 >=0){
	GPIO_PORTF_DATA_R|=0x0e;
ItoA(number_1,string_1);
ItoA(number_2,string_2);
for(i=number_1;i>=0;i--){
LCD_String(string_2);
LCD_String(colon);
LCD_String(string_1);
number_1 --;
ItoA(number_1,string_1);
	for ( jj=0 ;jj < 500 ; jj++ ){
delayMs(2);
	P___S();}
LCD_command(0x01);
}
number_1+=60;
number_2 --;
}
for (pp=0;pp<3;pp++){
GPIO_PORTF_DATA_R =	GPIO_PORTF_DATA_R ^ 0X0E;
	for (sss=0 ;sss<1000;sss++){
GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R ^ 0x08;
		delayMs(1);
	}
		delayMs(1000);
	
}
main();
}



 void count_delay_sec(float x){
 int minuit ;
	 int second;
	 minuit =(int) x/60;
	 x=x/60;
	 x-=minuit;
	 x*=60;
	 second = (int) x;
  count_down_edit(second ,minuit);
 }