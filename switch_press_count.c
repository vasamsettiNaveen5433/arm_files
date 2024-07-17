#include"header.h"
#define SW ((IOPIN0>>16)&1)
int main()
{
   u8 count=0;
   u8 arr[]="switch is pressed 00 times\r\n";
   uart0_init(9600);
   while(1)
   {
    if(SW==0)
	{
	 while(SW==0);
	 count++;
	 if(count==100)
	 count=1;
	 arr[18]=(count/10)+48;
	 arr[19]=(count%10)+48;
	 uart0_tx_string(arr);
	}
   }
   
}
