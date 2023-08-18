  /* 利用計時中斷方式完成10秒的計數顯示 */ 
/* 使用Timer 0 Mode 1(16 bits)模式來計數 */ 
#include<regx51.h>	  
#define segment_7 P2	     
#define cnt 50000 //宣告cnt=50000 (中斷的計數值)
code char tab[]={0xc0, // 共陽極顯示器0~9字型碼 	
  0xf9,0xa4,0xb0,0x99,0x92,0x83,0xf8,0x80,0x98};
char num,sec;	    
/*   主程式   */
void main (void)  
  { segment_7=tab[sec];	 //顯示器顯示0 
    EA=1;     // 開啟所有的中斷   
    ET0=1;	  // 開啟Timer 0 的中斷 
    TMOD=0x01; //設定計數/計數模式1(16 bits)
	  TR0=1;           // 啟動 Timer 0
    while(1);	 // 無窮迴圈,等待計時中斷  
  }
/*  T0 計時中斷的副程式  */
void timer0 (void) interrupt 3
  { TH0=(65536-cnt)/256;// TH0存放其商數 
    TL0=(65536-cnt)%256;// TL0存放其餘數 
    num++;			    // num加 1  
    if(num>=20)          // 1us*50000*20=1s
      { num=0;	              // num歸零 
	    sec++;	              // sec(秒)加1 
	    segment_7=tab[sec];	   // 秒數輸出顯示 
	  }
		if(sec >=10){
			TR0 = 0;
		}
  }