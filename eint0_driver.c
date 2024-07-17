#include"header.h"
#define LED (1<<17)
u32 flag=1;
u32 count=0;
void EINT0_Handler(void)__irq
{
 //static int flag;
 //int count=0;
 flag^=1;
  if(flag==0)
   IOCLR0=LED;
   else
   IOSET0=LED;

  //  flag^=1;
   count++;
 
  //flag=1;
   EXTINT=(1<<1);
   VICVectAddr=0;
}
void config_vic_for_eint0(void)
{
  VICIntSelect=0;
  VICVectCntl0=15|(1<<5);
  VICVectAddr0=(u32)EINT0_Handler;
  VICIntEnable|=(1<<15);
//   VICIntEnClr=1<<14;
}
void config_eint0(void)
{
 EXTPOLAR=0;
 EXTMODE=1<<1;
PINSEL0|=0x20000000;
 // PINSEL1|=1;
 // PINSEL0|=(2<<28);
// IODIR0|=LED;
}
