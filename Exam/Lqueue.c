#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *data;
    struct Node *link;
} Node;

void createEmptyQueue(Node **front, Node **rear)
{
    (*front) = NULL;
    (*rear) = NULL;
}

int isEmpty(Node **front, Node **rear)
{
    return (*front) == NULL && (*rear) == NULL;
}

void enqueue(Node **front, Node **rear, char *x)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char *)malloc((strlen(x) + 1) * sizeof(char));
    strcpy(newNode->data, x);
    newNode->link = NULL;
    if (isEmpty(front, rear))
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->link = newNode;
        *rear = newNode;
    }
    return;
}

char *dequeue(Node **front, Node **rear)
{
    if (isEmpty(front, rear))
    {
        printf("Stack underflow. \n");
        return NULL;
    }
    char *x = (*front)->data;
    Node *p = (*front);

    (*front) = (*front)->link;
    if (*front == NULL)
    {
        *rear = NULL; // if the queue becomes empty after dequeue
    }
    free(p);
    return x;
}
int main()
{
    Node *front;
    Node *rear;
    createEmptyQueue(&front, &rear);

    enqueue(&front, &rear, "Hello");
    enqueue(&front, &rear, "World");
    enqueue(&front, &rear, "Queue");

    printf("Dequeued element: %s\n", dequeue(&front, &rear));
    printf("Dequeued element: %s\n", dequeue(&front, &rear));

    return 0;
}