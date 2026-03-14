// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10
#include <stdio.h>

#define MAX 100

int main()
{
    int n;
    int queue[MAX], stack[MAX];
    int top = -1;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    for(int i = 0; i < n; i++)
        stack[++top] = queue[i];

    while(top >= 0)
        printf("%d ", stack[top--]);

    return 0;
}