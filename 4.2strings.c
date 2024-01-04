#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char name0[] = "john";

    printf("what is your name ?\n");
    char name[20];     // name will only store 19 characters, the last one is for the null character, which is automatically added to the end of the string
    scanf("%s", name); // this will only read the first word, it will stop reading when it encounters a space
    int length = 0;
    while (name[length] != '\0')
    {
        length++;
    }

    printf("hello %s, your name is %d characters long\n", name, length);
    int inbuilLength = strlen(name);
    printf("hello %s, your name is %d characters long\n", name, inbuilLength);

    // string comparison
    char password[] = "password";
    char guess[20];
    printf("enter your password\n");
    scanf("%s", guess);
    if (strcmp(password, guess) == 0) // strcmp returns 0 if the strings are equal
    {
        printf("correct\n");
    }
    else
    {
        printf("incorrect\n");
    }

    // string concatenation
    char firstName[] = "john";
    char lastName[] = "doe";
    char fullName[20];
    // fullName = firstName + " " + lastName; // this will give an error
    // copy firstName into fullName then concatenate a space and lastName into fullName
    strcpy(fullName, firstName); // copy firstName into fullName        // strcpy(destination, source)
    strcat(fullName, " ");       // add a space to fullName         // strcat(destination, source)
    strcat(fullName, lastName);  // add lastName to fullName            // strcat(destination, source)
    printf("your full name is %s\n", fullName);

    // printf("comparing two string %s ", "dhiraj" == "dhfiraj" ? "true" : "false");        // this comparision will give warning

    return 0;
}