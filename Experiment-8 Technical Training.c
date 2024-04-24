#include <stdio.h>
#include <limits.h>
#include <math.h>

int unboundedKnapsack(int k, int arr[], int n) {
    int dp[k + 1];
    for (int i = 0; i <= k; i++) {
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        for (int capacity = num; capacity <= k; capacity++) {
            dp[capacity] = fmax(dp[capacity], dp[capacity - num] + num);
        }
    }
    return dp[k];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        int result = unboundedKnapsack(k, arr, n);
        printf("Maximum sum: %d\n", result);
    }
    return 0;
}
