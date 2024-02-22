#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adjMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void DFS(int node, int nodes) {
    visited[node] = 1;
    for (int i = 0; i < nodes; i++) {
        if (adjMatrix[node][i] && !visited[i]) {
            DFS(i, nodes);
        }
    }
}

int isConnected(int nodes) {
    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    DFS(0, nodes);

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter adjacency matrix for the graph:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    if (isConnected(nodes)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
