/*----LCD Header File------*/
#define RS (1<<16)
#define E (1<<17)
#define D4 (1<<10)
#define D5 (1<<11)
#define D6 (1<<12)
#define D7 (1<<13)
//void delay(void);
void lcd_init(void);
void lcd_cmd(int );
void lcd_string(char *str);
void lcd_conv(char );
void lcd_cmd(int cmd)
{
 IOCLR0|=RS;
 lcd_conv(cmd);
 IOCLR0|=RS;
 timeudel(1000);
}
void lcd_init(void)
{
 IODIR0|=D4|D5|D6|D7;
  IODIR0|=RS|E;
  IOCLR0|=D4|D5|D6|D7;
  IOCLR0|=RS|E;
 lcd_cmd(0x02);
 lcd_cmd(0x28);
 lcd_cmd(0x0E);
 lcd_cmd(0x01);
 lcd_cmd(0x06);
}
void lcd_string(char *str)
{
 while(*str!=0)
 {
  IOSET0|=RS;
  lcd_conv(*str);
  str++;
 }
 timeudel(1000);
}
void lcd_conv(char data)
{
 int recv;
 IOCLR0|=D4|D5|D6|D7;
 recv=data>>4;
 IOSET0=recv<<10;
 IOSET0|=E;
 timeudel(1000);
 IOCLR0|=E;
 timeudel(1000);
 IOCLR0|=D4|D5|D6|D7;
 recv=data;
 IOSET0|=(recv<<10);
 IOSET0|=E;
 timeudel(1000);
 IOCLR0|=E;
 IOCLR0|=D4|D5|D6|D7;
}
