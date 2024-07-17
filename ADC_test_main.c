#include"header.h"
main()
{
char op1,op2;
u32 temp;
 uart0_init(9600);
 spi0_init(); 
 adc_init();

 while(1)
 {
  uart0_tx_string("a.Test on-chip ADC of LPC2129\r\n");
  uart0_tx_string("b.Test MCP3204 external ADC\r\n");
  op1=uart0_rx();
  if(op1=='a')
  {
  uart0_tx_string("options....\r\n");
  uart0_tx_string("1.read Ain0\r\n");
  uart0_tx_string("2.read Ain1\r\n");
  uart0_tx_string("3.read Ain2\r\n");
  uart0_tx_string("4.read Ain3\r\n");
  op2=uart0_rx();

  switch(op2)
  {
	case '1':temp=adc_read(0);break;
	case '2':temp=adc_read(1);break;
	case '3':temp=adc_read(2);break;
	case '4':temp=adc_read(3);break;
	default :uart0_tx_string("wrong option\r\n");
  }
   uart0_tx_integer(temp);

   uart0_tx_string("\r\n");

  }
  else if(op1=='b')
  {
  uart0_tx_string("options....\r\n");
  uart0_tx_string("1.read CH0\r\n");
  uart0_tx_string("2.read CH1\r\n");
  uart0_tx_string("3.read CH2\r\n");
  uart0_tx_string("4.read CH3\r\n");
 
  op2=uart0_rx();

  switch(op2)
  {
	case '1':temp=mcp3204_read(0);break;
	case '2':temp=mcp3204_read(1);break;
	case '3':temp=mcp3204_read(2);break;
	case '4':temp=mcp3204_read(3);break;
	default :uart0_tx_string("wrong option\r\n");
  }
   uart0_tx_integer(temp);
   uart0_tx_string("\r\n");

   
  }
  else
  uart0_tx_string("wrong option\r\n");

 }



}

