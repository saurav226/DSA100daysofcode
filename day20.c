// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int countZeroSumSubarrays(int arr[], int n)
{
    long long prefixSum = 0;
    int count = 0;
    
    int offset = MAX;
    int size = 2 * MAX + 1;

    int *hash = (int*)calloc(size, sizeof(int));

    hash[offset] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (hash[prefixSum + offset] > 0)
            count += hash[prefixSum + offset];

        hash[prefixSum + offset]++;
    }

    free(hash);
    return count;
}