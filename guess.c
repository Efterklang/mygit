#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int number=rand()%100+1;
    int count=0;
    int guess=0;
    do
    {
        printf("guess a number:");
        scanf("%d",&guess);
        if (guess > number)
        {printf("too big\n");}
        else if (guess < number)
        {printf("too small\n");}
    } while (guess != number);
    printf("you guess right");

}