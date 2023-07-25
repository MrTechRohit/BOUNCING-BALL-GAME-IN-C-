//___________WELCOME ALL OF YOU ON ROHIT TECH STUDY CHANNEL________________//
//_______________C++ PROGRAM TO MAKE BOUNCING BALL GAME______________________//


#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main()
{
   Play_Again:
   int gdriver = DETECT, gmode, errorcode;
   int midx,midy,maxx,maxy,ball_x,ball_y,key;
   int speed,bar_upper,bar_lower,gap,score,fail,i;
   int bar_x[3],bar_y[3],color[3],bar_i[3],pattern[3];
   float ball_vlct;
   initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
   fail=0;
   speed=0;
   score=0;
   key=0;
   gap=85;
   ball_vlct=0.80;
   midx=getmaxx()/2;
   midy=getmaxy()/2;
   maxx=getmaxx();
   maxy=getmaxy();
   ball_x=25;
   ball_y=midy;
   bar_upper=5;
   bar_lower=maxy-5;
   bar_x[0]=maxx-10;
   bar_x[1]=bar_x[0]+219;
   bar_x[2]=bar_x[1]+219;
   for(i=0;i<=2;i++)
   {
     bar_y[i]=random(maxy-150);
     color[i]=random(15)+1;
     bar_i[i]=0;
     pattern[i]=random(13);
   }

   do
   {
     if(kbhit())
     {
       if((key=getch())==' '||(key=getch())==' ')
       {
	 ball_vlct=0.6;
	 speed=speed+ball_vlct-50;
       }
     }

     if(fail==1)
     {
      for(i=0;i<=2;i++)
	color[i]=10;
     }

     setcolor(BLACK);
     setfillstyle(1,20);

      //draws ball
     fillellipse(ball_x,ball_y+speed,10,10);
      //draws bar with random color
     for(i=0;i<=2;i++)
     {
     setcolor(color[i]);
       //setfillstyle(pattern[i],color[i]);
   rectangle(bar_x[i]-bar_i[i],bar_y[i]+gap,bar_x[i]+25-bar_i[i],bar_lower);
   rectangle(bar_x[i]-bar_i[i],bar_y[i],bar_x[i]+25-bar_i[i],bar_upper);
   }
     if(fail==1)
     {
       delay(1000);          //exit if fail
       break;
     }

     gotoxy(1,2);
     printf("Score: %d",score);
     for(i=0;i<=2;i++)            //check for fail or not
     {
       if(bar_x[i]-bar_i[i]<=25)
       {
	 if(!(ball_y+speed>=bar_y[i]&&ball_y+speed<=bar_y[i]+85))
	   fail=1;
	 else
	   fail=0;
       }
     }
     //checks for ball doesn't go out of the screen
     if(ball_y+speed>maxy-20)
     {
       ball_vlct=0.0;
       speed=0;
       ball_y=maxy-27;
     }
     if(ball_y+speed<20)
     {
       speed=0;
       ball_y=25;
     }

     //increments the values
     ball_vlct=ball_vlct+0.81;
     speed=speed+ball_vlct;
     for(i=0;i<=2;i++)
       bar_i[i]=bar_i[i]+5;

     for(i=0;i<=2;i++)
     {
     //restart the bar values again
       if(bar_x[i]-bar_i[i]+25<=0)
       {
	 bar_i[i]=0;
	 bar_x[i]=maxx;
	 bar_y[i]=random(maxy-150);
	 color[i]=random(15)+1;
	 pattern[i]=random(13);
	 score++;
       }
     }
     delay(50);
     cleardevice();
   }while(1);
   closegraph();
   clrscr();

   char name[12];
   gotoxy(25,10);
   textcolor(3);
   cprintf("Enter your name:- ");
   gets(name);
   gotoxy(25,11);
   textcolor(RED);
   cputs(name);
   cprintf(" your score is %d",score);
   gotoxy(26,13);
   textcolor(RED+BLINK);
   cprintf("Play Again(y/n)");
   char play=getch();
   if(play=='y')
   {
     goto Play_Again;
   }
   return 0;
}
 //___________________PRESS SPACE KEY TO BOUNCE BALL_______________________//
//--------------------THANKS TO WATCHING THIS VIDEO------------------------//