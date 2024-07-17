//#include<lpc21xx.h>
#include"header.h"
void lcd_data(unsigned char data)
{
     IOCLR1=0XFE<<16;
	 IOSET1=(data&0xf0)<<16;
	 IOSET1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(2);
	 IOCLR1=1<<19;

	 IOCLR1=0XFE<<16;
	 IOSET1=(data&0x0f)<<20;
	 IOSET1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(2);
	 IOCLR1=1<<19;

}
void lcd_cmd(unsigned char cmd)
{
   IOCLR1=0XFE<<16;
	 IOSET1=(cmd&0xf0)<<16;
	 IOCLR1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(2);
	 IOCLR1=1<<19;

	 IOCLR1=0XFE<<16;
	 IOSET1=(cmd&0x0f)<<20;
	 IOCLR1=1<<17;
	 IOCLR1=1<<18;
	 IOSET1=1<<19;
	 delay_ms(2);
	 IOCLR1=1<<19;
}
void lcd_init()
{
  IODIR1=0Xfe<<16;
	PINSEL2=0X0;
	IOCLR1=1<<19;
	lcd_cmd(0x02);
	lcd_cmd(0x28);
    lcd_cmd(0x0e);
	lcd_cmd(0x01);
}
 void lcd_string(char*p)
{
   while(*p)
   {
   lcd_data(*p);
   p++;
   }
 }

/*void lcd_string(char*p,int i)
{
   int j=0,z=0;
   while(*p)
   {
   lcd_data(*p);
   p++;
   z++;
   if(i+z>15)
   {
   lcd_cmd(0x80+j);
   j++;
   } 
   }
 }  */



void lcd_integer(int num)
{
  int a[10],i=0;
  if(num==0)
  {
  lcd_data('0');
  }
  if(num<0)
  {
   lcd_data('-');
   num=-num;
  }
  while(num)
  {
   	a[i]=num%10+48;
	num=num/10;
	i++;
  }
  for(i=i-1;i>=0;i--)
  lcd_data(a[i]);
} 


void lcd_float(float f)
{
     unsigned int n;
//	 int i;
//	 unsigned char ch;
	 if(f==0)
	 {
	  lcd_data('0');
	  return;
	 }
	 if(f<0)
	 {
	 lcd_data('-');
	 f=-f;
	 }
	 n=f;
	 lcd_integer(n);
	 lcd_data('.');
	 
	 f=f-n;
	 f=f*1000000;
	 n=f;
	 lcd_integer(n);

//	 for(i=0;i<6;i++)
//	 {
//	  ch=(int)f+48;
//	  lcd_data(ch);
//	  f=f-(int)f;
//	  f=f*10;
//	 }
} 

void lcd_cgram(void)
{
    //unsigned char a[]={0x0,0xA,0xA,0x0,0x0,0x11,0xE,0x0};
	unsigned char b[]={0x0,0x1B,0x15,0x11,0x11,0xA,0x4,0x0};
	int i;
//	lcd_cmd(0x40);
//	for(i=0;i<8;i++)
//	lcd_data(a[i]);

	lcd_cmd(0x48);
	for(i=0;i<8;i++)
	lcd_data(b[i]);
}

