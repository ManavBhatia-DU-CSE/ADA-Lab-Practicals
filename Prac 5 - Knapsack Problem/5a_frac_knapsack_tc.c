#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    double value;
    double weight;
    double ratio;
} Item;

void sortItems(Item items[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (items[j].ratio < items[j + 1].ratio){
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

double fractionalKnapsack(Item items[], int n, double capacity){
    double totalValue = 0.0;
    for (int i = 0; i < n; i++){
        items[i].ratio = items[i].value / items[i].weight;
    }

    sortItems(items, n);

    for (int i = 0; i < n; i++){
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity){
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            double fraction = capacity / items[i].weight;
            totalValue += fraction * items[i].value;
            capacity = 0;
        }
    }
    return totalValue;
}

int main(){
    int n, reps = 10000;
    double capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%lf", &capacity);

    srand(time(NULL));

    Item *items = (Item *)malloc(n * sizeof(Item));
    clock_t start, end;
    double total_time = 0;

    for (int r = 0; r < reps; r++){
        for (int i = 0; i < n; i++){
            items[i].weight = (rand() % 100) + 1; // random 1–100
            items[i].value = (rand() % 200) + 1;  // random 1–200
        }

        start = clock();
        double maxValue = fractionalKnapsack(items, n, capacity);
        end = clock();
        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    printf("\nAverage time for n=%d: %lf seconds\n", n, total_time / reps);
    free(items);
    return 0;
}