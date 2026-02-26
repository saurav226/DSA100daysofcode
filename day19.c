// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

// Example:
// Input:
// 5
// 1 60 -10 70 -80

// Output:
// -10 1

// Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void closestToZero(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = INT_MAX;
    int minLeft = 0, minRight = 0;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum))
        {
            minSum = sum;
            minLeft = left;
            minRight = right;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", arr[minLeft], arr[minRight]);
}