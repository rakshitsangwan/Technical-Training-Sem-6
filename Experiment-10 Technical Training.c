#include <stdbool.h>
#include <stdio.h>

bool isSubsetSum(int* set, int n, int sum) {
    bool dp[n + 1][sum + 1];
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }
    
    return dp[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int sum2 = 30;
    int n = sizeof(set) / sizeof(set[0]);
    
    if (isSubsetSum(set, n, sum1))
        printf("Subset with sum %d exists.\n", sum1);
    else
        printf("Subset with sum %d does not exist.\n", sum1);
    
    if (isSubsetSum(set, n, sum2))
        printf("Subset with sum %d exists.\n", sum2);
    else
        printf("Subset with sum %d does not exist.\n", sum2);
    
    return 0;
}
