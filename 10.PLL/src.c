//always select target option and check mark o/p-hex, linker-use memry layout
#include<lpc21xx.h>
void delay(unsigned int a);
void pll_36mhz(void);
int main()
{
 unsigned int count = 0;
 VPBDIV = 2; // pclk=cclk/2
 IODIR1 = (0XFF<<17);

 while(1)				  //initialy cpu-clk cclk=60Mhz so, pclk=30Mhz
 {
  IOSET1=(0xFF<<17);
  delay(250);
  IOCLR1=(0xFF<<17);
  delay(250);

  if(count==5)	  //count=5, config CCLK to 36Mhz so, Pclk=18Mhz
  {
  pll_36mhz(); //using PLL
  }
  count++;
 }
}

void pll_36mhz(void)
{			 
  //M=3, P=4 (btwn 2.1-4.4)
  PLLCFG = (1<<6)|(1<<1); //
  PLLCON = (1<<0);	//Enable PLL
  PLLFEED = 0xAA;  //Feed Signal latches/triggers/activates P & M values
  PLLFEED = 0x55;

  while(!(PLLSTAT&(1<<10)));//Check PLL Locked or not, use Polling statement

  PLLCON = (1<<1)|(1<<0);	//Connect PLL to CPU and Enable PLL
  PLLFEED = 0xAA;  //Feed Signal latches/triggers/activates P & M values
  PLLFEED = 0x55;

}

void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++);
}