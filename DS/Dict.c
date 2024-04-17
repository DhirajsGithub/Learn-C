#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for key-value pair
typedef struct KeyValue
{
    char key[50];
    int value;
    struct KeyValue *next; // for chaining in case of collisions
} KeyValue;

// Define a structure for the dictionary using a linear list (array)
typedef struct DictionaryArray
{
    KeyValue *entries;
    int size;
} DictionaryArray;

// Initialize a dictionary using a linear list (array)
void initArray(DictionaryArray *dict, int size)
{
    dict->size = size;
    dict->entries = (KeyValue *)malloc(size * sizeof(KeyValue));
    for (int i = 0; i < size; i++)
    {
        strcpy(dict->entries[i].key, "");
        dict->entries[i].value = -1; // assuming -1 represents an empty slot
        dict->entries[i].next = NULL;
    }
}

// Insert a key-value pair into the dictionary using a linear list (array)
void insertArray(DictionaryArray *dict, char *key, int value)
{
    // Assuming a simple hash function for demonstration purposes
    int index = strlen(key) % dict->size;

    if (dict->entries[index].value == -1)
    {
        strcpy(dict->entries[index].key, key);
        dict->entries[index].value = value;
    }
    else
    {
        // Collision resolution using chaining
        KeyValue *newEntry = (KeyValue *)malloc(sizeof(KeyValue));
        strcpy(newEntry->key, key);
        newEntry->value = value;
        newEntry->next = dict->entries[index].next;
        dict->entries[index].next = newEntry;
    }
}

// Search for a key in the dictionary using a linear list (array)
int searchArray(DictionaryArray *dict, char *key)
{
    int index = strlen(key) % dict->size;

    // why &dict and not dict
    // because dict is a pointer to a structure and we want to access the structure
    KeyValue *current = &dict->entries[index];
    // if collision not occur then current will be null and we will not enter the loop
    // but the value is already ad
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

// Define a structure for the dictionary using a linked list
typedef struct DictionaryLinkedList
{
    KeyValue *head;
} DictionaryLinkedList;

// Initialize a dictionary using a linked list
void initLinkedList(DictionaryLinkedList *dict)
{
    dict->head = NULL;
}

// Insert a key-value pair into the dictionary using a linked list
void insertLinkedList(DictionaryLinkedList *dict, char *key, int value)
{
    KeyValue *newEntry = (KeyValue *)malloc(sizeof(KeyValue));
    strcpy(newEntry->key, key);
    newEntry->value = value;
    newEntry->next = dict->head;
    dict->head = newEntry;
}

// Search for a key in the dictionary using a linked list
int searchLinkedList(DictionaryLinkedList *dict, char *key)
{
    KeyValue *current = dict->head;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

int main()
{
    // Example usage of dictionary with linear list (array)
    DictionaryArray arrayDict;
    initArray(&arrayDict, 10);
    insertArray(&arrayDict, "apple", 5);
    insertArray(&arrayDict, "banana", 8);
    printf("Array Dictionary: apple=%d, banana=%d\n", searchArray(&arrayDict, "apple"), searchArray(&arrayDict, "banana"));

    // Example usage of dictionary with linked list
    DictionaryLinkedList linkedListDict;
    initLinkedList(&linkedListDict);
    insertLinkedList(&linkedListDict, "apple", 5);
    insertLinkedList(&linkedListDict, "banana", 8);
    printf("Linked List Dictionary: apple=%d, banana=%d\n", searchLinkedList(&linkedListDict, "apple"), searchLinkedList(&linkedListDict, "banana"));

    return 0;
}
