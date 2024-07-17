#include"header.h"
#define  CS0 (1<<7) 

void spi0_init(void)
{
  PINSEL0|=0x1500;
  IODIR0|=CS0;
  IOSET0=CS0;
  S0SPCR=0X20;
  S0SPCCR=15;
}

#define SPIF ((S0SPSR>>7)&1)

u8 spio(u8 data)
{
  S0SPDR=data;
  while(SPIF==0);
  return S0SPDR;
}
