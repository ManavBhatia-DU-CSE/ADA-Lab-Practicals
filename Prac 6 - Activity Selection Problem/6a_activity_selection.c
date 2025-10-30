#include <stdio.h>

// Quick Sort
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int start[], int finish[], int low, int high){
    int pivot = finish[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (finish[j] <= pivot){
            i++;
            swap(&finish[i], &finish[j]);
            swap(&start[i], &start[j]);
        }
    }
    swap(&finish[i + 1], &finish[high]);
    swap(&start[i + 1], &start[high]);
    return i + 1;
}

void quickSort(int start[], int finish[], int low, int high){
    if (low < high){
        int pi = partition(start, finish, low, high);
        quickSort(start, finish, low, pi - 1);
        quickSort(start, finish, pi + 1, high);
    }
}

int main(){
    int n = 6;
    int start[] = {3, 1, 5, 0, 5, 8};
    int finish[] = {4, 2, 7, 6, 9, 9};
    int total_time;

    // Display original activities
    printf("Original Activities:\n");
    printf("Activity\tStart\tFinish\n");
    for (int i = 0; i < n; i++){
        printf("A%d\t\t%d\t%d\n", i + 1, start[i], finish[i]);
    }

    // Sort activities using Quick Sort
    quickSort(start, finish, 0, n - 1);

    // Display sorted activities
    printf("\nActivities Sorted by Finish Time:\n");
    printf("Activity\tStart\tFinish\n");
    for (int i = 0; i < n; i++){
        printf("A%d\t\t%d\t%d\n", i + 1, start[i], finish[i]);
    }

    // Take input of total available time
    printf("\nEnter total available time: ");
    scanf("%d", &total_time);

    // Check if all activities exceed the total available time limit
    if (finish[0] > total_time){
        printf("\nNo activities can be selected within the given time limit.\n");
        return 0;
    }

    // Greedy Algorithm (Iterative Approach)
    printf("\nSelected Activities:\n");
    int i = 0, count = 0;
    if (finish[i] <= total_time){
        printf("A%d (Start: %d, Finish: %d)\n", i + 1, start[i], finish[i]);
        count = 1;
    }

    for (int j = 1; j < n; j++){
        if (start[j] >= finish[i] && finish[j] <= total_time){
            printf("A%d (Start: %d, Finish: %d)\n", j + 1, start[j], finish[j]);
            count++;
            i = j;
        }
    }
    
    if (count == 0)
        printf("No activities can be selected within the given time limit.\n");
    else
        printf("Total number of activities selected: %d\n", count);

    return 0;
}