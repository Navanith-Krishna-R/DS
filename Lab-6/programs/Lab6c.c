#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* first, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL) {
        return newNode;
    }

    struct Node* ptr = first;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    return first;
}

void sort(struct Node* first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* ptr;
    struct Node* p;

    for (ptr = first; ptr != NULL; ptr = ptr->next) {
        bool swapped = false;
        for (p = first; p->next != NULL; p = p->next) {
            if (p->data > (p->next)->data) {
                int temp = p->data;
                p->data = (p->next)->data;
                (p->next)->data = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    struct Node* p1 = first;
    while (p1 != NULL) {
        printf(" Element: %d", p1->data);
        p1 = p1->next;
    }
    printf("\n");

}

void display(struct Node* first){
    struct Node* p1 = first;
    while (p1 != NULL) {
        printf(" Element: %d", p1->data);
        p1 = p1->next;
    }
    printf("\n");

}

struct Node* reverse(struct Node* first) {
    struct Node* prev = NULL;
    struct Node* current = first;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    struct Node* first = NULL;
    int n, ele;

    do {
        printf("\n1. Add Element\n2. Sort\n3. Reverse\n4. Display\n5. Exit\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter the data:\n");
                scanf("%d", &ele);
                first = insert(first, ele);
                break;
            case 2:
                sort(first);
                break;
            case 3:
                first = reverse(first);
                printf("List reversed.\n");
                break;
            case 4:
                display(first);
                break;
            case 5:
                exit(0);
            default:
                printf("Enter correct choice\n");
        }
    } while (5);

    return 0;
}
