#include <stdio.h>
#include <stdlib.h>

int equalStacks(int *h1, int n1, int *h2, int n2, int *h3, int n3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n1; i++)
        sum1 += h1[i];
    for (int i = 0; i < n2; i++)
        sum2 += h2[i];
    for (int i = 0; i < n3; i++)
        sum3 += h3[i];

    while (!(sum1 == sum2 && sum2 == sum3)) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[0];
            for (int i = 0; i < n1 - 1; i++)
                h1[i] = h1[i + 1];
            n1--;
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[0];
            for (int i = 0; i < n2 - 1; i++)
                h2[i] = h2[i + 1];
            n2--;
        } else {
            sum3 -= h3[0];
            for (int i = 0; i < n3 - 1; i++)
                h3[i] = h3[i + 1];
            n3--;
        }
    }
    return sum1;
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int *h1 = (int *)malloc(n1 * sizeof(int));
    int *h2 = (int *)malloc(n2 * sizeof(int));
    int *h3 = (int *)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++)
        scanf("%d", &h1[i]);
    for (int i = 0; i < n2; i++)
        scanf("%d", &h2[i]);
    for (int i = 0; i < n3; i++)
        scanf("%d", &h3[i]);

    int result = equalStacks(h1, n1, h2, n2, h3, n3);

    printf("Maximum possible common height: %d\n", result);

    free(h1);
    free(h2);
    free(h3);

    return 0;
}
