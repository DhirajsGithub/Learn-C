#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[100];
} Stu;

int main()
{
    Stu s = {2, "fdkjf"};
    printf("%d", s.id);
    return 0;
}