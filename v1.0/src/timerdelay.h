/*----Timerdelay Header File------*/
void timemdel(unsigned int con)
{
 T0CTCR=0X0;
 T0PR=59999;
 T0MR0=con;
 T0MCR|=1<<2;
 T0TCR=0X02;
 T0TCR=0X01;
 while(T0TC!=T0MR0);
 T0TC=0;
 T0TCR=0;
}
void timeudel(unsigned int con)
{
 T1CTCR=0X0;
 T1PR=59;
 T1MR0=con;
 T1MCR|=1<<2;
 T1TCR=0X02;
 T1TCR=0X01;
 while(T1TC!=T1MR0);
 T1TC=0;
 T1TCR=0;
}
