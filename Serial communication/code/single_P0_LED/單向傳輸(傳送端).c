#include<regx51.h> 
#define send_data P2 //�ŧi���ǰe��ƥ�P2��J 
/****      �D�{��(�ǰe��)       ****/
void main(void) 
{ send_data=0xff; // �W��send_data(P2)����J�� 
  TMOD=0x20;  // �]�wTimer 1���u�@�Ҧ���Mode 2(8 bits)
  TH1=0xF3;	//�]�w�j�v��4800(OSC��12MHz)
  PCON=0x80;   // �]�wSMOD=1
  TR1=1;	 // �Ұ�Timer 1 
  SM1=1; // �]�w��C��Mode 1(8 bit UART�ǿ�)
  while(1)
    { TI=0; // �i�ǰe��ƤF 
      SBUF=send_data; //�ǰe��Ʀs�J��C��w�ľ��� 
  	  while(TI==0); // TI=1��ܤ@��(8 bit)��ƶǰe���� 
    }
} 


