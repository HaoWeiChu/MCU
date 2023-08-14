#include <reg52.h>
#define LED P0
void delay(unsigned int time) {
  while (time > 0) {
    time--;
  }
}

void main(void){
	int temp,i;
	while(1){
		temp = 0x80;
		for(i=0;i<8;i++){
				LED = ~temp;
				delay(20000);
				temp = temp >>1;
		}
}
}