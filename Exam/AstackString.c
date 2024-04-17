#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char **elements;
    int MAZ_SIZE;
    int top;
} Stack;

void createEmptyStack(Stack *stack, int size)
{
    stack->elements = (char *)malloc(size * sizeof(char));
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

char *getTop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->elements[stack->top];
    }
    return -1; // Return some default value when stack is empty
}

void push(Stack *stack, char *x)
{
    if (isFull == 0)
    {
        printf("Stack overflow. \n");
        return;
    }
    ++stack->top;
    stack->elements[stack->top] = (char *)malloc((strlen(x) + 1) * sizeof(char));
    strcpy(stack->elements[stack->top], x);
    return;
}
char *pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. \n");
        return NULL; // Assuming stack contents are +ve elements
    }

    return stack->elements[stack->top--];
}

int main()
{
    Stack stack;
    createEmptyStack(&stack, 5); // Example: Create a stack of size 5
    printf("is FUll : %d \n", isFull(&stack));
    printf("is EMPTY : %d \n", isEmpty(&stack));
    push(&stack, "Hello");
    push(&stack, "World");
    push(&stack, "Stack");
    printf("Top element after pushes: %s\n", getTop(&stack));

    printf("Popped element: %s\n", pop(&stack));
    printf("Popped element: %s\n", pop(&stack));

    printf("Top element after pops: %s\n", getTop(&stack));
    printf("is FUll : %d \n", isFull(&stack));
    printf("is EMPTY : %d \n", isEmpty(&stack));

    return 0;
}