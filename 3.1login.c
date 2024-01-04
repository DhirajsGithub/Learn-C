#include <stdio.h>
#include <stdbool.h>

int main()
{
    // logic operators
    bool p = true;
    bool q = false;
    if (p && q)
    {
        printf("p and q are true\n");
    }
    else if (p || q)
    {
        printf("p or q is true\n");
    }
    else if (!p)
    {
        printf("p is false\n");
    }
    else
    {
        printf("something else \n");
    }

    // one line if statement
    int a = 5;
    int b = 6;
    if (a > b)
        printf("a is greater than b\n");

    // switch statemenet
    int menuChoice = 2;
    switch (menuChoice)
    {
    case 1:
    case 2:
    case 3:
        printf("You chose 1 2 and 3\n");
        break;
    case 4:
        printf("You chose 4\n");
        break;
    default:
        printf("You chose something else\n");
        break;
    }

    // conditional operator
    int x = 5;
    int y = 6;
    int z = x > y ? x : y;
    printf("z is %d\n", z);
}