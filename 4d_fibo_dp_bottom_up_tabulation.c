#include <stdio.h>
#include <time.h>

long long fibBottomUp(int n){
    if (n <= 1)
        return n;
    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int reps = 100000; // number of repetitions
    long long result = 0;

    clock_t start = clock();
    for (int i = 0; i < reps; i++)
    {
        result = fibBottomUp(n);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci(%d) = %lld\n", n, result);
    printf("Time taken = %f seconds\n", time_taken);
    return 0;
}