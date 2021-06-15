#include <lpc21xx.h>
void delay(unsigned int a);

int main()
{
 //PWM CH4 P0.8
 PINSEL0 |= (1<<17);   //P0.8 as PWM pin 17:6 1:0
 PINSEL0 &= ~(0<<16); //P0.8 as PWM pin

 //PWM CONFIG
 PWMPR = 14;	//PRESCALAR
 PWMMR0 = 10000; //TOTAL TIME
 PWMLER = (1<<0); //Enable PWMMRO values
 PWMMCR = (1<<1); //PWMMR0 in repeat R mode 010
 PWMPCR &= ~(1<<4);	//CH4 & single edge PWM	Bit4=0
 PWMPCR = (1<<12); //Enable PWM CH4 O/P	  Bit12=1
 PWMTCR = (1<<3)|(1<<0); //Enable PWM ckt, clr counters

 //ACTION PART
 while(1)
 {
  PWMMR4 = 2500; //25% DUTY CYCLE
  PWMLER = (1<<4);
  delay(1000);

  PWMMR4 = 5000; //50% DUTY CYCLE
  PWMLER = (1<<4);
  delay(1000);

  PWMMR4 = 7500; //75% DUTY CYCLE
  PWMLER = (1<<4);
  delay(1000);

  PWMMR4 = 10000; //100% DUTY CYCLE
  PWMLER = (1<<4);
  delay(1000);
 }
}

void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<6000;j++);
}