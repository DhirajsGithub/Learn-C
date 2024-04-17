#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a structure for key-value pair
typedef struct KeyValue
{
    char key[50];
    int value;
    int isDeleted; // To mark deleted entries in linear probing
} KeyValue;

// Define a structure for the dictionary using double hashing
typedef struct DictionaryDoubleHashing
{
    KeyValue *entries;
    int size;
} DictionaryDoubleHashing;

// Hash function 1
int hash1(char *key, int size)
{
    int hash = 0;
    while (*key)
    {
        hash = (hash * 31 + *key) % size;
        key++;
    }
    return hash;
}

// Hash function 2 for double hashing
int hash2(char *key, int size)
{
    int hash = 0;
    while (*key)
    {
        hash = (hash * 17 + *key) % size;
        key++;
    }
    return (hash != 0) ? size - hash : 1;
}

// Initialize a dictionary using double hashing
void initDoubleHashing(DictionaryDoubleHashing *dict, int size)
{
    dict->size = size;
    dict->entries = (KeyValue *)malloc(size * sizeof(KeyValue));
    for (int i = 0; i < size; i++)
    {
        strcpy(dict->entries[i].key, "");
        dict->entries[i].value = -1; // assuming -1 represents an empty slot
        dict->entries[i].isDeleted = 0;
    }
}

// Insert a key-value pair into the dictionary using double hashing
void insertDoubleHashing(DictionaryDoubleHashing *dict, char *key, int value)
{
    int index = hash1(key, dict->size);
    int step = hash2(key, dict->size);

    while (dict->entries[index].value != -1 && strcmp(dict->entries[index].key, key) != 0)
    {
        index = (index + step) % dict->size; // linear probing
    }

    strcpy(dict->entries[index].key, key);
    dict->entries[index].value = value;
}

// Search for a key in the dictionary using double hashing
int searchDoubleHashing(DictionaryDoubleHashing *dict, char *key)
{
    int index = hash1(key, dict->size);
    int step = hash2(key, dict->size);

    while (dict->entries[index].value != -1)
    {
        if (strcmp(dict->entries[index].key, key) == 0 && !dict->entries[index].isDeleted)
        {
            return dict->entries[index].value;
        }
        index = (index + step) % dict->size; // linear probing
    }

    return -1; // Key not found
}

// Delete a key from the dictionary using double hashing
void deleteDoubleHashing(DictionaryDoubleHashing *dict, char *key)
{
    int index = hash1(key, dict->size);
    int step = hash2(key, dict->size);

    while (dict->entries[index].value != -1)
    {
        if (strcmp(dict->entries[index].key, key) == 0 && !dict->entries[index].isDeleted)
        {
            dict->entries[index].isDeleted = 1; // Mark as deleted without actually removing the entry
            return;
        }
        index = (index + step) % dict->size; // linear probing
    }
}

int main()
{
    // Example usage of dictionary with double hashing
    DictionaryDoubleHashing doubleHashDict;
    initDoubleHashing(&doubleHashDict, TABLE_SIZE);
    insertDoubleHashing(&doubleHashDict, "apple", 5);
    insertDoubleHashing(&doubleHashDict, "banana", 8);

    printf("Double Hashing Dictionary: apple=%d, banana=%d\n", searchDoubleHashing(&doubleHashDict, "apple"),
           searchDoubleHashing(&doubleHashDict, "banana"));

    deleteDoubleHashing(&doubleHashDict, "apple");
    printf("After deleting 'apple': apple=%d, banana=%d\n", searchDoubleHashing(&doubleHashDict, "apple"),
           searchDoubleHashing(&doubleHashDict, "banana"));

    return 0;
}
