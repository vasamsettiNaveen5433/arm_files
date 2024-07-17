#include"header.h"
main()
{
    u8 temp;
	uart0_init(9600);
	while(1)
	{
	 uart0_tx_string("\r\nEnter char: ");
	 temp=uart0_rx();
	 uart0_tx(temp);
	 while(uart0_rx()!='\r');
	 uart0_tx_string("\r\nASCII: ");
	 uart0_integer(temp);
	}


 // uart string
// uart0_init(9600);
// uart0_tx_string("VECTOR\r\nBLR");
//    uart0_tx_string("\r\nINSTITUTE");

  // loopback program
//  u8 temp;
//  uart0_init(9600);
//  while(1)
//  {
//   temp=uart0_rx();
//   uart0_tx(temp);
//  }
     




 // receive data
//  u8 temp;
//  uart0_init(9600);
//  lcd_init();
//  while(1)
//  {
//    temp=uart0_rx();
//	lcd_data(temp);
//  }	

  
   // transfer data

//  uart0_init(9600);
//  while(1)
//  {
//   uart0_tx('B');
//   delay_ms(50);
//  }				  
}
