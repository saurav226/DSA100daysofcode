// Problem Statement
// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

// Input Format
// An integer array arr[].

// Output Format
// Print the length of the longest subarray with sum equal to zero.

// Sample Input
// 15 -2 2 -8 1 7 10 23

// Sample Output
// 5

// Explanation
// The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefixSum = 0;
    int maxLen = 0;

    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++)
        hash[i] = -2;

    hash[MAX] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int index = prefixSum + MAX;

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}