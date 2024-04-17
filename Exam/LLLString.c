#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int MAX_SIZE;
    char **elements;
    int len;
} LinearList;

LinearList createEmtpyList(LinearList *list, int size)
{
    list->MAX_SIZE = size;
    list->len = 0;
    list->elements = (char *)malloc(size * sizeof(char *));
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
int search(LinearList *list, char *x)
{
    for (int i = 0; i < list->len; i++)
    {
        if (strcmp(list->elements[i], x) == 0)
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
int insert(LinearList *list, int k, char *x)
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

char *deleteElement(LinearList *list, int k)
{
    char *x;
    x = list->elements[k];
    for (int i = k; i < list->len - 1; i++)
    {
        list->elements[i] = list->elements[i + 1];
    }
    list->len -= 1;
    return x;
}
void printList(LinearList *list)
{
    printf("List elements:\n");
    for (int i = 0; i < list->len; i++)
    {
        printf("%s\n", list->elements[i]);
    }
}

int main()
{
    LinearList list;
    createEmtpyList(&list, 10);

    insert(&list, 0, "apple");
    insert(&list, 1, "banana");
    insert(&list, 2, "orange");
    insert(&list, 1, "grape");

    printf("After insertion:\n");
    printList(&list);

    char *deletedElement = deleteElement(&list, 2);
    printf("\nDeleted element: %s\n", deletedElement);

    printf("\nAfter deletion:\n");
    printList(&list);

    // Free memory allocated for elements
    for (int i = 0; i < list.len; i++)
    {
        free(list.elements[i]);
    }
    free(list.elements);

    return 0;
}
