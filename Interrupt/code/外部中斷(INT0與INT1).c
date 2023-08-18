/* 
練習中斷控制，透過P2_0外接LED燈以及模組的LED進行中斷練習。
可透過 IT0、IT1 調整中斷信號是否被紀錄
*/
#include <regx51.h>  	
unsigned char led; 
/*  延遲的副程式  */
void delay(unsigned int value)
  { while(value>0) value--;} 
/*  INT0外部中斷副程式  */
void ext0 (void) interrupt 0 
  {	char i,led1;		  
  	led1=1;				    
    for(i=0;i<8;i++)	   
      { P0=~led1; 
	    led1<<=1;  //LED左移 
	    delay(30000);  
      }
  }
/*  INT1外部中斷副程式  */  	
void ext1 (void) interrupt 2 
  {	char i;		 
  	P0 = 0xff;
	for(i=0;i<5;i++){
		P2_0 = 0;
		delay(50000);
		P2_0 = 1;
		delay(50000);
		}
	P2_0 = 1;
  }	
/*  主程式  */
void main (void)  
  { led=0;     
    IT0=IT1= 0;// 0 代表低態觸發、1代表負緣觸發
    PX1=1;      // 設定INT1優先 
	EX0=EX1=1;  // 致能INT0,INT1中斷 	
    EA=1;	    // 開啟中斷總開關 
    while (1)  
      { 
		P2_0 = 1;
		P0=~led;  
	    led=~led; //使LED閃爍 
        delay(20000); 
      }
  }


