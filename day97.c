// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.
#include <stdio.h>
#include <stdlib.h>

int cmpStart(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int cmpEnd(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int intervals[][2], int n) {
    qsort(intervals, n, sizeof(intervals[0]), cmpStart);

    int* heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    heap[size++] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        qsort(heap, size, sizeof(int), cmpEnd);

        if (intervals[i][0] >= heap[0]) {
            heap[0] = intervals[i][1];
        } else {
            heap[size++] = intervals[i][1];
        }
    }

    return size;
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);

    printf("%d\n", minMeetingRooms(intervals, n));

    return 0;
}