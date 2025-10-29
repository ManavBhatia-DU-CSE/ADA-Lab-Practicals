#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16  // size of square matrix (change as needed)
#define ITER 10000 // number of iterations

// Function to multiply two matrices
void multiply_matrices(int A[N][N], int B[N][N], int result[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            result[i][j] = 0;
            for (int k = 0; k < N; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    int A[N][N], B[N][N], result[N][N];
    srand(time(NULL)); // seed random generator

    // Generate random matrices A and B
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = rand() % 10; // numbers from 0-9
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            B[i][j] = rand() % 10;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Start measuring time
    clock_t start = clock();

    for (int i = 0; i < ITER; i++){
        multiply_matrices(A, B, result);
    }

    // End measuring time
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print result matrix
    printf("\nResultant Matrix after multiplication:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");   
    }

    // Print time
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}