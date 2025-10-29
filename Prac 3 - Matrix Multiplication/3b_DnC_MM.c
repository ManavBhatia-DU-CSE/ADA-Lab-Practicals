#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16 // Matrix size (must be power of 2 here)
#define ITER 10000

// Function to add two matrices
void add_matrix(int A[N][N], int B[N][N], int C[N][N], int size){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void sub_matrix(int A[N][N], int B[N][N], int C[N][N], int size){
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Recursive Divide and Conquer multiplication
void multiply_dnc(int A[N][N], int B[N][N], int C[N][N], int size){
    if (size == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    int a11[newSize][newSize], a12[newSize][newSize], a21[newSize][newSize], a22[newSize][newSize];
    int b11[newSize][newSize], b12[newSize][newSize], b21[newSize][newSize], b22[newSize][newSize];
    int c11[newSize][newSize], c12[newSize][newSize], c21[newSize][newSize], c22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Splitting matrices
    for (int i = 0; i < newSize; i++){
        for (int j = 0; j < newSize; j++){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // C11 = A11*B11 + A12*B21
    multiply_dnc(a11, b11, temp1, newSize);
    multiply_dnc(a12, b21, temp2, newSize);
    add_matrix(temp1, temp2, c11, newSize);

    // C12 = A11*B12 + A12*B22
    multiply_dnc(a11, b12, temp1, newSize);
    multiply_dnc(a12, b22, temp2, newSize);
    add_matrix(temp1, temp2, c12, newSize);

    // C21 = A21*B11 + A22*B21
    multiply_dnc(a21, b11, temp1, newSize);
    multiply_dnc(a22, b21, temp2, newSize);
    add_matrix(temp1, temp2, c21, newSize);

    // C22 = A21*B12 + A22*B22
    multiply_dnc(a21, b12, temp1, newSize);
    multiply_dnc(a22, b22, temp2, newSize);
    add_matrix(temp1, temp2, c22, newSize);

    // Join results
    for (int i = 0; i < newSize; i++){
        for (int j = 0; j < newSize; j++){
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
}

int main(){
    int A[N][N], B[N][N], C[N][N] = {0};

    srand(time(NULL));

    printf("Matrix A:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = rand() % 10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {
            B[i][j] = rand() % 10;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    clock_t start = clock();
    for (int i = 0; i < ITER; i++)
        multiply_dnc(A, B, C, N);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResultant Matrix after multiplication:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}