#include<LPC21xx.h>
#include<string.h>
typedef unsigned char u8;		 1
typedef  char s8;
typedef unsigned int u32;
#define SW1 (IOPIN0>>14&1) 


extern void uart0_init(unsigned int);
extern void uart0_tx(unsigned char);
extern void delay_sec(unsigned int);
extern void delay_ms(unsigned int);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(u8*);
extern void uart0_tx_integer(int);
extern void uart0_tx_float(float );
extern 	void uart0_rx_string(u8*,u8);
extern void uart1_rx_string(u8*,u8);
extern void uart0_rx_string_password(u8*,u8);

extern void lcd_init(void);
extern void lcd_cmd(u8);
extern void lcd_data(u8);
extern void lcd_integer(int);

extern void adc_init(void);
extern u32 adc_read(u8 );

void config_vic_for_eint0(void);
void config_eint0(void);


// spi0

extern void spi0_init(void);
extern u8 spio(u8);
extern u32 mcp3204_read(u8);


extern void i2c_byte_write_frame(u8 ,u8 ,u8);
extern u8 i2c_byte_read_frame(u8 ,u8);
extern void i2c_init(void);
