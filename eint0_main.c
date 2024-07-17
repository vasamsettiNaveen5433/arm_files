#include"header.h"
#define LED (1<<17)
extern u32 count;
main()
{
  config_vic_for_eint0();
  config_eint0();
  while(1)
  {
   IOCLR0=LED;
   delay_ms(100);
   IOSET0=LED;
   delay_ms(100);
  }
}
