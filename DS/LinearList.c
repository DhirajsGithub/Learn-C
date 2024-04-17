#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int MAX_SIZE;
    int *elements;
    int len;
} LinearList;

LinearList createEmptyList(LinearList list, int size)
{
    list.MAX_SIZE = size;
    list.len = 0;
    list.elements = (int *)malloc(size * (sizeof(int)));

    return list;
}
int isEmpty(LinearList list)
{
    return list.len == 0;
}
int listLength(LinearList list)
{
    return list.len;
}
int search(LinearList list, int x)
{
    for (int i = 0; i < list.len; i++)
    {
        if (list.elements[i] == x)
        {
            return ++i; // 1 index system
        }
    }
    return 0;
}
void insert(LinearList list, int x, int e)
{
    if (list.len == 0 && x != 0)
    {
        printf("empty list can't insert");
        return;
    }
    if (list.len == list.MAX_SIZE)
    {
        printf("list full");
        return;
    }
    if (list.len == 0 && x == 0)
    {
        list.elements[x] = e;
        list.len++;
        return;
    }

    for (int i = list.len - 1; i >= x; i--)
    {
        list.elements[i + 1] = list.elements[i];
    }
    list.elements[x] = e;
    list.len++;
}
LinearList delete(LinearList list, int k)
{
    // assuming k is in range

    for (int i = k; i < list.len - 1; i++)
    {
        list.elements[i] = list.elements[i + 1];
    }
    return list;
}

int main()
{
    int c = 3;
    int *p;
    p = &c;
    printf("%p\n", p);
    return 0;
}