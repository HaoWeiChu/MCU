#include<regx51.h>
#include<matrixLED.h>
 
void delay(unsigned int value)	   // ����ɶ��Ƶ{�� 
  {while(value>0) value--; }
void main(void)				   // �D�{���}�l 
  {unsigned char i,j,time,number=0;
   while(1)
     {for(i=0,j=0x80;i<8;i++,j=j>>1)// ��ܤ@�Ʀr 
	      {P0=0xff;   
	       P1=j;	  
	       P0=~font[number][i]; 
	       delay(100);      // ����1ms
 	      }
	    time++;
	    if(time>=125) 	//�C�ӼƦr��ܬ�1s���ɶ� 
	      {time=0;
		     number++;    // ��ܤU�@�ӼƦr 
		     if(number>=10) number=0; //��0�}�l��� 
		    }
     }	
  }	  