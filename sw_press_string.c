#include"header.h"
#define SW1 (IOPIN0>>14&1)
extern u32 flag;
main()
{
   u32 count=0;
  char*p="vector";
  
  config_vic_for_eint0();
  config_eint0();
  uart0_init(9600);
  
  //uart0_tx('A'); 

  while(1)
  {
    if(flag==1)
	{
	 uart0_tx(*p);
	 p++;
	 flag=0;
	 if(*(p)=='\0')
	 {	
	    VICIntEnClr|=(1<<14);
	  //VICVectCntl0=0;
	  //VICIntEnable^=(1<<14);
	  VICIntEnClr=1;

	  }
	// count++;
	 //uart0_tx_integer(count);
	}
    
  }
}
