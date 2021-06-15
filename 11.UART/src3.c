//FULL DUPLEX(RX+TX) UART
#include <lpc21xx.h>
#include"lcdheader.h"
int main()
{
 unsigned char val;
 lcd_config();	//use always
//TX pin select mode
  PINSEL0 |= (1<<0);
  PINSEL0 &= ~(1<<1);
//RX pin select mode
  PINSEL0 |= (1<<2);
  PINSEL0 &= ~(1<<3);

//CONFIG BAUDRATE @9600
U0LCR |= (1<<7);//Enable DLAB BIT 7th bit
U0DLM = 00;//Load values
U0DLL = 97;
U0LCR &= ~(1<<7);//Disable

//CONFIG UART in 8bit mode, 1 start & stop bit, no parity
//[0 0 0 0 0 0 1 1]--->LCR
U0LCR = (1<<0)|(1<<1);

//ACTUAL RECEPTION
	while(1)
	{
	 //Check if THR empty or not, use polling statement
	 while(!(U0LSR&(1<<0))); //do nothing wait, check RBR empty or not
	 val = U0RBR; //Load Data to be received
	 lcd_data(val);

//ACTUAL TRANSMISSION
	 //Check if THR empty or not, use polling statement
	 while(!(U0LSR&(1<<5))); //do nothing wait
	 U0THR = val; //Load Data to be transmitted
	}
}


