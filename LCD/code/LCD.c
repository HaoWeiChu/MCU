/*
練習透過 LCM模組顯示字串內容，完成LCM初始化設定。
*/
#include <regx51.h>
#define RS P1_0
#define RW P1_1
#define E  P1_2
code char string1[]={ "Testing------" };
code char string2[]={ "abcdefgh" };
code char string3[]={"aaaaaaaa"};

/* 延遲 10us */
void delay_10us(unsigned int time)
  { while(time>0) time--; }
/* 寫入指令 副程式(寫入至 LCM) */
void write_c(char lcd_data)
  { RS=0;RW=0;E=1;
    P0=lcd_data;
    delay_10us(100);
    E=0;delay_10us(100);
  }
/* 寫入資料 副程式(資料顯示在LCM)*/
void write_d(char lcd_data)
  { RS=1;RW=0;E=1;
    P0=lcd_data;
    delay_10us(100);
    E=0;delay_10us(100);
  }
/* LCM初始化 副程式 (使用八位元介面模式)*/
void init(void)
  { delay_10us(2000);
    write_c(0x30);	 
    write_c(0x30);	 
	write_c(0x38);	 
    write_c(0x08);  
    write_c(0x01);  
    write_c(0x06);  
    write_c(0x0c);  
  }
/* 顯示位置 副程式 */
void disp_p(char row,word)
  { char change_p;
    row--;word--;
    change_p=0x80+(row*0x40+word);
    write_c(change_p);
  } 
/* 顯示字串 副程式*/
void disp_s(char *ptr)
  { while(*ptr!=0)
      { write_d(*ptr);
        ptr++;
      }
  }
/* 主程式 */
void main(void)
  { init();		 //	LCM初始化
    disp_p(1,1); //第一個字串顯示位置設定
    disp_s(string1);//顯示字串一
    disp_p(2,1);	 //第二個字串顯示位置設定
    disp_s(string2);// 顯示字串二
	delay_10us(50000); // 顯示延遲
	init(); // 初始化
	disp_p(1,1);	 //第三個字串顯示位置設定 
    disp_s(string3);// 顯示字串三
    while(1);
  }
