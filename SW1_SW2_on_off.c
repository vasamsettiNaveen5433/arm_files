#include<LPC21xx.h>
#define SW1 (IOPIN0>>14&1)
#define SW2 (IOPIN0>>15&1)
main()
{
  int c=0,d=0;
  IODIR0=7<<17;
  IOSET0=7<<17;

  while(1)
  {
  if(SW1==0)
  {
   if(c==0)
   IOCLR0=1<<17;
   else
   IOSET0=1<<17;
   while(SW1==0);
   c=!c;
  }
 
  if(SW2==0)
  {
   if(d==0)
   IOSET0=1<<17;
   else
   IOCLR0=1<<17;
   while(SW2==0);
   d=!d;
  }


  }

}