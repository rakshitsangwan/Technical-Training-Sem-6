#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int calculateCost(int **graph, int *tour, int n) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++) {
        cost += graph[tour[i]][tour[i + 1]];
    }
    cost += graph[tour[n - 1]][tour[0]];
    return cost;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *arr, int start, int end, int **graph, int startCity, int n, int *minCost) {
    if (start == end) {
        if (arr[0] == startCity) {
            int currentCost = calculateCost(graph, arr, n);
            *minCost = (currentCost < *minCost) ? currentCost : *minCost;
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end, graph, startCity, n, minCost);
            swap(&arr[start], &arr[i]);
        }
    }
}

int travelingSalesmanNaive(int **graph, int start, int n) {
    int *tour = (int *)malloc(n * sizeof(int));
    if (tour == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        tour[i] = i;
    }

    int minCost = INT_MAX;
    permute(tour, 0, n - 1, graph, start, n, &minCost);

    free(tour);
    return minCost;
}

int main() {
    int n = 4;
    int **graph = (int **)malloc(n * sizeof(int *));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
        if (graph[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    graph[0][0] = 0;
    graph[0][1] = 10;
    graph[0][2] = 15;
    graph[0][3] = 20;
    graph[1][0] = 10;
    graph[1][1] = 0;
    graph[1][2] = 35;
    graph[1][3] = 25;
    graph[2][0] = 15;
    graph[2][1] = 35;
    graph[2][2] = 0;
    graph[2][3] = 30;
    graph[3][0] = 20;
    graph[3][1] = 25;
    graph[3][2] = 30;
    graph[3][3] = 0;

    int startCity = 0;
    int minCost = travelingSalesmanNaive(graph, startCity, n);
    printf("Minimum cost of the tour: %d\n", minCost);

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
