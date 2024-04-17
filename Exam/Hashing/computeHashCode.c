#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Student
{
    int id;
    char name[30];
    char branch[5];
    int age;
} Student;

int noOfDigits(int d)
{
    int count = 0;
    while (d > 0)
    {
        d = d / 10;
        count++;
    }
    return count;
}

int TruncationMethod(Student *stu, int truncationDigit)
{
    int id = stu->id;
    int digits = noOfDigits(id);

    int loop = digits - truncationDigit;
    if (loop < 0)
    {
        printf("cannot truncate \n");
        return -1;
    }
    for (int i = 0; i < loop; i++)
    {
        id = id / 10;
    }
    return id;
}

int midNum(int num)
{

    if (noOfDigits(num) <= 2)
    {
        return num;
    }
    int di = pow(10, ((noOfDigits(num) / 2) - 1));

    int qu = num / di;

    if (noOfDigits(num) % 2 == 0)
    {
        return qu % 100;
    }
    else
    {
        qu = qu / 10;
        return qu % 10;
    }
}

int midSquare(int key, int digits)
{
    int ans = 0;
    while (noOfDigits(key) > 1)
    {

        int tenPow = pow(10, noOfDigits(key) - 2);
        int firstTwo = key / tenPow;
        printf("mid num of first two %d\n", midNum(firstTwo * firstTwo));
        if (noOfDigits(midNum(firstTwo * firstTwo)) > 1)
        {
            ans = ans * 100 + midNum(firstTwo * firstTwo);
        }
        else
        {
            ans = ans * 10 + midNum(firstTwo * firstTwo);
        }

        key = key % tenPow;
    }
    ans = ans * 100 + midNum(key * key);
    return ans;
}

int FoldingMethod(Student *stu)
{
    int ans = 0;
    int id = stu->id;
    int digits = noOfDigits(id);

    if (digits % 2 == 0)
    {
        while (id > 0)
        {
            int lastTwo = id % 100;
            id = id / 100;
            ans += lastTwo;
        }
    }
    else
    {
        ans += id % 10;
        id = id / 10;
        while (id > 0)
        {
            int lastTwo = id % 100;
            id = id / 100;
            ans += lastTwo;
        }
    }
    return ans;
}
int ModularMethod(Student *stu, int hashSize)
{
    return (stu->id) % hashSize;
}

int divisionMethod(int key, int hashSize)
{
    return key % hashSize;
}
int multiplicationMethod(int key, int m, float A)
{
    float product = key * A;
    float fraction = product - (int)product;
    int hash = (int)(m * fraction);
    return hash;
}

int main()
{
    int trucationDigits = 3;
    Student stu = {12342, "dhiraj", "CSE", 22};
    printf("TruncationMethod : %d \n", TruncationMethod(&stu, 3));
    printf("midSquare : %d \n", midSquare(stu.id, noOfDigits(stu.id)));
    printf("FoldingMethod : %d \n", FoldingMethod(&stu));
    printf("ModularMethod : %d \n", ModularMethod(&stu, 100));

    return 0;
}
