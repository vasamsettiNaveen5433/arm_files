#include"header.h"
int main()
{
  u8 temp;
  u32 num,a[10];
  int pos,i=0;
  uart0_init(9600);
  while(1)
  {
   	 uart0_tx_string("\r\nEnter char: ");
	 temp=uart0_rx();
	 uart0_tx(temp);
	 while(uart0_rx()!='\r');
	 uart0_tx_string("\r\nASCII: ");
	 uart0_integer(temp);

	 for(i=i-1;i>=0;i--)
	 uart0_integer(a[i]);
	 uart0_tx_string("\r\n");

	   uart0_tx_string("0x");
	   num=temp;
	   if((num/16)<10)
	   uart0_integer(num/16);
	   else
	   uart0_tx(num/16+55);

	   if(num%16<10)
	   uart0_integer(num%16);
	   else
		uart0_tx(num%16+55);
	  uart0_tx_string("\r\n");

	  lcd_init();
      lcd_cmd(0x80);
	 for(pos=7;pos>=0;pos--)
	 {
	 
	  lcd_integer(temp>>pos&1); 
	  //   lcd_data(((temp>>pos)&1)+48);
	   uart0_tx(((temp>>pos)&1)+48);	  
	 }
  }
}

//	 for( ;num;num=num>>4)
//	 {
//	    for(sum1=0,count=0,pos=0;pos<4;pos++)
//		{
//		  r=num>>pos&1;
//		  count++;
//		  if(r)
//		  {
//		  if(count==1)
//		  sum1=sum1+1;
//		  if(count==2)
//		  sum1=sum1+2;
//		  if(count==3)
//		  sum1=sum1+4;
//		  if(count==4)
//		  sum1=sum1+8;
//		  }
//		}
//		a[i]=sum1;
//		i++;
//	 }

