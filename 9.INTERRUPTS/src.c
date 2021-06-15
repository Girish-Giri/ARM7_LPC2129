/*Generate an Interrupt from timer0 for every 5 sec,
Toggle LED P1.24 in ISR part,
Toggle LED P1.17 in the main program or 
as CPU Functionality*/

#include<lpc21xx.h>
void timer_config(void);
void intr_config(void);
void timer_isr(void)__irq;
void delay(unsigned int a);
int main()
{
IODIR1=(0XFF<<17);	     // COnfig LED Por Pins a OP Port
timer_config();
intr_config();

	while(1)			 // Toggle P1.17 LED as a CPU functionality
	{
	IOSET1=(1<<17);			 
	delay(300);
	IOCLR1=(1<<17);
	delay(300);
	}
}

void timer_config(void)	    // TImer Configuration for 5 sec 
{
T0PR=14;
T0MR0=5000000;
T0MCR=(1<<1)|(1<<0);
T0TCR=(1<<1);
T0TCR=(1<<0);
}

void intr_config(void)		    // Interrupt Configuration with slot 0
{
VICIntSelect&=~(1<<4);    		// Select IRQ mode with timer0 as a source--->4
VICVectCntl0=(1<<5)|(4<<0);    // use SLot 0	and control info.GIE, and SRC no
VICVectAddr0=(long)timer_isr;  // Load the ISR address to VIC Addre Reg
VICIntEnable=(1<<4);           // Enable Int
}

void timer_isr(void)__irq     // Std way of defining ISR
{
	IOSET1=(1<<24);			 // Toggle P1.24 LED
	delay(500);
	IOCLR1=(1<<24);
	delay(500);
	T0IR=(1<<0);     // Clear the Int flag
	VICVectAddr=0;  // std return address
}

void delay(unsigned int a)	  // 100*6000   
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<6000;j++);
}