//SPI 16bit MODE
#include<lpc21xx.h>

void spi_data(unsigned int);

int main()
{
 //config 0.4:SCLK, 0.5:MOSI, 0.6:MISO, 0.7:SS(GPIO)
 PINSEL0 |= (1<<8)|(1<<10)|(1<<12);
 PINSEL0 &= ~((1<<9)|(1<<11)|(1<<13)); //8:9, 10:11, 12:13
 IODIR0 = (1<<7); //SS as GPIO

 //config SPI in 16bit mode, CPOL=1, CPHASE=1, Master mode, Data tx frm MSB, no INTr
 S0SPCR = (1<<2)|(1<<3)|(1<<4)|(1<<5); //read registr diag
 //Generate SCLK @1.875Mhz OR 1.9Mhz
 S0SPCCR = 8; //SPI CLK cntrl rgstr

 //SLAVE CONFIG
 //16bit mode, ADDR+DATA, 
 spi_data(0x090F); //0x09 0F Decode rgstr in DECODE MODE
 spi_data(0x0A0F); //0x0A 0F Intesity rgstr with MAX INTNSITY
 spi_data(0x0B03); //0x0B 03 Scan Limit 0 1 2 3
 spi_data(0x0C01); //0x0C 01 Enable Segment module-->1 shutdwn register

//Actual Data in DECODE MODE, O/P Display 4 5 6 7 
 spi_data(0x0104); //0x01 04 ADDR + DATA
 spi_data(0x0205); //0x02 04 ADDR + DATA
 spi_data(0x0306); //0x03 04 ADDR + DATA
 spi_data(0x0407); //0x04 04 ADDR + DATA
}

void spi_data(unsigned int d)
{
 S0SPDR = d; //Load the Data to be transmitted
 IOCLR0 = (1<<7); //Slave Sel low to tx the data
 while(!(S0SPSR&(1<<7))); 
 IOSET0 = (1<<7); //Release (SS line) Slave Sel to High 
}