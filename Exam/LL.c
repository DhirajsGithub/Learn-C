#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

// function to create a new node
Node *createNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// function to insert a node at beginning of ll
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNewNode(data);
    newNode->link = head;
    head = newNode;
    return head;
}

void freeLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->link;
        free(temp); // Free memory for the current node
    }
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNewNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node *tempNode = head;
    while (tempNode->link != NULL)
    {
        tempNode = tempNode->link;
    }
    tempNode->link = newNode;
    return newNode;
}

int deleteElement(Node *head, int x)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *current = head;
    Node *prv = NULL;
    if (current->data == x)
    {
        head = current->link; // Update head to the next node
        free(current);        // Free memory for the deleted node
        return x;
    }
    while (current != NULL)
    {
        if (current->data == x)
        {
            prv->link = current->link;
            return x;
        }
        prv = current;
        current = current->link;
    }
    return -1;
}

int search(Node *head, int x)
{
    int position = 0;
    Node *current = head;

    // Traverse the list to find the node with data x
    while (current != NULL)
    {
        if (current->data == x)
        {
            return position; // Return the position if found
        }
        current = current->link;
        position++;
    }

    return -1; // Return -1 if not found
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    // Insert elements at the beginning of the list
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40);

    Node *end = NULL;
    end = insertAtEnd(head, 90);

    // Print the initial list
    printf("Initial list: ");
    printList(head);
    free(end);

    // Search for an element in the list
    int searchValue = 20;
    int position = search(head, searchValue);
    if (position != -1)
    {
        printf("%d found at position %d\n", searchValue, position);
    }
    else
    {
        printf("%d not found in the list\n", searchValue);
    }

    // Delete an element from the list
    int deleteValue = 30;
    int deletedElement = deleteElement(head, deleteValue);
    if (deletedElement != -1)
    {
        printf("Deleted %d from the list\n", deletedElement);
    }
    else
    {
        printf("%d not found in the list, nothing to delete\n", deleteValue);
    }

    // Print the modified list
    printf("Modified list: ");
    printList(head);

    return 0;
}