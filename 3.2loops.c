#include <stdio.h>
#include <stdbool.h>

int main()
{

    // game
    int num;
    int ans = 69;
    do
    {
        printf("guess number between 1 and 100\n");
        scanf("%d", &num);
        if (num > ans)
        {
            printf("too high\n");
        }
        else if (num < ans)
        {
            printf("too low\n");
        }
        else
        {
            printf("you got it\n");
        }
    } while (num != ans);

    // loops
    // while loop
    int i = 0;
    while (i < 10)
    {
        printf("i is %d\n", i);
        i++;
    }

    // do while loop
    int j = 0;
    do
    {
        printf("j is %d\n", j);
        j++;
    } while (j < 10);

    // for loop
    for (int k = 0; k < 10; k++)
    {
        printf("k is %d\n", k);
    }

    // break and continue
    for (int l = 0; l < 10; l++)
    {
        if (l == 5)
        {
            continue;
        }
        printf("l is %d\n", l);
    }

    for (int m = 0; m < 10; m++)
    {
        if (m == 5)
        {
            break;
        }
        printf("m is %d\n", m);
    }

    // nested loops
    for (int n = 0; n < 10; n++)
    {
        for (int o = 0; o < 10; o++)
        {
            printf("n is %d and o is %d\n", n, o);
        }
    }

    // infinite loop
    for (;;)
    {
        printf("infinite loop\n");
        break;
    }

    return 0;
}