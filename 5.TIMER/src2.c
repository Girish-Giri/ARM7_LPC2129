#include <lpc21xx.h>
#include"lcdheader.h"

int main()
{
  IODIR1 |= (0XFF<<17);
  //Timer Config
  T0PR = 14;
  T0MR0 = 2000000;
  T0MR1 = 4000000; //3sec DELAY	 use mr1
  T0MR2 = 6000000;
  T0MR3 = 8000000;
  T0MCR = (1<<10)|(1<<9)|(1<<6)|(1<<3)|(1<<0); //rep for MR0 removed //MR0 IN Rep & INTR MODE
  T0TCR = (1<<1); //Clear counter
  T0TCR = (1<<0); //Enable timer

  //Action Part
		while(1)
		{
		 if(T0IR&(1<<0)) //Check Match Condition occured or not
		 {
		 	IOCLR1 = (1<<20);
		 	IOSET1 = (1<<17);	
			T0IR = (1<<0);  //Clr INTR FLAG
		 }

		 if(T0IR&(1<<1)) //Check Match Condition occured or not
		 {
			IOCLR1 = (1<<17);
		 	IOSET1 = (1<<18);
			T0IR = (1<<1);  //Clr INTR FLAG
		 }


		 if(T0IR&(1<<2)) //Check Match Condition occured or not
		 {
			IOCLR1 = (1<<18);
		 	IOSET1 = (1<<19);
			T0IR = (1<<2);  //Clr INTR FLAG
		 }


		 if(T0IR&(1<<3)) //Check Match Condition occured or not
		 {
			IOCLR1 = (1<<19);
		 	IOSET1 = (1<<20);
			T0IR = (1<<3);  //Clr INTR FLAG
		 }

		}
}