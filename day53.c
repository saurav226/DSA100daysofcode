// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    node->hd = 0;
    return node;
}

struct Node* buildTree(int arr[], int i, int n) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);
    return root;
}

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    root->hd = 0;
    enqueue(&q, root);

    int map[200][100];
    int count[200] = {0};

    int minHD = 100, maxHD = -100;

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        int hd = temp->hd + 100;

        map[hd][count[hd]++] = temp->data;

        if (temp->hd < minHD) minHD = temp->hd;
        if (temp->hd > maxHD) maxHD = temp->hd;

        if (temp->left) {
            temp->left->hd = temp->hd - 1;
            enqueue(&q, temp->left);
        }

        if (temp->right) {
            temp->right->hd = temp->hd + 1;
            enqueue(&q, temp->right);
        }
    }

    for (int i = minHD + 100; i <= maxHD + 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    verticalOrder(root);

    return 0;
}