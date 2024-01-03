#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a = 10;
    float b = 10.5;
    double d = 10.5;
    char c = 'a';
    char name[] = "Dhiraj Borse";
    printf("size of int %lu bytes\n", sizeof(a));
    // why %lu? because sizeof returns unsigned long, unsigned means positive
    printf("size of float is %lu bytes\n", sizeof(b));
    printf("size of double is %lu bytes\n", sizeof(d));
    printf("size of char is %lu bytes\n", sizeof(c));
    printf("size of string is %lu bytes\n", sizeof(name)); // Dhiraj Borse\0   13 bytes

    // need to include stdbool.h for bool
    bool isTrue = true; // true is 1, false is 0

    // constants
    const int x = 10;
    // x = 20; // this is wrong

    // type casting
    // int zero = .99999; // implicit type casting, it will give warning but we can stil run it
    // printf("zero is %d\n", zero);

    // explicit type casting
    int slices = 17;
    int people = 2;
    double slicesPerPerson1 = slices / people;         // 8.00, coz int/int = int
    double slicesPerPerson2 = (double)slices / people; // 8.50  // double/int = double coz of explicit type casting
    printf("Each person gets %lf slices\n", slicesPerPerson1);
    printf("Each person gets %lf slices\n", slicesPerPerson2);

    double test1 = 25 / 2 * 2;           // 24.00
    double test2 = 25 / 2 * 2.0;         // 24.00   // 25/2 = 12.00, 12.00*2.0 = 24.00
    double test3 = 25.0 / 2 * 2;         // 25.00   // 25.0/2 = 12.50, 12.50*2 = 25.00
    double test4 = (double)25 / 2 * 2.0; // 25.00 // 25.0/2 = 12.50, 12.50*2.0 = 25.00
    printf("test1 is %lf\n", test1);
    printf("test2 is %lf\n", test2);
    printf("test3 is %lf\n", test3);
    printf("test4 is %lf\n", test4);

    return 0;
}