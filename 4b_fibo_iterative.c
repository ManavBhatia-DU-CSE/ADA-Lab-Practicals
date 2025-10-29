#include <stdio.h>
#include <time.h>

long long fibIterative(int n){
    if (n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int reps = 100000; // number of repetitions
    long long result = 0;
    clock_t start = clock();
    for (int i = 0; i < reps; i++){
        result = fibIterative(n);
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci(%d) = %lld\n", n, result);
    printf("Time taken = %f seconds\n", time_taken);
    return 0;
}