/* 
�m�ߤ��_����A�z�LP2_0�~��LED�O�H�μҲժ�LED�i�椤�_�m�ߡC
�i�z�L IT0�BIT1 �վ㤤�_�H���O�_�Q����
*/
#include <regx51.h>  	
unsigned char led; 
/*  ���𪺰Ƶ{��  */
void delay(unsigned int value)
  { while(value>0) value--;} 
/*  INT0�~�����_�Ƶ{��  */
void ext0 (void) interrupt 0 
  {	char i,led1;		  
  	led1=1;				    
    for(i=0;i<8;i++)	   
      { P0=~led1; 
	    led1<<=1;  //LED���� 
	    delay(30000);  
      }
  }
/*  INT1�~�����_�Ƶ{��  */  	
void ext1 (void) interrupt 2 
  {	char i;		 
  	P0 = 0xff;
	for(i=0;i<5;i++){
		P2_0 = 0;
		delay(50000);
		P2_0 = 1;
		delay(50000);
		}
	P2_0 = 1;
  }	
/*  �D�{��  */
void main (void)  
  { led=0;     
    IT0=IT1= 0;// 0 �N��C�AĲ�o�B1�N��t�tĲ�o
    PX1=1;      // �]�wINT1�u�� 
	EX0=EX1=1;  // �P��INT0,INT1���_ 	
    EA=1;	    // �}�Ҥ��_�`�}�� 
    while (1)  
      { 
		P2_0 = 1;
		P0=~led;  
	    led=~led; //��LED�{�{ 
        delay(20000); 
      }
  }


