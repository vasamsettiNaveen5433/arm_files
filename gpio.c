#include"header.h"
#include<LPC21xx.H>
main()
{
int i,j=1;
IODIR0 =0Xff;
IOSET0 =0xff;
while(1)
{
for(i=0;i<4;i++)
{
IOCLR0=1<<(i*2+j);
delay_ms(200);
IOSET0=1<<(i*2+j);
delay_ms(300);
}
//			  i=!i;
			  j=!j;
}
}

