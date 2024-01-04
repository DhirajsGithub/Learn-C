#include <stdio.h>
#include "6.2libraries.h"

/*
how to compile and run this file
gcc -c 6.2libraries.c
gcc -c 6.2libraries-main.c
// above commands will create two object files 6.2libraries.o and 6.2libraries-main.o
// object files are the compiled version of the source code
// now we need to link these two object files to create an executable file
// the executable file will be created with the name a.out
gcc 6.2libraries.o 6.2libraries-main.o
./a.out

*/

int main()
{
    double po = power(2, -5);
    printf("%lf\n", po);

    int a = 10;
    printf("before changing value of a : %d\n", a);
    changeVal(&a);
    printf("after changing value of a : %d\n", a);

    int ages[] = {45, 67, 89, 21, 34, 56, 78, 90};
    int length = sizeof(ages) / sizeof(int);
    int oldest = calOldest(ages, length);
    printf("oldest is %d\n", oldest);

    return 0;
}