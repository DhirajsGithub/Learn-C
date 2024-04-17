#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 1000
#define EMPTY -1

typedef struct Record
{
    int id;
    char name[50];
    char branch[50];
    int age;
} Record;

typedef struct Slot
{
    int status;
    Record *record;
} Slot;

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
        table[i].record = NULL;
        table[i].status = EMPTY;
    }

    return table;
}

int hashCode(int key)
{
    return key % MAX_KEYS;
}

void insertRecord(Slot *table, Record *record)
{
    int hash = hashCode(record->id);
    while (table[hash].status == 1)
    {
        hash = (hash + 1) % MAX_KEYS;
    }

    table[hash].record = record;
    table[hash].status = 1;
}

void deleteRecord(Slot *table, int key)
{
    int hash = hashCode(key);
    while (table[hash].status != EMPTY)
    {
        if (table[hash].status == 1 && table[hash].record->id == key)
        {
            table[hash].status = EMPTY;
            table[hash].record = NULL;
            return;
        }
        hash = (hash + 1) % MAX_KEYS;
    }
}

Record *searchRecord(Slot *table, int key)
{
    int hash = hashCode(key);
    while (table[hash].status != EMPTY)
    {
        if (table[hash].status == 1 && table[hash].record->id == key)
        {
            return table[hash].record;
        }
        hash = (hash + 1) % MAX_KEYS;
    }
    return NULL;
}

int main()
{
    Slot *table = createDirectAddressTable();
    Record record1 = {123, "dhiraj", "CSE", 22};
    Record record2 = {455, "harshal", "ME", 20};

    insertRecord(table, &record1);
    insertRecord(table, &record2);

    int keyToSearch = 123;
    Record *foundKey = searchRecord(table, keyToSearch);
    if (foundKey != NULL)
    {
        printf("Name %s found in the direct address table.\n", foundKey->name);
    }
    else
    {
        printf("Key not found !!! ");
    }

    deleteRecord(table, record1.id);

    Record *foundKey2 = searchRecord(table, keyToSearch);
    if (foundKey2 != NULL)
    {
        printf("Name %s found in the direct address table.\n", foundKey2->name);
    }
    else
    {
        printf("Key not found !!! ");
    }

    return 0;
}