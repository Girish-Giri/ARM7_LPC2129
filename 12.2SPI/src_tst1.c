//full custom mode, 8BIT PSIM
#include<lpc21xx.h>
void spi_data(unsigned int);
void delay(unsigned int);

int main()
{
 //config 0.4:SCLK, 0.5:MOSI, 0.6:MISO, 0.7:SS(GPIO)
 PINSEL0 |= (1<<8)|(1<<10)|(1<<12);
 PINSEL0 &= ~((1<<9)|(1<<11)|(1<<13)); //8:9, 10:11, 12:13
 IODIR0 = (1<<7); //SS as GPIO

 //config SPI in //8bit mode, CPOL=1, CPHASE=1, Master mode, Data tx frm MSB, no INTr
 S0SPCR = (1<<3)|(1<<4)|(1<<5); //read registr diag
 //Generate SCLK @1.875Mhz OR 1.9Mhz
 S0SPCCR = 8; //SPI CLK cntrl rgstr, sets freq >=8 even value

 //SLAVE CONFIG
 //8bit mode, ADDR+DATA, 
 spi_data(0x09); //0x09 0F Decode rgstr in DECODE MODE
 spi_data(0x00);//spi_data(0x0F); //no data(custom data) mode 

 spi_data(0x0A); //0x0A 0F Intesity rgstr with MAX INTNSITY
 spi_data(0x0F); 

 spi_data(0x0B); //0x0B 03 Scan Limit 0 1 2 3 4 5 6 7
 spi_data(0x07); 

 spi_data(0x0C); //0x0C 01 Enable Segment module-->1 shutdwn register
 spi_data(0x01);  

 //Actual Data in DECODE MODE, O/P Display PROTOCOL
delay(50); 
 spi_data(0x01); //0x01 04 ADDR + DATA
 spi_data(0x67); //P

delay(50);
 spi_data(0x02); //0x02 05 ADDR + DATA
 spi_data(0x77); //R

delay(50);  
 spi_data(0x03); //0x03 06 ADDR + DATA
 spi_data(0x7E); //O

delay(50);
 spi_data(0x04); //0x04 07 ADDR + DATA
 spi_data(0x46); //T

 delay(50); 
 spi_data(0x05); //0x01 04 ADDR + DATA
 spi_data(0x7E); //O

delay(50);
 spi_data(0x06); //0x02 05 ADDR + DATA
 spi_data(0x4E); //C

delay(50);  
 spi_data(0x07); //0x03 06 ADDR + DATA
 spi_data(0x7E); //O

delay(50);
 spi_data(0x08); //0x04 07 ADDR + DATA
 spi_data(0x0E); //L


}

void spi_data(unsigned int d)
{
 S0SPDR = d; //Load the Data to be transmitted
 IOCLR0 = (1<<7); //Slave Sel low to tx the data
 while(!(S0SPSR&(1<<7))); 
 IOSET0 = (1<<7); //Release (SS line) Slave Sel to High 
}

void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++);
}