#include<regx51.h> 

/* �D�{��(������) */
void main(void) 
{ TMOD=0x20;  // �]�w Timer 1���u�@�Ҧ���Mode 2(8 bits)�B����baud rate
  TH1=0xF3;	 // �]�w baud rate 4800 (12Mhz)
  PCON=0x80; // �]�w SMOD = 1
  TR1=1;	  // �Ұ� Timer 1
  SCON=0x50;  // �]�w��C �� MODE 1 �������
  while(1)
    { RI=0;	 
  	  while(RI==0);	 
   	  if(SBUF==0xfe)     // �����}���H�� 
	     P0 =0xfe; // LED �O���GP0_0
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
	  else 		 // �D�H�W���p
	     P0=0x00; // LED �����O�G
    }
}  