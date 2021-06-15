#include <lpc21xx.h>
#include"tmrhdr.h"

int main()
{
  IODIR1 |= (0XFF<<17);
  	while(1)
		{
		IOSET1 = (1<<17);
		delay(3000);
		IOCLR1 = (1<<17);
		delay(3000);
		}
}	