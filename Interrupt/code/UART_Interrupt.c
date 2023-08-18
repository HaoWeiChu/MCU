/*
練習 串列傳輸中斷，透過串列傳輸將字串傳輸到電腦上的Tera term。
*/
#include <regx51.h>
code char string[10] = " hello ";
char i=0;
void main(void){
	TMOD = 0x20;
	TH1 = 243;
	SCON = 0x50;
	TR1 = 1;
	ES = 1;
	EA = 1;
	TI = 1;
	while(1);
}
/*
每按下一次 reset就會顯示一次 " hello " 
*/

void uart(void) interrupt 4{
	if(TI){
		TI = 0;
		if(i<7)
			SBUF = string[i++];
		else
			i=0;
	}
	if(RI){
		RI=0;
	}
}

