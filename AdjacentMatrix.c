
#include <stdio.h>

#define MAX 10

int main(void) {
    int graph[MAX][MAX];
    int vertices, edges;
    int i, j, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges for an undirected graph\n");
        return 1;
    }

    for (i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= vertices ||
            v < 0 || v >= vertices || u == v) {
            printf("Invalid edge\n");
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }


    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
