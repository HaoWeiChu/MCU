  /* �Q�έp�ɤ��_�覡����10���p����� */ 
/* �ϥ�Timer 0 Mode 1(16 bits)�Ҧ��ӭp�� */ 
#include<regx51.h>	  
#define segment_7 P2	     
#define cnt 50000 //�ŧicnt=50000 (���_���p�ƭ�)
code char tab[]={0xc0, // �@������ܾ�0~9�r���X 	
  0xf9,0xa4,0xb0,0x99,0x92,0x83,0xf8,0x80,0x98};
char num,sec;	    
/*   �D�{��   */
void main (void)  
  { segment_7=tab[sec];	 //��ܾ����0 
    EA=1;     // �}�ҩҦ������_   
    ET0=1;	  // �}��Timer 0 �����_ 
    TMOD=0x01; //�]�w�p��/�p�ƼҦ�1(16 bits)
	  TR0=1;           // �Ұ� Timer 0
    while(1);	 // �L�a�j��,���ݭp�ɤ��_  
  }
/*  T0 �p�ɤ��_���Ƶ{��  */
void timer0 (void) interrupt 3
  { TH0=(65536-cnt)/256;// TH0�s���Ӽ� 
    TL0=(65536-cnt)%256;// TL0�s���l�� 
    num++;			    // num�[ 1  
    if(num>=20)          // 1us*50000*20=1s
      { num=0;	              // num�k�s 
	    sec++;	              // sec(��)�[1 
	    segment_7=tab[sec];	   // ��ƿ�X��� 
	  }
		if(sec >=10){
			TR0 = 0;
		}
  }