#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_NODES - 1)
        printf("\nQueue is Full!!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nQueue is Empty!!");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void BFS(int start, int nodes) {
    struct Queue* queue = createQueue();

    visited[start] = 1;
    enqueue(queue, start);

    printf("Breadth First Search starting from node %d: ", start);

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);

        for (int i = 0; i < nodes; i++) {
            if (adjMatrix[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int nodes, startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter adjacency matrix for the graph:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    BFS(startNode, nodes);

    return 0;
}
