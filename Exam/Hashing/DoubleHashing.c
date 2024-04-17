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

// Structure for each node in the hash table
typedef struct
{
    Record *record;
    int status; // Status of the slot: 0 for empty, 1 for occupied, -1 for deleted
} Slot;

// Function to create a hash table and initialize it
Slot *createHashTable()
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

// First hash function
int hash1(int key)
{
    return key % MAX_KEYS;
}

// Second hash function for probing
int hash2(int key)
{
    // Choose a prime number less than MAX_KEYS for better distribution
    return 7 - (key % 7);
}

// Function to insert a record into the hash table using double hashing
void insertRecord(Slot *table, Record *record)
{
    int key = record->id;
    int index = hash1(key); // Compute the initial hash code

    // If the slot is occupied, probe using the second hash function
    while (table[index].status == 1)
    {
        int step = hash2(key);             // Compute the step size
        index = (index + step) % MAX_KEYS; // Move to the next slot
    }

    // Insert the record into the empty slot
    table[index].record = record;
    table[index].status = 1; // Mark the slot as occupied
}

// Function to search for a record in the hash table
Record *searchRecord(Slot *table, int key)
{
    int index = hash1(key); // Compute the initial hash code

    // If the slot is occupied, probe using the second hash function
    while (table[index].status != EMPTY)
    {
        if (table[index].status == 1 && table[index].record->id == key)
        {
            return table[index].record; // Return the record if found
        }
        int step = hash2(key);             // Compute the step size
        index = (index + step) % MAX_KEYS; // Move to the next slot
    }
    return NULL; // Record not found
}

// Function to delete a record from the hash table
void deleteRecord(Slot *table, int key)
{
    int index = hash1(key); // Compute the initial hash code

    // If the slot is occupied, probe using the second hash function
    while (table[index].status != EMPTY)
    {
        if (table[index].status == 1 && table[index].record->id == key)
        {
            table[index].record = NULL; // Delete the record
            table[index].status = -1;   // Mark the slot as deleted
            return;
        }
        int step = hash2(key);             // Compute the step size
        index = (index + step) % MAX_KEYS; // Move to the next slot
    }
}

int main()
{
    Slot *table = createHashTable(); // Create the hash table

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

    // Insert the record into the hash table
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
