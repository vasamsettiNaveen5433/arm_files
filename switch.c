#include<LPC21xx.H>
#include"header.h"
#define LED 1<<17
#define SW (IOPIN0>>14&1)
main()
{
int count=0;
IODIR0=LED;
//IOSET0=;
while(1)
{
if(SW==0)
{
IOCLR0=1<<17;
 
 while(SW==0) ;
 count++;
 }
 else
 IOSET0=1<<17;
}
}
/*{
int count=0;
IODIR0=0X01;
while(1)
{
 if((IOPIN0>>5&1)==0)
 {
 IOCLR0=0X01;
 }
 else
 {
 IOSET0=0X01;
 count++;
 }
 }
} */
