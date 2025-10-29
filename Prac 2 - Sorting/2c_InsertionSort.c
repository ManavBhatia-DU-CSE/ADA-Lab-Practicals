// 2 (c) Design and implement C Program to sort a given set of n integer elements using Insertion Sort method and compute its time complexity. Run the program for varied values of n, and record the time taken to sort. 
// Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort function
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, repetitions = 1000;
    printf("Enter array size: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL));
    clock_t start, end;

    start = clock();
    for (int r = 0; r < repetitions; r++) {
        // Regenerate random array for each repetition
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }
        insertionSort(arr, n);
    }
    end = clock();

    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    double avg_time = total_time / repetitions;

    printf("Array size: %d | Avg Time: %lf seconds\n", n, avg_time);

    free(arr);
    return 0;
}