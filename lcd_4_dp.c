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
void lcd_string(char*p,int i)
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
 }
