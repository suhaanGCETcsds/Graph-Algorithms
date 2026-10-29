
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node *next;
};

struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

struct Node* createNode(int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q, int value) {
    struct QueueNode *newNode =
        malloc(sizeof(struct QueueNode));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q) {
    struct QueueNode *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

void BFS(struct Node *adj[], int vertices, int start) {
    int visited[MAX] = {0};
    struct Queue q;

    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS Traversal: ");

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        struct Node *temp = adj[current];

        while (temp != NULL) {
            int v = temp->vertex;

            if (!visited[v]) {
                visited[v] = 1;
                enqueue(&q, v);
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

int main(void) {
    struct Node *adj[MAX] = {NULL};
    int vertices, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 ||
        edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges\n");
        return 1;
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        if (scanf("%d %d", &u, &v) != 2 ||
            u < 0 || u >= vertices ||
            v < 0 || v >= vertices || u == v) {
            printf("Invalid edge\n");
            return 1;
        }

        addEdge(adj, u, v);
    }

    printf("Enter starting vertex: ");
    if (scanf("%d", &start) != 1 ||
        start < 0 || start >= vertices) {
        printf("Invalid starting vertex\n");
        return 1;
    }

    BFS(adj, vertices, start);

    for (int i = 0; i < vertices; i++) {
        while (adj[i] != NULL) {
            struct Node *temp = adj[i];
            adj[i] = adj[i]->next;
            free(temp);
        }
    }

    return 0;
}
