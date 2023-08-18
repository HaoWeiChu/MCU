#include<regx51.h> 
#define send_data P2 //宣告欲傳送資料由P2輸入 
/****      主程式(傳送端)       ****/
void main(void) 
{ send_data=0xff; // 規劃send_data(P2)為輸入埠 
  TMOD=0x20;  // 設定Timer 1的工作模式為Mode 2(8 bits)
  TH1=0xF3;	//設定鮑率為4800(OSC為12MHz)
  PCON=0x80;   // 設定SMOD=1
  TR1=1;	 // 啟動Timer 1 
  SM1=1; // 設定串列埠Mode 1(8 bit UART傳輸)
  while(1)
    { TI=0; // 可傳送資料了 
      SBUF=send_data; //傳送資料存入串列埠緩衝器中 
  	  while(TI==0); // TI=1表示一筆(8 bit)資料傳送完畢 
    }
} 


