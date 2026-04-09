// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    indegree[v]++;
}

void topoSort(int V) {
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    printf("Topological Order: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while (temp) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0)
                queue[rear++] = temp->vertex;

            temp = temp->next;
        }
    }

    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    topoSort(V);

    return 0;
}