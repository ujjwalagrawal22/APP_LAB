#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10 // Define the hash table size

// Node structure for each key-value pair
typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

// Hash map structure
typedef struct {
    Node **buckets;
} HashMap;

// Hash function: Computes an index for a given key
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key; // A prime-based hash function
        key++;
    }
    return hash % TABLE_SIZE;
}

// Create a new hash map
HashMap* create_table() {
    HashMap *table = malloc(sizeof(HashMap));
    table->buckets = calloc(TABLE_SIZE, sizeof(Node *));
    return table;
}

// Insert a key-value pair into the hash map
void insert(HashMap *table, const char *key, int value) {
    unsigned int index = hash(key);
    Node *new_node = malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

// Search for a key in the hash map and return its value
int search(HashMap *table, const char *key) {
    unsigned int index = hash(key);
    Node *current = table->buckets[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Return -1 if key not found
}

// Delete a key-value pair from the hash map
void delete(HashMap *table, const char *key) {  //read once more 
    unsigned int index = hash(key);
    Node *current = table->buckets[index];
    Node *prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Free all memory allocated for the hash map
void free_table(HashMap *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = table->buckets[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp->key);  //see the reason for this, it shouldn't be necessary 
            free(temp);
        }
    }
    free(table->buckets);    //see the reason for this, it shouldn't be necessary 
    free(table);
}

// Example usage
int main() {
    HashMap *table = create_table();
    
    insert(table, "apple", 1);
    insert(table, "banana", 2);
    insert(table, "cherry", 3);

    printf("Value for 'apple': %d\n", search(table, "apple"));
    printf("Value for 'banana': %d\n", search(table, "banana"));
    printf("Value for 'cherry': %d\n", search(table, "cherry"));

    delete(table, "banana");
    printf("Value for 'banana' after deletion: %d\n", search(table, "banana"));

    free_table(table);
    return 0;
}
