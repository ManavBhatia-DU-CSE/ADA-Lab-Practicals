#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16 // Matrix size (must be power of 2)
#define ITER 10000

// Function to add matrices
void add(int n, int A[n][n], int B[n][n], int C[n][n]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract matrices
void subtract(int n, int A[n][n], int B[n][n], int C[n][n]){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]){
    if (n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int a11[newSize][newSize], a12[newSize][newSize], a21[newSize][newSize], a22[newSize][newSize];
    int b11[newSize][newSize], b12[newSize][newSize], b21[newSize][newSize], b22[newSize][newSize];
    int c11[newSize][newSize], c12[newSize][newSize], c21[newSize][newSize], c22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize], M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Splitting input matrices
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

    // M1 = (A11+A22)(B11+B22)
    add(newSize, a11, a22, temp1);
    add(newSize, b11, b22, temp2);
    strassen(newSize, temp1, temp2, M1);

    // M2 = (A21+A22)B11
    add(newSize, a21, a22, temp1);
    strassen(newSize, temp1, b11, M2);

    // M3 = A11(B12-B22)
    subtract(newSize, b12, b22, temp1);
    strassen(newSize, a11, temp1, M3);

    // M4 = A22(B21-B11)
    subtract(newSize, b21, b11, temp1);
    strassen(newSize, a22, temp1, M4);

    // M5 = (A11+A12)B22
    add(newSize, a11, a12, temp1);
    strassen(newSize, temp1, b22, M5);

    // M6 = (A21-A11)(B11+B12)
    subtract(newSize, a21, a11, temp1);
    add(newSize, b11, b12, temp2);
    strassen(newSize, temp1, temp2, M6);

    // M7 = (A12-A22)(B21+B22)
    subtract(newSize, a12, a22, temp1);
    add(newSize, b21, b22, temp2);
    strassen(newSize, temp1, temp2, M7);

    // C11 = M1 + M4 - M5 + M7
    add(newSize, M1, M4, temp1);
    subtract(newSize, temp1, M5, temp2);
    add(newSize, temp2, M7, c11);

    // C12 = M3 + M5
    add(newSize, M3, M5, c12);

    // C21 = M2 + M4
    add(newSize, M2, M4, c21);

    // C22 = M1 - M2 + M3 + M6
    subtract(newSize, M1, M2, temp1);
    add(newSize, temp1, M3, temp2);
    add(newSize, temp2, M6, c22);

    // Join into result matrix
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
    int A[N][N], B[N][N], C[N][N] = {{0}};

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
        for (int j = 0; j < N; j++){
            B[i][j] = rand() % 10;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    clock_t start = clock();
    for (int i = 0; i < ITER; i++)
        strassen(N, A, B, C);
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