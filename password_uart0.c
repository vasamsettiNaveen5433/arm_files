#include"header.h"
main()
{
 u32 count=0;
 u8 arr[50],p[5]="1234";
 uart0_init(9600);
 while(1)
 {
  if(count<3)
  {
  uart0_tx_string("Enter the password:");
  uart0_rx_string_password(arr,50);
  uart0_tx_string("\r\n");
//  uart0_tx_string(arr);
// uart0_tx_string("\r\n");
    if(strcmp(arr,p)==0)
	uart0_tx_string("password is correct \r\n");
	else
	{
	uart0_tx_string("password is wrong \r\n");
	count++;
	}
	}
	 else
	uart0_tx_string("blocked \r\n");
   }
//   else if(count>3)
//   {
//     
//    	 
//
//   }
}
