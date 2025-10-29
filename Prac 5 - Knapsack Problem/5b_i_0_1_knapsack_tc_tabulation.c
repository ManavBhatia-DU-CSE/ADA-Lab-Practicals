#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack01(int values[], int weights[], int n, int capacity){
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= capacity; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int result = dp[n][capacity];
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main(){
    int n, capacity, reps = 500;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    srand(time(NULL));
    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));

    clock_t start, end;
    double total_time = 0;

    for (int r = 0; r < reps; r++){
        for (int i = 0; i < n; i++){
            weights[i] = (rand() % 100) + 1; // random 1–100
            values[i] = (rand() % 200) + 1;  // random 1–200
        }

        start = clock();
        int maxValue = knapsack01(values, weights, n, capacity);
        end = clock();

        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    printf("\nAverage time for n=%d: %lf seconds\n", n, total_time / reps);
    free(values);
    free(weights);
    return 0;
}