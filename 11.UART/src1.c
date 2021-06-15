#include <lpc21xx.h>
void write(char data);
void Send_String(char*);
void delay(unsigned int a);

char arr[]="Cranes Varsity\n";

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


  while(1)    
  {        
    Send_String(arr);
	delay(1000);    
  }
}



void write(char data)
{
  while (!(U0LSR & (1<<5))); // wait till the THR is empty
  U0THR = data;
}


void Send_String(char* ptr){
 
 while(*ptr != 0x00)
 {
 write(*ptr);
 ptr++;
 }
}

void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++);
}



