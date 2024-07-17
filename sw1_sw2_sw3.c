#include<LPC21xx.h>
#define SW1 (IOPIN0>>14&1)
#define SW2 (IOPIN0>>15&1)
#define SW3 (IOPIN0>>16&1)
main()
{
   int count=0;
   T0PR=15000-1;
   while(1)
   {

   if(SW1==0)
   {
   while(SW1==0);	   
   while(count!=59)
   {
   T0PC=0;
   T0TC=0;
   T0TCR=1;
   while(T0TC<8);
   count++;
   }
   }
   if(SW2==0)
   count--;
   while(SW2==0);

   if(SW3==0)
   {
   while(SW3==0);
   while(count)
   {
   T0PC=0;
   T0TC=0;
   T0TCR=1;
   while(T0TC<8);
    count--;
   }
   }

   }
}

