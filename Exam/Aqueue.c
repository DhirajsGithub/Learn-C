#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
    int Max_Size;
    char **element; // 1D dynamic array
    int front;      // index of front element
    int rear;       // index of rear element
} Queue;

void createEmptyQueue(Queue *queue, int size)
{
    queue->element = (char **)malloc(size * sizeof(char *));
    queue->Max_Size = size;
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}
int isFull(Queue *queue)
{
    return queue->rear == queue->Max_Size;
}

int getFront(Queue *q)
{
    return q->front;
}

// Function that return the rear element in stack
int getRear(Queue *q)
{
    return q->rear;
}

void enqueue(Queue *queue, char *x)
{
    if (isFull(queue))
    {
        printf("Queue overflow. \n");
        return;
    }
    queue->rear++;
    queue->element[queue->rear] = (char *)malloc((strlen(x) + 1) * sizeof(char));
    strcpy(queue->element[queue->rear], x);
    if (queue->front == -1) // check if it is the first element
        queue->front = 0;

    return;
}

char *dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow. \n");
        return NULL;
    }
    char *x = queue->element[queue->front];
    if (queue->rear == queue->front)
    {
        queue->rear = -1;
        queue->front = -1;
    }
    else
    {
        queue->front++;
    }

    return x;
}

int main()
{
    Queue queue;
    createEmptyQueue(&queue, 5); // Example: Create a queue of size 5

    enqueue(&queue, "Hello");
    enqueue(&queue, "World");
    enqueue(&queue, "Queue");

    printf("Front: %d, Rear: %d\n", getFront(&queue), getRear(&queue));

    printf("Dequeued element: %s\n", dequeue(&queue));
    printf("Dequeued element: %s\n", dequeue(&queue));

    printf("Front: %d, Rear: %d\n", getFront(&queue), getRear(&queue));

    return 0;
}
