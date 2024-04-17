#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *data;
    struct Node *link;
} Node;

// function to create a new node
Node *createNewNode(char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = (char *)malloc((strlen(data) + 1) * sizeof(char));
    if (newNode->data == NULL)
    {
        printf("Memory allocation failed.\n");
        free(newNode); // Free the allocated node
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->link = NULL;
    return newNode;
}

// function to insert a node at beginning of ll
Node *insertAtBeginning(Node *head, char *data)
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

Node *insertAtEnd(Node *head, char *data)
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

char *deleteElement(Node **headPtr, char *x)
{
    if (*headPtr == NULL)
    {
        return NULL; // Return NULL if the list is empty
    }
    Node *current = *headPtr;
    Node *prv = NULL;
    while (current != NULL)
    {
        if (strcmp(current->data, x) == 0)
        {
            if (prv == NULL)
            {
                *headPtr = current->link; // Update head to the next node
            }
            else
            {
                prv->link = current->link;
            }
            char *deletedData = current->data;
            free(current); // Free memory for the deleted node
            return deletedData;
        }
        prv = current;
        current = current->link;
    }
    return NULL; // Return NULL if the element was not found
}

int search(Node *head, char *x)
{
    int position = 0;
    Node *current = head;

    // Traverse the list to find the node with data x
    while (current != NULL)
    {
        if (strcmp(current->data, x) == 0)
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
        printf("%s->", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

void deleteList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->link;
        free(temp); // Free memory for the current node
    }
}

int main()
{
    Node *head = NULL;

    // Insert elements at the beginning of the list
    head = insertAtBeginning(head, "apple");
    head = insertAtBeginning(head, "banana");
    head = insertAtBeginning(head, "papaya");
    head = insertAtBeginning(head, "melon");

    // Insert element at the end of the list
    insertAtEnd(&head, "mango");

    // Print the initial list
    printf("Initial list: ");
    printList(head);
    printf("\n");

    // Search for an element in the list
    char searchValue[100] = "papaya";
    int position = search(head, searchValue);
    if (position != -1)
    {
        printf("%s found at position %d\n", searchValue, position);
    }
    else
    {
        printf("%s not found in the list\n", searchValue);
    }

    // Delete an element from the list
    char deleteValue[100] = "papaya";
    char *deletedElement = deleteElement(&head, deleteValue);
    if (deletedElement != NULL)
    {
        printf("Deleted %s from the list\n", deletedElement);
        free(deletedElement); // Free the memory allocated for the deleted element
    }
    else
    {
        printf("%s not found in the list, nothing to delete\n", deleteValue);
    }

    // Print the modified list
    printf("Modified list: ");
    printList(head);
    printf("\n");

    // Free the memory allocated for the linked list
    deleteList(&head);
}