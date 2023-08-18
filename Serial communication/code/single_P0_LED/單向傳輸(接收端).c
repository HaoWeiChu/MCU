#include<regx51.h> 

/* 主程式(接收端) */
void main(void) 
{ TMOD=0x20;  // 設定 Timer 1的工作模式為Mode 2(8 bits)、產生baud rate
  TH1=0xF3;	 // 設定 baud rate 4800 (12Mhz)
  PCON=0x80; // 設定 SMOD = 1
  TR1=1;	  // 啟動 Timer 1
  SCON=0x50;  // 設定串列 為 MODE 1 接收資料
  while(1)
    { RI=0;	 
  	  while(RI==0);	 
   	  if(SBUF==0xfe)     // 指撥開關信號 
	     P0 =0xfe; // LED 燈號亮P0_0
	  else if(SBUF==0xfd)// 
         P0=0xfd;
	  else if(SBUF==0xfb)
         P0=0xfb; 
	  else if(SBUF==0xf7)
         P0=0xf7;
   	  else if(SBUF==0xef)
	     P0=0xef;
	  else if(SBUF==0xdf)
         P0=0xdf;
	  else if(SBUF==0xbf)
         P0=0xbf;
	  else if(SBUF==0x7f)
         P0=0x7f;
	  else 		 // 非以上狀況
	     P0=0x00; // LED 全部燈亮
    }
}  