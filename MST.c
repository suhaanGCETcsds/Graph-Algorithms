
#include <stdio.h>

#define MAX 100
#define INF 999999

int main(void) {
    int cost[MAX][MAX];
    int selected[MAX] = {0};
    int n, i, j, edges = 0;
    int u = -1, v = -1;
    int min, totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter cost adjacency matrix:\n");
    printf("Enter 0 for no edge (except diagonal)\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (i == j) {
                cost[i][j] = INF;
            } else if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("MST does not exist: graph is disconnected\n");
            return 1;
        }

        printf("%d - %d : %d\n", u, v, min);

        totalCost += min;
        selected[v] = 1;
        edges++;
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
