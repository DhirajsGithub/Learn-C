#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 1000 // Maximum number of keys

// Structure for each node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a direct address table and initialize it
Node **createDirectAddressTable()
{
    Node **table = (Node **)malloc(MAX_KEYS * sizeof(Node *));
    if (table == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < MAX_KEYS; i++)
    {
        table[i] = NULL; // Initialize all slots to NULL (indicating empty)
    }
    return table;
}

// Function to compute the hash code using the folding method
int hashCodeFolding(int key)
{
    int sum = 0;
    while (key > 0)
    {
        sum += key % 100; // Extract two digits at a time and add them to the sum
        key /= 100;       // Move to the next pair of digits
    }
    return sum % MAX_KEYS; // Take the remainder when divided by the table size
}

// Function to insert a key into the direct address table
void insertKey(Node **table, int key)
{
    int hashCode = hashCodeFolding(key);          // Compute the hash code for the key
    Node *newNode = (Node *)malloc(sizeof(Node)); // Create a new node
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = key;
    newNode->next = table[hashCode]; // Insert the new node at the beginning of the linked list
    table[hashCode] = newNode;
}

// Function to search for a key in the direct address table
int searchKey(Node **table, int key)
{
    int hashCode = hashCodeFolding(key); // Compute the hash code for the key
    Node *current = table[hashCode];
    while (current != NULL)
    {
        if (current->data == key)
        {
            return key; // If the key is found, return the key
        }
        current = current->next;
    }
    return -1; // Key not found
}

// Function to delete a key from the direct address table
void deleteKey(Node **table, int key)
{
    int hashCode = hashCodeFolding(key); // Compute the hash code for the key
    Node *current = table[hashCode];
    Node *prev = NULL;
    while (current != NULL)
    {
        if (current->data == key)
        {
            if (prev == NULL)
            {
                table[hashCode] = current->next; // Update the head of the list
            }
            else
            {
                // break the link between the previous node and the current node
                prev->next = current->next; // Link the previous node to the next node
            }
            free(current); // Free memory allocated for the node
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main()
{
    Node **table = createDirectAddressTable(); // Create the direct address table

    // Insert some keys
    insertKey(table, 12345);
    insertKey(table, 678910);
    insertKey(table, 1112131415);

    // Search for a key
    int keyToSearch = 1112131415;
    int foundKey = searchKey(table, keyToSearch);
    if (foundKey != -1)
    {
        printf("Key %d found in the direct address table.\n", foundKey);
    }
    else
    {
        printf("Key %d not found in the direct address table.\n", keyToSearch);
    }

    // Delete a key
    int keyToDelete = 12345;
    deleteKey(table, keyToDelete);
    printf("Key %d deleted from the direct address table.\n", keyToDelete);

    // Free memory allocated for the table
    for (int i = 0; i < MAX_KEYS; i++)
    {
        Node *current = table[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp); // Free memory allocated for the nodes in the linked list
        }
    }
    free(table);
    return 0;
}
