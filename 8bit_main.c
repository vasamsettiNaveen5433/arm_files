#include"header.h"
main()
{
   int i,j=0;
   char s[20]="VECTOR";
   for(j=0;s[j];j++);
   lcd_init();
   while(1)
   {
     for(i=0;i<16;i++)
	 {
	  lcd_cmd(0x80+i);
	  lcd_string(s);
	  if(i>16-j)
	  {
		  lcd_cmd(0x80);
		  lcd_string(s+(16-i));
	  }
	 
	  delay_ms(500);
	  lcd_cmd(0x01);
	 }

   }


}  
 
 
 /*  for(i=0;i<26;i++)
   {
   lcd_cmd(0x80);
   lcd_data('A'+i);
   delay_ms(500);
   }  */
     



