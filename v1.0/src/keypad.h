/*----Keypad Header File------*/
#define c1 (1<<20)
#define c2 (1<<21)
#define c3 (1<<22)
#define r1 (1<<16)
#define r2 (1<<17)
#define r3 (1<<18)
#define r4 (1<<19)

char get_key(void)
{
 IO1DIR=0x0f<<16;
  IO1CLR|=0xFF<<16;
 IO1SET|=0xFF<<16;
 while(1)
 {
   IO1CLR|=r1;
  IO1SET|=0x0E<16;
   if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '1';
   }
   else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '2';
   }
   else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '3';
   }
    IO1CLR|=r2;
  IO1SET|=0x0D<<16;
    if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '4';
   }
  else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '5';
   }
  else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '6';
   }
   IO1CLR|=r3;
  IO1SET|=0X0B<<16;
    if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '7';
   }
  else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '8';
   }
  else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '9';
   }
  IO1CLR|=r4;
   IO1SET|=0X07<<16;
       if((IO1PIN&c1)==0)
   {
     while((IO1PIN&c1)==0);
  return '*';
   }
  else if((IO1PIN&c2)==0)
   {
     while((IO1PIN&c2)==0);
  return '0';
   }
  else if((IO1PIN&c3)==0)
   {
     while((IO1PIN&c3)==0);
  return '#';
   }
 }
}
