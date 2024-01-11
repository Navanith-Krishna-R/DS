//1. To insert in a linked list
#include <stdio.h>
#include <stdlib.h>

// Describes a Node
struct Node {
    int data;
    struct Node *next;
};

// Inserts an element at the start of the node
struct Node *insertstart(struct Node *start, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = start;
    return ptr;
}

// Inserts a new Node at a given index
struct Node *insertIndex(struct Node *start, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = start;
    int i = 0;
    while (i < index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Index out of bounds:\n");
        free(ptr);
        return start;
    }
    ptr->next = p->next;
    p->next = ptr;
    return start;
}

// Insert at the end
struct Node *InsertEnd(struct Node *start, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (start == NULL) {
        // If the list is empty, the new node becomes the start
        return ptr;
    }

    struct Node *p = start;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return start;
}

// Prints all the elements present in a Node
void display(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct Node *first = NULL;

    char choice;
    int newData, newIndex;

    do {
        printf("\nChoose an option:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific index\n");
        printf("3. Insert at end\n");
        printf("4. Display the list\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the new element to insert at the beginning: ");
                scanf("%d", &newData);
                first = insertstart(first, newData);
                break;
            case '2':
                printf("Enter the new element to insert: ");
                scanf("%d", &newData);
                printf("Enter the index to insert at: ");
                scanf("%d", &newIndex);
                first = insertIndex(first, newData, newIndex);
                break;
            case '3':
                printf("Enter the new element to insert: ");
                scanf("%d", &newData);
                first = InsertEnd(first, newData);
                break;
            case '4':
                printf("Linked List:\n");
                display(first);
                break;
            case '5':
                printf("Quitting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != '5');

    return 0;
}
