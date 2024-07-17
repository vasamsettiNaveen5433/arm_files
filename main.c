// main file
#include"header.h"
#include<LPC21xx.H>
main()
{
int i,z,x;
IODIR0=0Xff;
IOSET0=0xff;
while(1)
{
for(i=0,z=1,x=3;i<4;i++)
{
IOCLR0=1<<(i*2+z);
delay_ms(300);
IOSET0=1<<(i*2+z);
delay_ms(300);
if(i==x)
{
i=-1;
z=0;
x=5;
}
}

}
}



