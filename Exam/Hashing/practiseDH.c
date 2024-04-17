#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define EMPTY -1

typedef struct Record
{
    int id;
    char name[100];
    int age;
} Record;

typedef struct Slot
{
    int status;
    Record *record;
} Slot;

Slot *createTable()
{
    Slot *table = (Slot *)malloc(MAX_SIZE * sizeof(Slot));
    if (table == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        table[i].status = EMPTY;
        table[i].record = NULL;
    }

    return table;
}

int hash1(int key)
{
    return key % MAX_SIZE;
}

int hash2(int key)
{
    return 7 - (key % 7);
}
void insertRecord(Slot *table, Record *record)
{
    int index = hash1(record->id);
    while (table[index].status == 1)
    {
        int step = hash2(record->id);
        index = (index + step) % MAX_SIZE;
    }
    table[index].status = 1;
    table[index].record = record;
}

void deleteRecord(Slot *table, int key)
{
    int index = hash1(key);
    while (table[index].status != EMPTY)
    {
        if (table[index].status == 1 && table[index].record->id == key)
        {
            table[index].status = -1;
            table[index].record = NULL;
            return;
        }
        int step = hash2(key);
        index = (index + step) % MAX_SIZE;
    }
    return;
}

Record *searchRecord(Slot *table, int key)
{
    int index = hash1(key);
    while (table[index].status != EMPTY)
    {
        if (table[index].status == 1 && table[index].record->id == key)
        {
            return table[index].record;
        }
        int step = hash2(key);
        index = (index + step) % MAX_SIZE;
    }
    return NULL;
}

int main()
{

    Slot *table = createTable();
    Record rec = {123, "dhiraj", 22};
    Record rec2 = {456, "anuv", 43};

    insertRecord(table, &rec);
    insertRecord(table, &rec2);

    int searchId = 456;

    Record *foundRecord = searchRecord(table, searchId);
    if (foundRecord != NULL)
    {
        printf("Student found:\n");
        printf("ID: %d\nName:  %s\nAge: %d\n", foundRecord->id, foundRecord->name, foundRecord->age);
    }
    else
    {
        printf("Student not found.\n");
    }

    // Delete a record
    int idToDelete = 456;
    deleteRecord(table, idToDelete);
    printf("Record with ID %d deleted.\n", idToDelete);

    Record *foundRecord2 = searchRecord(table, searchId);
    if (foundRecord2 != NULL)
    {
        printf("Student found:\n");
        printf("ID: %d\nName:  %s\nAge: %d\n", foundRecord2->id, foundRecord2->name, foundRecord2->age);
    }
    else
    {
        printf("Student not found.\n");
    }

    free(table); // Free memory allocated for the table
}