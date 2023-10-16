#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Entry {
    char* key;
    int value;
    struct Entry* next;
} Entry;

typedef struct Dictionary {
    Entry* table[TABLE_SIZE];
} Dictionary;

void initDictionary(Dictionary* dict) {
    for(size_t i = 0; i < TABLE_SIZE; i++) {
        dict->table[i] = NULL;
    }
}

unsigned int hash(char* key) {
    unsigned int hash = 0;
    while(*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % TABLE_SIZE;
}

void insert(Dictionary* dict, char* key, int value) {
    unsigned int index = hash(key);

    // Allocate memory for new entry

    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = NULL;

    // Add the entry to the dictionary

    if(dict->table[index] == NULL) {
        dict->table[index] = newEntry;
    } else {
        // handle collisions
        Entry* current = dict->table[index];
        while(current->next != NULL) {
            
            current = current->next;
        }
        printf("woah! collision detected, fixed: %d\n", current->value);
        current->next = newEntry;
    }
}

int search(Dictionary* dict, char* key) {
    unsigned int index = hash(key);
    Entry* current = dict->table[index];

    while(current != NULL) {
        if(strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // key not found
}

int delete(Dictionary* dict, char* key) {
    unsigned int index = hash(key);
    Entry* current = dict->table[index];
    Entry* previous = NULL;

    while(current != NULL) {
        if(strcmp(current->key, key) == 0) {
            // Found the entry to delete
            if(previous == NULL) {
                // If it's the first entry, update the table, essentially skipping the 1st element
                dict->table[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->key);
            free(current);
            return 0; // element deleted        

        }
        previous = current;
        current = current->next;
    }
    printf("key not found: %s\n", key);
    return -1; // key not found
}