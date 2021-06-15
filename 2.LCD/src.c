#include<lpc21xx.h>
#include"lcdheader.h"

int main()
{
 lcd_config();	//use always
 //lcd_data('A');
 lcd_int(123456890);
 lcd_cmd(0xc0); //nwline
 lcd_str("LCD is Running");
}

