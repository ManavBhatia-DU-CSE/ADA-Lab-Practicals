#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsackMemo(int n, int W, int values[], int weights[], int **dp){
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (weights[n - 1] <= W)
        dp[n][W] = max(values[n - 1] + knapsackMemo(n - 1, W - weights[n - 1], values, weights, dp),
                       knapsackMemo(n - 1, W, values, weights, dp));
    else
        dp[n][W] = knapsackMemo(n - 1, W, values, weights, dp);

    return dp[n][W];
}

int main(){
    int n, capacity;
    int reps = 500;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));

    // Random generation for values and weights
    srand(time(0));
    for (int i = 0; i < n; i++){
        values[i] = rand() % 100 + 1; // random values (1–100)
        weights[i] = rand() % 20 + 1; // random weights (1–20)
    }

    clock_t start, end;
    double total_time = 0.0;
    int result = 0; // store last result safely

    for (int r = 0; r < reps; r++){
        // Recreate DP table for each repetition to reset memoization
        int **dp = (int **)malloc((n + 1) * sizeof(int *));
        for (int i = 0; i <= n; i++){
            dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
            for (int j = 0; j <= capacity; j++)
                dp[i][j] = -1;
        }

        start = clock();
        result = knapsackMemo(n, capacity, values, weights, dp);
        end = clock();

        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;

        for (int i = 0; i <= n; i++){
            free(dp[i]);
        }
        free(dp);
    }

    double avg_time = total_time / reps;

    printf("\nAverage time for n=%d: %lf seconds\n", n, avg_time);
    free(values);
    free(weights);
    return 0;
}