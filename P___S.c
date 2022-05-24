	
char SWF;
	int currrent_sys;
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

