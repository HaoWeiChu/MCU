
#include<regx51.h>
#define LED P2
char i;
code char tab[]={0xc0,0xf9,0xa4, // table [0,1,2,3,4,5,6,7,8,9]
		         0xb0,0x99,0x92,0x83,0xf8,0x80,0x90};
void delay(unsigned int value)	// delay function
  { while(value>0) value--; }
void main(void)		 
  { int temp = 0x80;  
		while(1)		
		{ for(i=7;i>=0;i--){  // segment display
	       LED= ~temp;	
	        delay(50000);
					temp = temp>>1;
			}
			for(i=0;i<10;i++)  // table 0-9 display
	      { LED=tab[i];	
	        delay(50000); 
	      }	
	      	
				
    }
 }



