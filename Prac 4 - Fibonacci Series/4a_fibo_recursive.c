#include <stdio.h>
#include <time.h>

long long fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start = clock();
    long long result = fibRecursive(n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Recursive Fibonacci(%d) = %lld\n", n, result);
    printf("Time taken = %f seconds\n", time_taken);
    return 0;
}
