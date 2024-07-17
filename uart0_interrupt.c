#include"header.h"
u32 flag=0;
u8 a[17];
u32 i=0;
void uart0_handler(void)__irq
{
  u8 temp;
  int num=U0IIR&0x0E;
  if(num==0x4)
  {
    temp=U0RBR;
	a[i]=temp;
	i++;
	flag=1;
//	flag=0;
//	delay_ms(300);

  }
  if(num==0x02)
  {
    
  }
  VICVectAddr=0;
}
void config_vic_for_uart0(void)
{
  VICIntSelect=0;
  VICVectCntl1=6|(1<<5);
  VICVectAddr1=(int)uart0_handler;
  VICIntEnable|=(1<<6);
}
void en_uart0_interrupt(void)
{
  U0IER=3;
}








