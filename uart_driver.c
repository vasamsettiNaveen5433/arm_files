#include"header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
#define THRE1 ((U1LSR>>5)&1)
#define RDR1 (U1LSR&1)	
extern u32 flag;
void uart0_init(u32 baud)
{
   int a[]={15,60,30,15,15};
    unsigned int pclk;
	unsigned int result=0;
   pclk=a[VPBDIV]*1000000;
   
   result =pclk/(16*baud);
   PINSEL0|=0x5;
   U0LCR=0x83;
   U0DLL=result &0xFF;
   U0DLM=(result>>8)&0xff;
   U0LCR=0x03;
}

void uart0_tx(unsigned char data)
{
 U0THR=data;
 while(THRE==0);
}

unsigned char uart0_rx(void)
{
   u8 temp;
  
   	 // while(((U0LSR>>1)&1)==1);
   //while(RDR==0 && SW1==1);
   while(RDR==0);
   temp=U0RBR;
	
	 
 return temp;
}

void uart0_tx_string(u8*ptr)
{
 while(*ptr)
 {
  U0THR=*ptr;
  while(THRE==0);
  ptr++;
 }
}

 void uart0_tx_integer(int num)
{
  int a[10],i=0;
  if(num==0)
  {
   uart0_tx('0');
  }
  if(num<0)
  {
   uart0_tx('-');
   num=-num;
  }
  while(num)
  {
   	a[i]=num%10+48;
	num=num/10;
	i++;
  }
  for(i=i-1;i>=0;i--)
  uart0_tx(a[i]);
} 


void uart0_tx_float(float f)
{
     int n,i;
	 u8 ch;
	 if(f==0)
	 {
	  uart0_tx('0');
	  return;
	 }
	 if(f<0)
	 {
	 uart0_tx('-');
	 f=-f;
	 }
	 n=f;
	 uart0_tx_integer(n);
	 uart0_tx('.');
	 
	 f=f-n;
	 f=f*10;

	 for(i=0;i<6;i++)
	 {
	  ch=(int)f+48;
	  uart0_tx(ch);
	  f=f-(int)f;
	  f=f*10;
	 }
} 

void uart0_rx_string(u8*ptr,u8 len)
{
 u8 i;
 for(i=0;i<len;i++)
 {
  while(RDR==0);
  ptr[i]=U0RBR;
  if(ptr[i]=='\r')
  break;
  }
  ptr[i]='\0';
}

void uart1_rx_string(u8*ptr,u8 len)
{
 u8 i;
 for(i=0;i<len;i++)
 {
  while(RDR1==0);
  ptr[i]=U1RBR;
  if(ptr[i]=='\r')
  break;
  }
  ptr[i]='\0';
}


void uart0_rx_string_password(u8*ptr,u8 len)
{
 u8 i,del=0;
 for(i=0;i<len; )
 {
  while(RDR==0);
  ptr[i]=U0RBR;
   if(ptr[i]=='\r')
  break;

  if(del==0)
   if(ptr[i]==8)
    goto L1;
  if(ptr[i]==8 && del )
  {
    uart0_tx('\b');
	uart0_tx(' ');
	uart0_tx('\b');
	i--;
	del--;

  }
  else 
  {
   uart0_tx('*');
   del++;
   i++;
  }
   
  L1:
  {
  }
  }
  ptr[i]='\0';
}
