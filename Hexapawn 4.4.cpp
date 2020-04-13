#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int i,j,i1,j1,k,h,flag=1,z,x=0,y=0,m,b=1;
int a[4][4],var,countw=4,countb=4,one=0,two=0;

void disp()
{
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void white()
{

    printf("Player 1's Turn\n");
        printf("Enter the current location of the pawn you want to move:\n");
        scanf("%d %d",&i,&j);
        var=a[i][j];
        if(var==1)
        {
        printf("%d\n",a[i][j]);
        printf("Enter the destination location:\n");
        scanf("%d %d",&i1,&j1);
        h=j;

        if((a[i1][j1]==0)&&(j==j1)&&(i-i1==1||i1-i==1))
        {
            a[i1][j1]=var;
            a[i][j]=0;
            disp();

        }
        else if(a[i1][j1]!=0&&(j-j1==1||j-j1==-1)&&(i-i1==1||i1-i==1))
            {

                a[i1][j1]=var;
                a[i][j]=0;
                disp();
                countb--;

            }
        else
        {
            disp();
            printf("Invalid move\n");
            white();
        }
        }
        else
        {
            printf("Thats not a Player 1 pawn\n");
            white();
        }

        if(a[3][0] == 1 || a[3][1] == 1 || a[3][2] == 1||a[3][3]==1)
        {
			printf("player1 wins..\n");
            b=0;
			one++;

        }
}
void black()
{
        printf("Player 2's Turn\n");
        printf("Enter the current location of the pawn you want to move:\n");
        scanf("%d %d",&i,&j);
        var=a[i][j];
        if(var==2)
        {
        printf("%d\n",a[i][j]);
        printf("Enter the destination location:\n");
        scanf("%d %d",&i1,&j1);
        h=j;
        if(a[i1][j1]==0&&j==j1&&(i-i1==1||i1-i==1))
        {

            a[i1][j1]=var;
            a[i][j]=0;
            disp();
        }
        else if(a[i1][j1]!=0&&(j-j1==1||j-j1==-1)&&(i-i1==1||i1-i==1))
            {

                a[i1][j1]=var;
                a[i][j]=0;
                disp();
                countw--;
            }
        else
        {
            disp();
            printf("Invalid move\n");
            black();
        }

        }
        else
        {
            printf("Thats not a Player 2 pawn\n");
            black();
        }

        if(a[0][0] == 2 || a[0][1] == 2 || a[0][2] == 2||a[0][3]==2)
        {
			printf("Player 2 wins..\n");
            b=0;
			two++;


        }
}
countwhite()
{
    x=0;
    for(z=0;z<=3;z++)
    {
        if((a[0][z]==1&&a[1][z]==2)||(a[1][z]==1&&a[2][z]==2)||(a[2][z]==1&&a[3][z]==2))
        {
            x++;
        }
    }
}
countblack()
{
    y=0;
    for(z=0;z<=3;z++)
    {
        if((a[0][z]==1&&a[1][z]==2)||(a[1][z]==1&&a[2][z]==2)||(a[2][z]==1&&a[3][z]==2))
        {
            y++;
        }
    }
}
int main()
{
    do
    {
        flag=1;
        x=0;
        y=0;
        countw=4;
        countb=4;
        b=1;


    a[0][0]=1;
    a[0][1]=1;
    a[0][2]=1;
    a[0][3]=1;
    a[3][0]=2;
    a[3][1]=2;
    a[3][2]=2;
    a[3][3]=2;
    a[1][0]=a[1][1]=a[1][2]=a[1][3]=a[2][0]=a[2][1]=a[2][2]=a[2][3]=0;

    disp();
    while(1)
    {
        if(x==countw)
        {
            printf("Player 2 wins.\n");
            b=0;
			two++;
			break;
        }
        else
            if(b)
            {
            white();
            }
        else
            break;
        countblack();
        if(y==countb)
        {
            printf("Player 1 wins.\n");
            b=0;
			one++;
			break;

        }
        else
            if(b)
            {
            black();
            }
        else
            break;

        countwhite();
    }
v:
    printf("player1=%d\n",one);
    printf("player2=%d\n",two);
    printf("press 1 to play again (0 to exit)");
    scanf("%d",&m);
    }while(m);

    return 0;
}
