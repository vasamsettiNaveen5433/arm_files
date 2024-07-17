#include"header.h"

#define CS0 (1<<7)
u32 mcp3204_read(u8 ch_num)
{
  u32 result=0;
  u8 byteH=0,byteL=0;
  ch_num<<=6;
  IOCLR0=CS0;
  spio(0x06);
  byteH=spio(ch_num);
  byteL=spio(0x00);
  IOSET0=CS0;
  byteH&=0x0F;
  result=(byteH<<8)|(byteL);

  return result;
}

