// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
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

struct Node* queue[1000];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    front = 0;
    rear = -1;

    enqueue(root);
    int level = 0;

    while (!isEmpty()) {
        int size = rear - front + 1;
        int temp[size];

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue();
            temp[i] = node->data;

            if (node->left)
                enqueue(node->left);

            if (node->right)
                enqueue(node->right);
        }

        if (level % 2 == 0) {
            for (int i = 0; i < size; i++)
                printf("%d ", temp[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        }

        level++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    zigzagTraversal(root);

    return 0;
}