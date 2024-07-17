#include"header.h"
#include<LPC21xx.h>
#define LED 7<<17
#define SW  (IOPIN0>>14&1)
main()
{
   
   int count=0;
   int a[]={15,60,30,15,15};
   unsigned int pclk;
	IODIR0=LED;
    IOSET0=LED;
   pclk=a[VPBDIV]*1000000;
   T0PR=pclk-1;

   while(1)
   {
    if(SW==0)
	{
	  	count=0;
	 T0PC=0;
     T0TC=0;
	 T0TCR=1;
	  while(SW==0);
	  count++;
	 while(SW==1 && T0TC<1); 
	while(SW==0);
	count++;
   if(T0TC<1)
    IOCLR0=1<<17;
	else
	IOSET0=1<<17;
	while(T0TC<1);
	T0TCR=0;
	}
	}
   
  
 
}
