#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
int height=20,width=20,x,y,fruitX,fruitY,flag;
int gameover,score;

//function for the logic behind
//each movement
void makelogic()
{
    sleep(0.01);
    switch(flag)
    {
        case 1:
        {
            x--;
            break;
        }
        case 2:
        {
            x++;
            break;
        }
        case 3:
        {
            y--;
            break;
        }
        case 4:
        {
            y++;
            break;

        }
        default:
            break;
    }
    //if the game is over
    if(x<0 || x>height || y<0 || y>width)
        gameover=1;

    //if snake reach the fruit then update the score
    if(x== fruitX && y== fruitY)
    {
      level3:
        fruitX=rand()%20;
        if(fruitX==0)
        goto level3;

  level4:
       fruitY=rand()%20;
       if(fruitY==0)
       goto level4;
       score +=10;

    }


}

//function to take input
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
          case 'w':
          {
              flag=1;
              break;
          }
          case 's':
          {
              flag=2;
              break;
          }
          case 'a':
          {
              flag=3;
              break;
          }
          case 'd':
          {
              flag=4;
              break;
          }
        }
    }
}


//function to generate the fruit
//within the boundary
void setup()
{
 gameover = 0;

 x=height/2;
 y=width/2;

 level1:
    fruitX=rand()%20;
    if(fruitX==0)
    goto level1;

 level2:
    fruitY=rand()%20;
    if(fruitY==0)
    goto level2;
 score = 0;

}

//function to draw the boundaries
void draw()
{
   system("cls");
   int i,j;
   for(i=0;i<=height;i++)
   {
    for(j=0;j<=width;j++)
   {
       if(i==0 || i== height || j==0 || j==width)
       {
         printf("*");
       }
       else
       {
           if(i==x && j==y)
           {
               printf("0");
           }
           else if(i==fruitX && j==fruitY)
           {
               printf("@");
           }
           else
           {
               printf(" ");
           }

       }
   }
   printf("\n");
   }

  //print the score after the game end
  printf("Score = %d\n",score);
  printf("Press X to quit the game");


   }



int main()
{
    setup();
   //until the game is over
   while(!gameover)
   {
     draw();
     input();
     makelogic();

   }

}
