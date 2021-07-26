#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int snakeWaterGun(char you, char comp)
{
    // cases when game will result in draw
    //ss
    //ww
    //gg
    if (you == comp)
    {
        return 0;
    }
    // cases when there won't be draw
    //sg
    //wg
    //sw
    if (you == 's' && comp == 'w')
    {
        return 1;
    }
    else if (you == 'w' && comp == 's')
    {
        return -1;
    }
    else if (you == 'w' && comp == 'g')
    {
        return 1;
    }
    else if(you == 'g' && comp == 'w')
    {
        return -1;
    }
    else if (you == 'g' && comp == 's')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
char gen()
{
    int number;
    char comp;
    srand(time(0)); // time 0 returns time in seconds and gives new value every time we run the program
    number = rand() % 100 + 1;

    if (number < 33)
    {
        comp = 's';
    }
    else if (number > 33 && number < 66)
    {
        comp = 'w';
    }
    else
    {
        comp = 'g';
    }
    return comp;
}

int main()
{
    char you, comp, ch = 'Y';
    int a;
    int ctr = 0;
    int myscore=0;
    int compscore=0;

    while (ch == 'Y')
    {
        if (ctr == 0)
        {
            comp=gen();
            printf(" COMPUTER CHOOSE %c \n",comp);
            printf("Choose s for Snake, w for water, g for gun \n");
            scanf("%c", &you);
            int result = snakeWaterGun(you, comp);
            if (result == 0)
            {
                printf("IT IS A DRAW \n");
                myscore+=1;
                compscore+=1;
            }
            else if (result== 1)
            {
                printf("CONGRATULATIONS! YOU WON. \n");
                myscore+=1;
            }
            else
            {
                printf("SAD! YOU LOST.\n");
                compscore+=1;
            }
        }
        else if (ctr > 0)
        {
            printf("Wanna Play again?-Y(1)/N(0) \n");
            scanf("%d", &a);
            if (a == 1)
            {
                comp=gen();
                printf(" COMPUTER CHOOSE %c \n",comp);

                printf("Choose s for Snake, w for water, g for gun \n");
                scanf(" %c", &you);
                int result = snakeWaterGun(you, comp);
                if (result == 0)
                {
                    printf("IT IS A DRAW \n");
                    myscore+=1;
                    compscore+=1;
                }
                else if (result == 1)
                {
                    printf("CONGRATULATIONS! YOU WON. \n");
                    myscore+=1;
                }
                else
                {
                    printf("SAD! YOU LOST. \n");
                    compscore+=1;
                }
            }
            else if (a == 0)
            {
                ch = 'N';
                printf("FINAL SCORES ARE: \n");
                printf("COMPUTER'S SCORE %d \n",compscore);
                printf("YOUR SCORE %d \n ",myscore);
                if (myscore>compscore){
                    printf("YOU WON THE OVERALL GAME \n ");
                }
                else if (compscore>myscore){
                    printf("YOU LOST THE OVERALL GAME \n");
                }
                else{
                    printf("OVERALL GAME RESULTED IN A DRAW \n");
                    }
                printf("Thanks for playing");
                } 
            }
              ctr = ctr + 1;
        }
        return 0;      
    }


    