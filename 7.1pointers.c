#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void makeSquare(int *num)
{
    *num = *num * *num;
}
void sizeExample(int ages[])
{
    printf("memory size of ages is %lu\n", sizeof(ages));
    printf("it's not the same as the size of the array\n it is the size of the pointer\n");
}

int main()
{
    // pointers
    int a = 10;
    int *p = &a;
    printf("a is %d\n", a);
    printf("address of a is %p\n", &a);
    printf("p is %p\n", p); // %p is used to print the address of a variable in hexadecimal format (base 16)
    printf("value at address p is %d\n", *p);

    a = 69;
    printf("a is %d\n", a);
    printf("p is %d\n", *p);

    *p = 78;
    printf("a is %d\n", a);
    printf("p is %d\n", *p);

    // pointer arithmetic
    *p = *p + 1;
    printf("a is %d\n", a);
    printf("p is %d\n", *p);

    int c = 899;
    p = &c; // p now points to c
    a = 90;
    printf("a is %d\n", a);
    printf("p is %d\n", *p);

    // arrays and pointers
    int ages[] = {45, 67, 89, 21, 34, 56, 78, 90};
    int *pAges = ages;
    printf("ages is %p\n", ages);
    printf("pAges is %p\n", pAges);
    printf("value at address pAges is %d\n", *pAges);

    // pointers with functions
    int x = 5;
    makeSquare(&x);
    printf("x now is %d\n", x);

    // why to pass size of array to a function
    int size = 6;
    int ages2[] = {45, 67, 89, 21, 34, 56, 78, 90};
    printf("memory size of ages2 is %lu\n", sizeof(ages));
    sizeExample(ages2);

    return 0;
}
