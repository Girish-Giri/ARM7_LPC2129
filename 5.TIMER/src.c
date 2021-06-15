#include <lpc21xx.h>
#include"lcdheader.h"

int main()
{
  IODIR1 |= (0XFF<<17);
  //Timer Config
  T0PR = 14;
  T0MR0 = 2000000;
  T0MR1 = 3000000; //3sec DELAY	 use mr1
  T0MCR = (1<<4)|(1<<3)|(1<<0); //rep for MR0 removed //MR0 IN Rep & INTR MODE
  T0TCR = (1<<1); //Clear counter
  T0TCR = (1<<0); //Enable timer

  //Action Part
		while(1)
		{
		 if(T0IR&(1<<0)) //Check Match Condition occured or not
		 {
		 	IOSET1 = (1<<17);
			delay(300);
			IOCLR1 = (1<<17);
			delay(300);	
			T0IR = (1<<0);  //Clr INTR FLAG
		 }

		 if(T0IR&(1<<1)) //Check Match Condition occured or not
		 {
		 	IOSET1 = (1<<18);
			delay(300);
			IOCLR1 = (1<<18);
			delay(300);	
			T0IR = (1<<1);  //Clr INTR FLAG
		 }

		}
}