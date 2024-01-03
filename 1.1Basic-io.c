#include <stdio.h>

int main()
{
    printf("Hellow World\n"); // \n is a new line character

    // variables
    int a = 10;
    int b;  // declaration
    b = 20; // initialization

    // string format specifier
    printf("%s world\n", "Hellowww");

    // integer format specifier
    printf("Value of a : %d. Value of b : %d\n", a, b);

    // float format specifier
    float c = 10.5;
    printf("Value of c : %f\n", c);

    // so on for character, double, long, short, unsigned int, unsigned long, unsigned short, unsigned char
    // %c, %lf, %ld, %hd, %u, %lu, %hu, %hhu

    // taking user input
    printf("Enter a radius: ");
    int radius;
    scanf("%d", &radius); // & is the address of operator
    printf("Radius is %d\n", radius);
    // &radius is the address of the variable radius
    // scanf("%d", radius); // this is wrong
    // why & is needed? because scanf is a function and it needs to know where to store the value
    // & is not needed for arrays because arrays are already pointers

    // string in c
    char name[20]; // array of characters of size 19
    // you have to reserce one character for null terminator
    // null terminator is automatically added at the end of the string
    // null terminator is \0
    // why null terminator is needed? because printf needs to know where the string ends
    scanf("%19s", name); // why 19s? because we reserved 20 characters and we need one for null terminator
    printf("Your name is %s\n", name);
    // space is a delimiter for scanf and printf by default so it will stop reading after space
    // how to read space in scanf? use %[^\n]s
    char name2[20];
    scanf(" %[^\n]s", name2);
    printf("Your big name is %s\n", name2);

    return 0;
}