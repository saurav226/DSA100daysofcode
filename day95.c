// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->val >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next && curr->next->val < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    Node* buckets[n];

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        insertSorted(&buckets[index], arr[i]);
    }

    int idx = 0;

    for (int i = 0; i < n; i++) {
        Node* temp = buckets[i];
        while (temp) {
            arr[idx++] = temp->val;
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++)
        printf("%.6f ", arr[i]);

    return 0;
}