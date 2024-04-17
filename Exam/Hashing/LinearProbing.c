#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 1000 // Maximum number of keys
#define EMPTY -1

// Structure for each student record
typedef struct
{
    int id;
    char name[50];
    char branch[50];
    int age;
} Record;

// Structure for each node in the direct address table
typedef struct
{
    Record *record;
    int status; // Status of the slot: 0 for empty, 1 for occupied, -1 for deleted
} Slot;

// Function to create a direct address table and initialize it
Slot *createDirectAddressTable()
{
    Slot *table = (Slot *)malloc(MAX_KEYS * sizeof(Slot));
    if (table == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < MAX_KEYS; i++)
    {
        table[i].record = NULL;  // Initialize all records to NULL
        table[i].status = EMPTY; // Initialize all slots to empty
    }
    return table;
}

// Function to compute the hash code for a given key
int hashCode(int key)
{
    return key % MAX_KEYS;
}

// Function to insert a record into the direct address table using linear probing
void insertRecord(Slot *table, Record *record)
{
    int key = record->id;
    int index = hashCode(key); // Compute the hash code for the key

    // Linear probing until an empty slot is found
    while (table[index].status == 1)
    {
        index = (index + 1) % MAX_KEYS; // Move to the next slot
    }

    // Insert the record into the empty slot
    table[index].record = record;
    table[index].status = 1; // Mark the slot as occupied
}

// Function to search for a record in the direct address table
Record *searchRecord(Slot *table, int key)
{
    int index = hashCode(key); // Compute the hash code for the key

    // Linear probing until the record is found or an empty slot is encountered
    while (table[index].status != EMPTY)
    {
        if (table[index].status == 1 && table[index].record->id == key)
        {
            return table[index].record; // Return the record if found
        }
        index = (index + 1) % MAX_KEYS; // Move to the next slot
    }
    return NULL; // Record not found
}

// Function to delete a record from the direct address table
void deleteRecord(Slot *table, int key)
{
    int index = hashCode(key); // Compute the hash code for the key

    // Linear probing until the record is found or an empty slot is encountered
    while (table[index].status != EMPTY)
    {
        if (table[index].status == 1 && table[index].record->id == key)
        {
            table[index].record = NULL; // Delete the record
            table[index].status = -1;   // Mark the slot as deleted
            return;
        }
        index = (index + 1) % MAX_KEYS; // Move to the next slot
    }
}

int main()
{
    Slot *table = createDirectAddressTable(); // Create the direct address table

    // Input student data
    Record record;
    printf("Enter the id of the student: ");
    scanf("%d", &record.id);
    printf("Enter the name of the student: ");
    scanf("%s", record.name);
    printf("Enter the branch of the student: ");
    scanf("%s", record.branch);
    printf("Enter the age of the student: ");
    scanf("%d", &record.age);

    // Insert the record into the direct address table
    insertRecord(table, &record);

    // Search for a record by ID
    int searchId;
    printf("Enter the id to search: ");
    scanf("%d", &searchId);
    Record *foundRecord = searchRecord(table, searchId);
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

    free(table); // Free memory allocated for the table

    return 0;
}
