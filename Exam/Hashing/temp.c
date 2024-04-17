#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 1000 // Maximum number of keys

// Structure for each node in the linked list
typedef struct Node
{
    int id;
    char name[50];
    char branch[50];
    int age;
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

// Function to insert a record into the direct address table
void insertRecord(Node **table, Node *record)
{
    int hashCode = hashCodeFolding(record->id); // Compute the hash code for the key
    record->next = table[hashCode];             // Insert the new record at the beginning of the linked list
    table[hashCode] = record;
}

// Function to search for a record in the direct address table
Node *searchRecord(Node **table, int id)
{
    int hashCode = hashCodeFolding(id); // Compute the hash code for the key
    Node *current = table[hashCode];
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current; // If the record is found, return the record
        }
        current = current->next;
    }
    return NULL; // Record not found
}

// Function to delete a record from the direct address table
void deleteRecord(Node **table, int id)
{
    int hashCode = hashCodeFolding(id); // Compute the hash code for the key
    Node *current = table[hashCode];
    Node *prev = NULL;
    while (current != NULL)
    {
        if (current->id == id)
        {
            if (prev == NULL)
            {
                table[hashCode] = current->next; // Update the head of the list
            }
            else
            {
                prev->next = current->next; // Link the previous node to the next node
            }
            free(current); // Free memory allocated for the record
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main()
{
    Node **table = createDirectAddressTable(); // Create the direct address table

    // Input student data
    Node *record = (Node *)malloc(sizeof(Node));
    if (record == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the id of the student: ");
    scanf("%d", &record->id);
    printf("Enter the name of the student: ");
    scanf("%s", record->name);
    printf("Enter the branch of the student: ");
    scanf("%s", record->branch);
    printf("Enter the age of the student: ");
    scanf("%d", &record->age);

    // Insert the record into the direct address table
    insertRecord(table, record);

    // Search for a record by ID
    int searchId;
    printf("Enter the id to search: ");
    scanf("%d", &searchId);
    Node *foundRecord = searchRecord(table, searchId);
    if (foundRecord != NULL)
    {
        printf("Student found:\n");
        printf("ID: %d\nName: %s\nBranch: %s\nAge: %d\n", foundRecord->id, foundRecord->name, foundRecord->branch, foundRecord->age);
    }
    else
    {
        printf("Student not found.\n");
    }

    // Delete a record
    int idToDelete;
    printf("Enter the id to delete: ");
    scanf("%d", &idToDelete);
    deleteRecord(table, idToDelete);
    printf("Record with ID %d deleted.\n", idToDelete);

    // Free memory allocated for the table
    for (int i = 0; i < MAX_KEYS; i++)
    {
        Node *current = table[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp); // Free memory allocated for the record
        }
    }
    free(table);

    return 0;
}
