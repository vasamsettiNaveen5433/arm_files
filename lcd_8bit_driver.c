#include"header.h"
void lcd_data(unsigned char data)
{
IOCLR0=0X7FF;
IOSET0=data;
IOSET0=1<<8;
IOCLR0=1<<9;
IOSET0=1<<10;
delay_ms(2);
IOCLR0=1<<10;
}
void lcd_cmd(unsigned char cmd)
{
 IOCLR0=0X7FF;
IOSET0=cmd;
IOCLR0=1<<8;
IOCLR0=1<<9;
IOSET0=1<<10;
delay_ms(2);
IOCLR0=1<<10;
}
void lcd_init()
{
 IODIR0=0X7FF;
 IOCLR0=1<<10;
 lcd_cmd(0x38);
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




