// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);

    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int res[n][2];
    int idx = 0;

    res[0][0] = intervals[0][0];
    res[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= res[idx][1]) {
            if (intervals[i][1] > res[idx][1])
                res[idx][1] = intervals[i][1];
        } else {
            idx++;
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
        }
    }

    for (int i = 0; i <= idx; i++)
        printf("%d %d\n", res[i][0], res[i][1]);

    return 0;
}