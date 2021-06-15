#include <lpc21xx.h>
#include"lcdheader.h"

#define ROW (0x0F<<21)
#define COL (0x0F<<17)

void row_scan(void);
void colmn_scan1(void);	
void colmn_scan2(void);
void colmn_scan3(void);
void colmn_scan4(void);	

int main()
{
 lcd_config();
 while(1)
 {
  row_scan();
 }
}

void row_scan(void)
{
 int val;
 IODIR1 |= COL; //Col as o/p
 IODIR1 &= ~(ROW);//Row as i/p to read
 val = (IOPIN1 & ROW); //extract bit status
 val = val>>21;
 switch(val)
 {
 	case 0x0E: //lcd_str("ROW 1 ");	//0x0E=1110
		       colmn_scan1();		
			   break;
 	case 0x0D: //lcd_str("ROW 2 ");
		       colmn_scan2();		
			   break;
 	case 0x0B: //lcd_str("ROW 3 ");
		       colmn_scan3();		
			   break;
 	case 0x07: //lcd_str("ROW 4 ");
		       colmn_scan4();		
			   break;
	default:   lcd_cmd(0x01);
			   delay(1000);
 }
}  

void colmn_scan1(void)
{
 int val;
 IODIR1 |= ROW; //Col as o/p
 IODIR1 &= ~(COL);//Row as i/p to read
 val = (IOPIN1 & COL); //extract bit status
 val = val>>17;
 switch(val)
 {
 	case 0x0E: lcd_str("0");		//0x0E=1110
			   delay(1000);
			   break;
 	case 0x0D: lcd_str("1");
			   delay(1000);
			   break;
 	case 0x0B: lcd_str("2");
			   delay(1000);
			   break;
 	case 0x07: lcd_str("3");
			   delay(1000);
			   break;
	default:   lcd_cmd(0x01);
			   delay(1000);
 }
}


void colmn_scan2(void)
{
 int val;
 IODIR1 |= ROW; //Col as o/p
 IODIR1 &= ~(COL);//Row as i/p to read
 val = (IOPIN1 & COL); //extract bit status
 val = val>>17;
 switch(val)
 {
 	case 0x0E: lcd_str("4");		//0x0E=1110
			   delay(1000);
			   break;
 	case 0x0D: lcd_str("5");
			   delay(1000);
			   break;
 	case 0x0B: lcd_str("6");
			   delay(1000);
			   break;
 	case 0x07: lcd_str("7");
			   delay(1000);
			   break;
	default:   lcd_cmd(0x01);
			   delay(1000);
 }
}

void colmn_scan3(void)
{
 int val;
 IODIR1 |= ROW; //Col as o/p
 IODIR1 &= ~(COL);//Row as i/p to read
 val = (IOPIN1 & COL); //extract bit status
 val = val>>17;
 switch(val)
 {
 	case 0x0E: lcd_str("8");		//0x0E=1110
			   delay(1000);
			   break;
 	case 0x0D: lcd_str("9");
			   delay(1000);
			   break;
 	case 0x0B: lcd_str("A");
			   delay(1000);
			   break;
 	case 0x07: lcd_str("B");
			   delay(1000);
			   break;
	default:   lcd_cmd(0x01);
			   delay(1000);
 }
}

void colmn_scan4(void)
{
 int val;
 IODIR1 |= ROW; //Col as o/p
 IODIR1 &= ~(COL);//Row as i/p to read
 val = (IOPIN1 & COL); //extract bit status
 val = val>>17;
 switch(val)
 {
 	case 0x0E: lcd_str("C");		//0x0E=1110
			   delay(1000);
			   break;
 	case 0x0D: lcd_str("D");
			   delay(1000);
			   break;
 	case 0x0B: lcd_str("E");
			   delay(1000);
			   break;
 	case 0x07: lcd_str("F");
			   delay(1000);
			   break;
	default:   lcd_cmd(0x01);
			   delay(1000);
 }
}