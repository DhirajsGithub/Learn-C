#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int MAX_SIZE;
    int *elements;
    int len;
} LinearList;

LinearList createEmtpyList(LinearList *list, int size)
{
    list->MAX_SIZE = size;
    list->len = 0;
    list->elements = (int *)malloc(size * sizeof(int));
    return *list;
}

int isEmpty(LinearList *list)
{
    if (list->len == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int listLength(LinearList *list)
{
    return list->len;
}
int search(LinearList *list, int x)
{
    for (int i = 0; i < list->len; i++)
    {
        if (list->elements[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int isFull(LinearList *list)
{
    if (list->len == list->MAX_SIZE)
    {
        return 1;
    }
    return 0;
}
int insert(LinearList *list, int k, int x)
{
    if (isFull(list) == 1 || k < 0)
    {
        return -1;
    }
    if (list->len == 0)
    {
        list->elements[0] = x;
        list->len += 1;
        return x;
    }
    if (k >= list->len)
    {
        list->elements[list->len] = x;
        list->len += 1;
        return x;
    }

    for (int i = list->len - 1; i >= k; i--)
    {
        list->elements[i + 1] = list->elements[i];
    }
    list->elements[k] = x;
    list->len += 1;
    return x;
}

int deleteElement(LinearList *list, int k)
{
    int x, i;
    x = list->elements[k];
    for (int i = k; i < list->len - 1; i++)
    {
        list->elements[i] = list->elements[i + 1];
    }
    list->len -= 1;
    return x;
}

int main()
{
    LinearList myList;
    createEmtpyList(&myList, 10);

    insert(&myList, 0, 5);  // Insert 5 at index 0
    insert(&myList, 1, 10); // Insert 10 at index 1
    // Print some elements
    printf("List length: %d\n", listLength(&myList));
    printf("Is list empty? %s\n", isEmpty(&myList) ? "Yes" : "No");
    printf("Element at index 0: %d\n", myList.elements[0]);
    printf("Element at index 1: %d\n", myList.elements[1]);

    // Delete an element
    int deletedValue = deleteElement(&myList, 0); // Delete element at index 0
    if (deletedValue != -1)
    {
        printf("Deleted value: %d\n", deletedValue);
    }
    else
    {
        printf("Deletion failed.\n");
    }

    // Print updated list length
    printf("Updated list length: %d\n", listLength(&myList));
    int findEle = search(&myList, 10);
    printf("found elemetn at %d\n", findEle);
    free(myList.elements);

    return 0;
}
