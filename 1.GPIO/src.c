#include<lpc21xx.h>
void delay(unsigned int);
int main()
{  //basic gpio
/*	IODIR0 = 0x00005500;	//0x0000FF00;  //set direction as o/p using masking
	while(1)
	{
	 IOSET0 = 0x00005500;	//0x0000FF00;   	//reset
	 delay(100);
	 IOCLR0 = 0x00005500;	//0x0000FF00;	//set
	 delay(100);
	}	 */

	//odd evn gpio
/*	IODIR1 = 0x01FE0000;	//0x0000FF00;  //set direction as o/p using masking
	while(1)
	{
	 IOSET1 = 0x01FE0000;	//0x0000FF00;   	//reset
	 delay(300);   //controller needs more delay
	 IOCLR1 = 0x01FE0000;	//0x0000FF00;	//set
	 delay(300);
	}  */

   //led prgrm
/*	IODIR1 = 0x01FE0000;	//0x0000FF00;  //set direction as o/p using masking
	while(1)
	{
	int i;
	for(i=17; i<=24; i++)
	{
	 IOSET1 = (1<<i);	//0x0000FF00;   	//reset
	 delay(300);   //controller needs more delay
	 IOCLR1 =  (1<<i);
	 delay(300);
	}
	for(i=24; i>=17; i--)
	{
	 IOSET1 = (1<<i);	//0x0000FF00;   	//reset
	 delay(300);   //controller needs more delay
	 IOCLR1 =  (1<<i);
	 delay(300);
	}
	}		*/

   //led prgrm pattern
	IODIR1 = 0x01FE0000;	//0x0000FF00;  //set direction as o/p using masking
	while(1)
	{
	int i;
	int ar[] = {0x81,0x42,0x24,0x18,0x24,0x42,0x81};
	for(i=0; i<7; i++)
	{
	 IOSET1 = (ar[i]<<17);	//0x0000FF00;   	//reset
	 delay(300);   //controller needs more delay
	 IOCLR1 = (ar[i]<<17);
	 delay(300);
	}
	}


}

void delay(unsigned int a)	 //delay(100)*6000
{
 int i, j;
 for(i=0;i<=a;i++)
  for(j=0;j<6000;j++);
 } 