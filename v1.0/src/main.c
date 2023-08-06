#include<lpc214x.h>
#include<string.h>
#include"timerdelay.h"
#include"lcd.h"
#include"keypad.h"
#define bit(x) (1<<x)
char flag=0;
char pwd[]="3333";
void lock(void);


int main(void)
{
 char key[5];
 int con=0;
 lcd_init();
 lcd_cmd(0x01);
 lcd_string("press # to cha-");
 lcd_cmd(0x01);
 lcd_string("nge password");
 flag=get_key();
 if(flag=='#')
 { 
  lcd_cmd(0x01);
  lcd_string("New pwd : ");
  for(con=0;con<4;con++){
  pwd[con]=get_key();
  lcd_string("*");}
     pwd[con]=0;
   }
	 
	 
  while(1){
 lcd_cmd(0x01);
 lcd_string("password:");
 //lcd_cmd(0xc0);
 for(con=0;con<4;con++){
	 if (IO0PIN & bit(21)) {
          lock();
	 }
  key[con]=get_key();
  lcd_string("*");}
  key[con]=0;
  if(strcmp(key,pwd)!=0)
  {
  lcd_cmd(0x20);
    lcd_cmd(0x01);
  lcd_string("Wrong password");
  }
  else {
		lock();
  }
}

}
void lock(void)
{
 IO0DIR|=bit(19)|bit(20);
 lcd_cmd(0x01);
 lcd_string("lock is opening");
 IO0SET|=bit(19);
 timemdel(50);
 IO0CLR|=bit(19);
 timemdel(100);
 lcd_cmd(0x01);
 lcd_string("lock is closing");
 IO0SET|=bit(20);
 timemdel(50);
 IO0CLR|=bit(20);
}
