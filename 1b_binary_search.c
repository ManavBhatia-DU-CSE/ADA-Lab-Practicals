#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary Search function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        arr[i] = i;  // Sorted array [0, 1, 2, ..., n-1]
    }

    int key = n - 1; // Worst-case: last element

    // Repeat search many times to measure properly
    long long repetitions = 1000000;  // 1 million runs
    clock_t start = clock();
    for (long long i = 0; i < repetitions; i++) {
        binarySearch(arr, n, key);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) / repetitions;
    printf("Time taken for binary search of %d elements: %.10f seconds\n", n, time_taken);

    free(arr);
    return 0;
}