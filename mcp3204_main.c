#include"header.h"
main()
{
  u32 temp,percentage;
  float vout;
  uart0_init(9600);
  spi0_init();
  uart0_tx_string("MCP3204 test\r\n");
  while(1)
  {
   temp=mcp3204_read(2);
   uart0_tx_integer(temp);
   uart0_tx_string("   ");
   
   vout=(temp*5)/4095;
   uart0_tx(' ');
   uart0_tx_float(vout);
   uart0_tx_string("   ");

   percentage=(temp*100)/4095;
   uart0_tx_integer(percentage);
   uart0_tx('%');
   uart0_tx_string("\r\n"); 
   delay_ms(500);




   
  }
}
