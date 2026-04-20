// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005

typedef struct {
    int v, dist;
} Node;

typedef struct {
    Node heap[MAX];
    int size;
} MinHeap;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap *h, int v, int dist) {
    int i = ++h->size;
    h->heap[i].v = v;
    h->heap[i].dist = dist;

    while (i > 1 && h->heap[i].dist < h->heap[i/2].dist) {
        swap(&h->heap[i], &h->heap[i/2]);
        i /= 2;
    }
}

Node pop(MinHeap *h) {
    Node root = h->heap[1];
    h->heap[1] = h->heap[h->size--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2*i, right = 2*i + 1;

        if (left <= h->size && h->heap[left].dist < h->heap[smallest].dist)
            smallest = left;
        if (right <= h->size && h->heap[right].dist < h->heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&h->heap[i], &h->heap[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

int isEmpty(MinHeap *h) {
    return h->size == 0;
}

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u];
    adj[u] = e;

    // undirected
    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u;
    e2->weight = w;
    e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[source] = 0;
    push(&h, source, 0);

    while (!isEmpty(&h)) {
        Node curr = pop(&h);
        int u = curr.v;

        if (curr.dist > dist[u]) continue;

        Edge* temp = adj[u];
        while (temp) {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}