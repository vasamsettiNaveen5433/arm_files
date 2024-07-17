#include"header.h"
#include<LPC21xx.h>
main()

{
 u8 a[20],op;
 u32 i;
 u32 num1=0,num2=0,ret=0;
 uart0_init(9600);

 while(1)
 { 
   uart0_tx_string("enter the input\r\n");
   uart0_rx_string(a,19);
   uart0_tx_string(a);
   uart0_tx_string("\r\n");
   for(i=0,num1=0;a[i];i++)
   {
     if(a[i]>='0' && a[i]<='9')
	 num1=num1*10+(a[i]-48);
	 else
	 break;
   }
   op=a[i];
   
   for(i=i+1,num2=0;a[i];i++)
   {
     if(a[i]>='0' && a[i]<='9')
	 num2=num2*10+(a[i]-48);
	 else 
	 break;
   }
   if(op=='/' && num2==0)
   {
     uart0_tx_string("floating point error\r\n");
	 continue;
   }

   switch(op)
   {
    case '+':ret=num1+num2;
	         break;
	case '-':ret=num1-num2;
	         break;
	case '*':ret=num1*num2;
	         break;
	case '/':ret=num1/num2;
	         break;	
	default :uart0_tx_string("wrong expression\r\n\r\n");
	         continue;		 	 		    
   }


   uart0_tx_integer(ret);
   uart0_tx_string("\r\n");
   ret=0;

 }
}








