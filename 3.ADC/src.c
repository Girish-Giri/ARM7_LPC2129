//TEMP SENSOR
#include <lpc21xx.h>
#include"lcdheader.h"

//make 2 separate funcs for temp and pot call each with delay

int main()
{
int val;
lcd_config();
//analog mode, pin0.27, bits 25,24 = 0,1 
PINSEL1 |= (1<<24);		  //24 = 1
PINSEL1 &= ~(1<<25);	  //25 = 0

//analog mode, pin0.28, bits 23,22 = 0,1 
PINSEL1 |= (1<<22);	
PINSEL1 &= ~(1<<23);

//ADC config chl=1, CLK DIV=4, BRST MODE=1, PDN1   
ADCR |= (1<<1)|(1<<0)|(4<<8)|(1<<16)|(1<<21);	  //ORing IS Padding!, dont OR ADCR to avoid chnl flicker
while(1)
 {
   while(!(ADDR&(1<<31)));	//while done bit not = 0
   {
   }
   val = (ADDR&(0X3FF<<6));
   lcd_int((val>>6)/3.3);	//raw to actual value
   delay(100);
 }
}

