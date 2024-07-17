#include"header.h"
//#define SW1 (IOPIN0>>14&1)
#define SW2 (IOPIN0>>15&1)
#define SW3 (IOPIN0>>16&1)
extern unsigned int flag;
extern unsigned int count;
int main()
{
  int c=0,cmd;
  IODIR0=7<<17;
  IOSET0=7<<17; 
  config_vic_for_eint0();
  config_eint0();
  uart0_init(9600);

  while(1)
  {
//  if(SW1==0)
//  {
//   while(SW1==0);
//   if(c==0)
//   IOCLR0=1<<17;
//   else
//   IOSET0=1<<17;
//   c=!c;
//  }

  if(flag==0)
  {
   if(SW2==0)
   {
    while(SW2==0);
	if(((IOPIN0>>18)&1)==1)
	IOCLR0=1<<18;
	else
	IOSET0=1<<18;
   }
   if(SW3==0)
   {
    while(SW3==0);
	if(((IOPIN0>>19)&1)==1)
 	IOCLR0=1<<19;
	else
	IOSET0=1<<19;
    }
  }
  else
  {
   uart0_tx_string("\r\nMenu");
   uart0_tx_string("\r\na.LED on");
   uart0_tx_string("\r\nb.LED off");
   uart0_tx_string("\r\nc.fan on");
   uart0_tx_string("\r\nd.fan off");
   uart0_tx_string("\r\ne.led & fan on");
   uart0_tx_string("\r\nf.led & fan off");
   uart0_tx_string("\r\noptions");

   cmd=uart0_rx();
 //  if(SW1==0)
  // continue;
   switch(cmd)
   {
	case 'a':IOCLR0=1<<18;break;
	case 'b':IOSET0=1<<18;break;
	case 'c':IOCLR0=1<<19;break;
	case 'd':IOSET0=1<<19;break;
	case 'e':IOCLR0=1<<18|1<<19;break;
	case 'f':IOSET0=1<<18|1<<19;break;
	default :uart0_tx_string("wrong cmd");
    
   }


  }

  }
   
}
