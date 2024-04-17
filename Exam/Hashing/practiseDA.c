#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Record
{
    int id;
    char name[20];
    int age;
} Record;

typedef struct Node
{
    Record *record;
    struct Node *link;
} Node;

Node **createHashTable()
{
    Node **table = (Node **)malloc(sizeof(Node *) * MAX_SIZE);
    if (table == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    for (int i = 0; i < MAX_SIZE; i++)
    {
        table[i] = NULL;
    }
    return table;
}

int hashCodeFolding(int key)
{
    int sum = 0;
    while (key > 0)
    {
        sum += key % 100; // Extract two digits at a time and add them to the sum
        key /= 100;       // Move to the next pair of digits
    }
    return sum % MAX_SIZE; // Take the remainder when divided by the table size
}

void insertRecord(Node **table, Record *record)
{
    int hashCode = hashCodeFolding(record->id);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->record = record;
    newNode->link = table[hashCode];
    table[hashCode] = newNode;
}

void deleteRecor(Node **table, int key)
{
    int hashCode = hashCodeFolding(key);
    Node *current = table[hashCode];
    Node *prv = NULL;
    while (current != NULL)
    {
        if (current->record->id == key)
        {

            if (prv == NULL)
            {
                table[hashCode] = current->link;
            }
            else
            {
                prv->link = current->link;
            }

            free(current);
        }
        prv = current;
        current = current->link;
    }
}

Record *searchRecord(Node **table, int key)
{
    int hashCode = hashCodeFolding(key);
    Node *current = table[hashCode];
    while (current != NULL)
    {
        if (current->record->id == key)
        {
            return current->record;
        }
        current = current->link;
    }
    return NULL;
}

int main()
{
    Node **table = createHashTable();
    Record record1 = {123, "dhiraj", 22};
    Record record2 = {455, "harshal", 20};

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

    deleteRecor(table, record1.id);
    foundKey = searchRecord(table, keyToSearch);
    if (foundKey != NULL)
    {
        printf("Name %s found in the direct address table.\n", foundKey->name);
    }
    else
    {
        printf("Key not found !!! ");
    }

    return 0;
}