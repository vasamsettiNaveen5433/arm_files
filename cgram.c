#include"header.h"
main()
{
 lcd_init();
 lcd_cgram();
 lcd_cmd(0x80);
 lcd_string("Naveen");
 lcd_cmd(0X87);
 lcd_data(1);
// lcd_cmd(0X8);
// lcd_string("v23be8v5");
 //lcd_data(1);
 while(1);

 
}

//void lcd_cgram(void)
//{
//    unsigned char a[]={0x0,0xA,0xA,0x0,0x0,0x11,0xE,0x0};
//	int i;
//	lcd_cmd(0x40);
//	for(i=0;i<8;i++)
//	lcd_data(a[i]);
//}
