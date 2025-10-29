// 1 (a) Write a C program to implement linear search algorithm. 
// Repeat the experiment for different values of n where n is the number of elements in the list to be searched and plot a graph of the time taken versus n

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  
    }
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key){
            return i;
        }
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

    generateRandomArray(arr, n);

    arr[n-1] = n-1;
    int key = n-1; // Considering Worst-Case

    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {
        linearSearch(arr, n, key);
    }
    clock_t end = clock();

    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) / 1000.0;
    printf("Time taken for linear search of %d elements: %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}