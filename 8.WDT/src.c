#include <LPC21xx.H>

void delay(unsigned int a);
void buzzr(void);
void led_tgl(unsigned int);

int main()
{
  IODIR0 = (1<<11);
  IODIR1 = (1<<17);
//to indicate that WDT caused a reset
  buzzr();
  led_tgl(24);
//WDT config
  WDMOD = (1<<1)|(1<<0); //Enable WDT Clear Counter
  WDTC = 0x1FFFFFF; //Load the Timeout value ~9sec
  WDFEED = 0xAA; //Trigger WDT to latch the abv value
  WDFEED = 0x55;
//CPU loop,   
  while(1)
  {
   led_tgl(17);
  }
}


void buzzr(void)
{
 IOSET0 = (1<<11);
 delay(100);
 IOCLR0 = (1<<11);
 delay(100);
}

void led_tgl(unsigned int p)
{
 IOSET1 = (1<<p);
 delay(100);
 IOCLR1 = (1<<p);
 delay(100);
}


void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++);
}