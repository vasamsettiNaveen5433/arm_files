#include<lpc21xx.h>
#include"header.h"
main()
{
   int i,z=0,k=0;
   char s[20]="vector";
   lcd_init();
   while(1)
   {
   for(i=0;i<16;i++)
   {

   lcd_cmd(0x80+i);
   lcd_string(s);
   for(z=0;s[z];z++);
   if(i+z>16)
   {
   lcd_cmd(0x80);
   k=
   lcd_string(s+k);
   }
   }
   }
}

