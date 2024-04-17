#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int *elements;
    int MAZ_SIZE;
    int top;
} Stack;

void createEmptyStack(Stack *stack, int size)
{
    stack->elements = (int *)malloc(size * sizeof(int));
    stack->MAZ_SIZE = size;
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}
int isFull(Stack *stack)
{
    return stack->top == stack->MAZ_SIZE - 1;
}

int getTop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->elements[stack->top];
    }
    return -1; // Return some default value when stack is empty
}

void push(Stack *stack, int x)
{
    if (isFull == 0)
    {
        printf("Stack overflow. \n");
        return;
    }
    stack->elements[++stack->top] = x;
    return;
}
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. \n");
        return -1; // Assuming stack contents are +ve elements
    }

    return stack->elements[stack->top--];
}

int main()
{
    Stack stack;
    createEmptyStack(&stack, 10);
    printf("is FUll : %d \n", isFull(&stack));
    printf("is EMPTY : %d \n", isEmpty(&stack));
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Top element after pushes: %d\n", getTop(&stack));
    printf("is FUll : %d \n", isFull(&stack));
    printf("is EMPTY : %d \n", isEmpty(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element after pops: %d\n", getTop(&stack));
    return 0;
}