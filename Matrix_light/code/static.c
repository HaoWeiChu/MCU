#include<regx51.h>
#include<matrixLED.h>
 
void delay(unsigned int value)	   // 延遲時間副程式 
  {while(value>0) value--; }
void main(void)				   // 主程式開始 
  {unsigned char i,j,time,number=0;
   while(1)
     {for(i=0,j=0x80;i<8;i++,j=j>>1)// 顯示一數字 
	      {P0=0xff;   
	       P1=j;	  
	       P0=~font[number][i]; 
	       delay(100);      // 延遲1ms
 	      }
	    time++;
	    if(time>=125) 	//每個數字顯示約1s的時間 
	      {time=0;
		     number++;    // 顯示下一個數字 
		     if(number>=10) number=0; //由0開始顯示 
		    }
     }	
  }	  