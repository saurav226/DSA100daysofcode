// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int i, int n){
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

void inorder(struct Node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    inorder(root);

    return 0;
}