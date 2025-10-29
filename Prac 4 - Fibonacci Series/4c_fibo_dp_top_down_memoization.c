#include <stdio.h>
#include <time.h>

long long memo[1000];

long long fibTopDown(int n){
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fibTopDown(n - 1) + fibTopDown(n - 2);
    return memo[n];
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int reps = 100000; // number of repetitions
    long long result = 0;

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    clock_t start = clock();
    for (int i = 0; i < reps; i++){
        // Reset memo array for each repetition
        for (int j = 0; j <= n; j++)
            memo[j] = -1;

        result = fibTopDown(n);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci(%d) = %lld\n", n, result);
    printf("Time taken = %f seconds\n", time_taken);
    return 0;
}