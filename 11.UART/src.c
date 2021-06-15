//TX PROGRAM
#include <lpc21xx.h>

int main()
{
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

//ACTUAL TRANSMISSION
	while(1)
	{
	 //Check if THR empty or not, use polling statement
	 while(!(U0LSR&(1<<5))); //do nothing wait
	 U0THR = 'G'; //Load Data to be transmitted
	}
}


