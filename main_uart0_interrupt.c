#include"header.h"
u32 count=0;
u32 count1=0;
extern u32 i;
extern u32 flag;
extern u8 a[17];
main()
{
  uart0_init(9600);
  config_vic_for_uart0();
  en_uart0_interrupt();
  while(1)
  {
    count++;
	if(flag==1)
	{
	  	count1++;
		flag=0;
		if(a[i-1]=='\r')
		{
		 a[i]=0;
		 uart0_tx_string(a);
		 uart0_tx_string("\r\n");
		 i=0;
		 a[i]='\0';

		}
	}
  }

}
