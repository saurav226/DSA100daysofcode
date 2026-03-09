// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20
#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

int findMinIndex() {
    if (size == 0) return -1;
    
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void insert(int x) {
    if (size < MAX) {
        pq[size++] = x;
    }
}

void delete() {
    int minIndex = findMinIndex();
    
    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void peek() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[minIndex]);
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {
            delete();
        }
        else if (op[0] == 'p') {
            peek();
        }
    }

    return 0;
}