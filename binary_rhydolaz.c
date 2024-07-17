#include<LPC21xx.H>
#include"header.h"
#define LED 7<<17
#define SW (IOPIN0>>14&1)
main()
{
int i;
IODIR0=LED;
IOSET0=LED;
while(1)
{
 for(i=0;i<8;i++)
 {
  IOCLR0=i<<17;
  delay_ms(200);
  IOSET0=i<<17;
  delay_ms(200);
  }
  
}
}
