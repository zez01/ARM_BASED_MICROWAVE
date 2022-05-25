	
	
char SWF;
	int currrent_sys;

volatile short SW3;
//short out; // OUT Should be an output pin

char SWF_READ(){
  return (GPIO_PORTF_DATA_R & 0x11);
}
char SW3_READ(){
  return (GPIO_PORTA_DATA_R & 0x01);}

	//###################
char OUT_SW_READ(){ 
		return (GPIO_PORTA_DATA_R & 0x04); 
}
void Check_door(){
    SW3=OUT_SW_READ() ;


 while (SW3==0X00){
		SW3=OUT_SW_READ() ;
	 if (SW3!=0x00){
	 break ;
	 }
						// Delay while sw 3 is down for pause & before start (open door) 
}
}

unsigned char P___S(){
      Check_door(); // pause whenever the door is oppened
	      SWF = SWF_READ();
 if ((SWF&0x10)==0x10){return 0;}//NO Pause Sw1 is not pressed
//sw1 is pressed
 currrent_sys=NVIC_ST_CURRENT_R;// store timer 
     delayMs(500);
 while(1){  //pause
	 
	 GPIO_PORTF_DATA_R =	GPIO_PORTF_DATA_R ^ 0X0E;
		delayMs(250);
            SWF=SWF_READ();
					 //x= integer 
            if ((SWF&0x10)!=0x10){
						LCD_command(0x01);
							main();
						}//stop sw1 pushed
            else  if ((SWF&0x01)!=0x01)
{
	 GPIO_PORTF_DATA_R |=0X0E;

	NVIC_ST_CURRENT_R=currrent_sys;

break;}
        
		}
	return 0;
					
				}

