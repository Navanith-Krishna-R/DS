#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void insert(int key);
void search(int key);
void displayHashTable();

int main() {
    // Initialize the hash table with 0
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = 0;
    }

    int choice, key;

    do {
        printf("\n--- Hash Table Operations ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                displayHashTable();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}

void insert(int key) {
    int i = 0;
    int hkey = key % TABLE_SIZE;
    int index;

    do {
        index = (hkey + i) % TABLE_SIZE;
        if (hashTable[index] == 0) {
            hashTable[index] = key;
            printf("Value %d inserted at index %d\n", key, index);
            return;
        } else {
            i++;
        }
    } while (i < TABLE_SIZE);

    printf("Hash table is full. Cannot insert %d\n", key);
}

void search(int key) {
    int i = 0;
    int hkey = key % TABLE_SIZE;
    int index;

    do {
        index = (hkey + i) % TABLE_SIZE;
        if (hashTable[index] == key) {
            printf("Value %d found at index %d\n", key, index);
            return;
        } else {
            i++;
        }
    } while (i < TABLE_SIZE);

    printf("Value %d not found in the hash table\n", key);
}

void displayHashTable() {
    printf("\n--- Hash Table Contents ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        if (hashTable[i] != 0)
            printf("%d", hashTable[i]);
        else
            printf("Empty");
        printf("\n");
    }
}
