  int portf_data(void ){              //return of the swiches 
	return(GPIO_PORTF_DATA_R&0x11);
}
///start function

void part_D(void){

	unsigned char text[]= "cooking time ?" ;
  unsigned char err[10]="error";
	unsigned char no_in[6]="0000";   //use in calculation
	unsigned char zeros[7]="00:00";   
	unsigned char to_print[6]="00:00";// use in  print
	int k=0;
	int q;
	int jj ; 
	init_portF();
	keypad_init();
	LCD_init();
  LCD_String(text) ;
delayMs(1000);
	
 while (((portf_data()&0X01)== 0x01)){ //IF BUTTON 2 IS NOT PUSHED 
		
reset:if ((portf_data()&0X10)!= 0x10){   //if sw1 pushed
		LCD_command(0x01);
		LCD_String(zeros);
	   k=0 ;
		 for ( jj=0;jj<4;jj++){        // to init the lcd
				no_in[jj]='0';
			 to_print[jj]=zeros[jj];
		 }
		 }
	 if(k>=4){
	 continue;  // to not depend on the k==4
	 }
    no_in[k]	=getkey_real_modify(to_print) ;//IT START TO READ
		if (no_in[k]=='r'){
		goto reset ;                              // to scan the return from the  sw1 pushed while keypad scaned
		}
	 if (no_in[k]=='g'){                         //if key pad oushed
		no_in[k]='0';
		 break;
		}
			if(k!=0){
						string_shift(to_print,1);			    // shift the string before print
		}
		to_print[4]=no_in[k] ;		                 //print the array
		LCD_command(0x01);
		LCD_String(to_print);
	  delayMs(250); 

		    // NO OF THE VARIABLE MUST ENTER BY USER
		k++;
		}

	if (k==4){     // if they enter 4 no 
	  q =no_in[3]-'0';             //sec
		q+= ( no_in[2]-'0') *10;     //tenth of the sec
		q+= ( no_in[1]- '0' )*60;     // minuit
		q+= (no_in[0]-'0')*60*10;     // tenth of minuit
	  if(q < 1800) //to limit the max time 30:00
			{
				LCD_command(0x01);
		count_delay_sec(q);
		}
		else{    //time larger than 30:00;
				LCD_command(0x01);
				LCD_String(err);
				delayMs(2000);
				part_D ();
	}
}
 else if (k==3){ //3 input
	  q =no_in[2]-'0';
		q+= ( no_in[1]-'0') *10;
		q+= ( no_in[0]- '0' )*60; //o{
	  	LCD_command(0x01);
	 count_delay_sec(q);
	  
 }
else if (k==2){    //2input
  	q =no_in[1]-'0';
		q+= ( no_in[0]-'0') *10;	
	 LCD_command(0x01);
	count_delay_sec(q);
}
 else if (k==1){  //1 input 
		q =no_in[0]-'0';
		LCD_command(0x01);
	 count_delay_sec(q);
	
	}
	else {
		LCD_String(zeros);
	}

			 
	}