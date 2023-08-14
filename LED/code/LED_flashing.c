#include <reg52.h>
/*
邏輯0 用以驅動LED(低態電壓)
*/
void delay_10us(unsigned int time) {
  while (time > 0) {
    time--;
  }
}

void main(void) {
    P0 = 0xf0;
    delay_10us(50000000);
		P0 = 0x0f;
    delay_10us(50000000); 	
		P0 = 0x01;
    delay_10us(50000);
    P0 = 0x02;
    delay_10us(50000);
		P0 = 0x04;
    delay_10us(50000);
		P0 = 0x08;
    delay_10us(50000);
		P0 = 0x10;
    delay_10us(50000);
    P0 = 0x20;
    delay_10us(50000);
		P0 = 0x40;
    delay_10us(50000);
		P0 = 0x80;
    delay_10us(50000);
	
  
}
