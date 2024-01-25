#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        return newNode;
    }

    rear->next = newNode;
    return newNode;
}

struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue underflow\n");
        return NULL;
    }
    struct Node* temp = front;
    front = front->next;
    free(temp);
    return front;
}

void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, element;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                rear = enqueue(rear, element);
                if (front == NULL) {
                    front = rear; // Set front to the first element if it's the first element
                }
                break;
            case 2:
                front = dequeue(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
