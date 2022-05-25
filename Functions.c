void ItoA( float num,unsigned char * str )		// ItoA is a function to Place a decimal value in string
{
	float my_num = num /10 ; 
	int x = (int) my_num ; 
	str[0] = x + '0' ; 
	my_num -= x ; 
	my_num *= 10 ; 
	str[1] = my_num+'0' ;
}
int atoi(unsigned char* str)					// atoi is a function to convert an Ascii stored in string to decimal value
{
    int res = 0;
		int i;
    for (i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    // return result.
    return res;
}



void string_shift(unsigned char* str ,int k ){
	 int i=0;
		 for(i=0;i<k;i++){
			 str[0]=str[1];
			 str[1]=str[3];
		   str[3]=str[4];
			}
		}
