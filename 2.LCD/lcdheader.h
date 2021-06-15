#include <lpc21xx.h>
#define RS (1<<10)
#define RW (1<<12)
#define EN (1<<13)
#define DATA (0XFF<<15)

void delay(unsigned int a);
void lcd_cmd(unsigned char);
void lcd_config(void);
void lcd_data(unsigned char);
void lcd_str(unsigned char *);
void lcd_int(unsigned int);

void delay(unsigned int a)	 //delay(100)*6000
{
 int i, j;
 for(i=0;i<=a;i++)
 for(j=0;j<6000;j++);
} 

void lcd_cmd(unsigned char c)
{
 IOCLR0 = DATA;	 //clr the data lines
 IOSET0 |= (c<<15); //load cmd values to same data line
 IOCLR0 = RS; //RS=0
 IOCLR0 = RW; //RW=0  TO WRITE
 IOSET0 = EN; //EN=1
 delay(15);
 IOCLR0 = EN; //EN=1  
}


void lcd_config(void) //func 1
{
 IODIR0 |= RS|RW|EN|DATA;	//configured as o/p using macros
 lcd_cmd(0x38);
 lcd_cmd(0x0E); 
 lcd_cmd(0x01);
 lcd_cmd(0x80);
}


void lcd_data(unsigned char d)	  //load data in register the transit via EN
{
 IOCLR0 = DATA;	 //clr the data lines
 IOSET0 |= (d<<15); //load cmd values to same data line
 IOSET0 = RS; //RS=1
 IOCLR0 = RW; //RW=0  TO WRITE
 IOSET0 = EN; //EN=1
 delay(15);
 IOCLR0 = EN; //EN=1  
}

void lcd_str(unsigned char *p)
{
 while(*p!='\0')
 {
 lcd_data(*p);
 p++;
 }
}

void lcd_int(unsigned int n)
{
 if(n)
 {
  lcd_int(n/10);
  lcd_data(n%10+0x30);	//0x30=0, pass remainder as data
 }
}