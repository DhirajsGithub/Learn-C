#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *data;
    struct Node *link;
} Node;

void createEmptyStack(Node **top)
{
    (*top) = NULL;
}

int isEmpty(Node **top)
{
    return (*top) == NULL;
}

void push(Node **top, char *x)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char *)malloc((strlen(x) + 1) * sizeof(char));
    strcpy(newNode->data, x);
    newNode->link = (*top);
    (*top) = newNode;
}
char *pop(Node **top)
{
    if (isEmpty(top))
    {
        printf("Stack underflow.\n");
        return NULL;
    }
    char *x = (*top)->data;
    Node *temp = *top;
    (*top) = (*top)->link;
    free(temp);
    return x;
}

char *top(Node **top)
{
    if (!isEmpty)
    {
        return (*top)->data;
    }
    return NULL;
}
char *top(Node **top)
{
    if (!isEmpty(top))
    {
        return (*top)->data;
    }
    return NULL;
}
int main()
{
    Node *topNode;
    createEmptyStack(&topNode);

    push(&topNode, "Hello");
    push(&topNode, "World");
    push(&topNode, "Stack");
    printf("Top element after pushes: %s\n", top(&topNode));

    printf("Popped element: %s\n", pop(&topNode));
    printf("Popped element: %s\n", pop(&topNode));

    printf("Top element after pops: %s\n", top(&topNode));
}
