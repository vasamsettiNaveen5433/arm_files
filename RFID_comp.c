#include"header.h"
main()
{
  u8 arr[13];
  u8 a[13]="4900C8FF3A44";
  u8 b[13]="020010A3A617";
  u8 c[13]="120026F4D616";
  uart0_init(9600);
  while(1)
  {
  // uart0_tx_string("welcome\r\n");
   uart0_rx_string(arr,12);
   uart0_tx_string(arr);
   uart0_tx_string("\r\n");

   if(strcmp(arr,a)==0)
   {
     uart0_tx_string("rara paparao\r\n");
   }
	else if(strcmp(arr,b)==0)
   {
     uart0_tx_string("second\r\n");
   }

   	 else if(strcmp(arr,c)==0)
   {
     uart0_tx_string("gupta\r\n");
   }
    else
	{  
	 	  uart0_tx_string("wrong card\r\n");
	}

  }
}
