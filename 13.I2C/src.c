//I2C Master write prgrm, EEPROM has no register to generate ACK, So use polling condition
#include<lpc21xx.h>
#include"lcdheader.h"
void i2c_config(void);
void i2c_start(void);
void i2c_data(unsigned char);
void i2c_stop(void);

int main()
{
 lcd_config();
 i2c_config();

 lcd_str("MASTER WRITE");
//START : SLAVE ADDR : R/W : ACK : DATA : ACK : DATA...: STOP
 i2c_start();
//slv addr with R/W, write mode: 1010 000 0--->0xA0, WRITE MODE
 i2c_data(0xA0);
 i2c_data(0x00); //write data in EEPROM frm addr 0
//actual data
lcd_cmd(0xc0); //nwline
 i2c_data('A');	lcd_data('A');
 i2c_data('B');	lcd_data('B');
 i2c_data('C'); lcd_data('C');

 i2c_stop();	
}

void i2c_config(void)
{
//config P0.2:SCL BIT 4 5:0 1, P0.3:SDA BIT 6 7:0 1 
PINSEL0 |= (1<<4)|(1<<6);
PINSEL0 &= ~((1<<5)|(1<<7));
//set clk for FREQ 100Khz
I2SCLL = 75;
I2SCLH = 75;
I2CONSET = (1<<6); //Enable I2C , intrpt flag of i2c sets so clr it nxt time
}

void i2c_start(void)
{
 I2CONCLR = (1<<3); //clr I2C intrpt flag
 I2CONSET = (1<<5); //Generate START BIT
 while(!(I2CONSET&(1<<3)));//Monitor intrpt flag! wait until set, ACK/POLLING STATEMENT
 I2CONCLR = (1<<3); //clr I2C intrpt flag
 I2CONCLR = (1<<5); //clr start bit flag to avoid repetitive start bit  
}

void i2c_data(unsigned char c)
{
 //Load data in I2C data rgstr
 I2DAT = c;
 while(!(I2CONSET&(1<<3)));//Monitor intrpt flag! wait until set, ACK/POLLING STATEMENT
 I2CONCLR = (1<<3); //clr I2C intrpt flag
}

void i2c_stop(void)
{
 I2CONSET = (1<<4); //Activate STOP bit
}