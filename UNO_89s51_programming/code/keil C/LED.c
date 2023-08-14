#include<regx51.h>
bit dir;
unsigned char led;
void delay(unsigned int value)
{ while(value>0) value--; }
void main(void)
{ dir=0;led=1;
  while(1)
    { P2=~led; // 89s51 used port 2 
	  delay(20000);
	  if(dir==0) led=led<<1;else led>>=1;
	  if(led==0x80) dir=1;
	  if(led==1) dir=0;
    }
}