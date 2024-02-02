
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* newNode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

struct Node* Insert(struct Node* first, int data, int pos) {
    struct Node* ptr = newNode(data);
    if (pos == 0) {
        ptr->next = first;
        if (first != NULL) {
            first->prev = ptr;
        }
        return ptr;  // Update to return the new head of the list
    }
    struct Node* p2 = first;
    struct Node* p1 = first;
    int i = 0;
    while (i != pos + 1 && p2 != NULL) {
        p1 = p2;
        p2 = p2->next;
        i++;
    }
    if (i < pos) {
        printf("Invalid position\n");
        free(ptr);  // Free the allocated memory before returning
        return first;
    }
    p1->next = ptr;
    ptr->prev = p1;
    ptr->next = p2;
    if (p2 != NULL) {
        p2->prev = ptr;  // Corrected line
    }
    return first;
}


struct Node* Delete(struct Node* first, int pos) {
    if (pos == 0) {
        struct Node* ptr = first;
        if (first->next != NULL) {
            first = first->next;
            first->prev = NULL;
        } else {
            first = NULL;
        }
        free(ptr);
        return first;  // Update to return the new head of the list
    }
    struct Node* p2 = first;
    struct Node* p1 = first;
    int i = 0;
    while (i != pos && p2 != NULL) {
        p1 = p2;
        p2 = p2->next;
        i++;
    }
    if (i != pos) {
        printf("Invalid position\n");
        return first;
    }
    p1->next = p2->next;
    if (p2->next != NULL) {
        p2->next->prev = p1;
    }
    free(p2);
    return first;
}



void display(struct Node* first) {
    if(first==NULL){
        printf("Empty List\n");
    }
    struct Node* p = first;
    while (p != NULL) {
        printf("Element %d\n", p->data);
        p = p->next;
    }
}

int main(){
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert at a specific position\n");
        printf("2. Delete at specified index\n");
        printf("3. display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = Insert(head, data, pos);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = Delete(head,pos);
                break;

            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
