// 2 (b)Design and implement C Program to sort a given set of n integer elements using Quick Sort method and compute its time complexity. Run the program for varied values of n, and record the time taken to sort. 
// Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, reps = 1000;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    int *temp = (int*)malloc(n * sizeof(int));

    srand(time(0));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10000;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int r = 0; r < reps; r++){
        for (int i = 0; i < n; i++){
            temp[i] = arr[i];
        }
        quickSort(temp, 0, n - 1);
    }
    end = clock();

    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    double avg_time = total_time / reps;

    printf("Array size: %d | Avg Time: %lf seconds\n", n, avg_time);

    free(arr);
    free(temp);
    return 0;
}