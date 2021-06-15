//timer0 configed as delay
#include<lpc21xx.h>
void delay(unsigned int);
int main()
{
while(1)
 {
  IODIR1 |= (0XFF<<17);
  IOSET1 = (1<<17);
  delay(1);
  IOCLR1 = (1<<17);
  delay(1);	
 }
}


void delay(unsigned int d)
{
   //Timer Config
  T0PR = 14; //prescal regiter value (it takes 14+1)
  T0MR0 = d*1000000;//2000000;
  T0MCR = (1<<1)|(1<<0); //RESET+INTR MODE
  T0TCR = (1<<1); //Clear counter
  T0TCR = (1<<0); //Enable timer

  //Action Part
		 while(!(T0IR&(1<<0))) //Check Match Condition occured or not
		 {
		 }	 //do nothing
  T0IR = (1<<0);  //Clr INTR FLAG
}