#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 128    // Matrix size (must be power of 2)
#define ITER 10000 // Number of iterations for timing

/* ITERATIVE METHOD */
void multiply_iterative(int A[N][N], int B[N][N], int C[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/* ADD & SUBTRACT HELPERS */
void add_matrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub_matrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* DIVIDE AND CONQUER */
void multiply_dnc(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int a11[newSize][newSize], a12[newSize][newSize], a21[newSize][newSize], a22[newSize][newSize];
    int b11[newSize][newSize], b12[newSize][newSize], b21[newSize][newSize], b22[newSize][newSize];
    int c11[newSize][newSize], c12[newSize][newSize], c21[newSize][newSize], c22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Split matrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
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

    // Compute submatrices
    multiply_dnc(newSize, a11, b11, temp1);
    multiply_dnc(newSize, a12, b21, temp2);
    add_matrix(newSize, temp1, temp2, c11);

    multiply_dnc(newSize, a11, b12, temp1);
    multiply_dnc(newSize, a12, b22, temp2);
    add_matrix(newSize, temp1, temp2, c12);

    multiply_dnc(newSize, a21, b11, temp1);
    multiply_dnc(newSize, a22, b21, temp2);
    add_matrix(newSize, temp1, temp2, c21);

    multiply_dnc(newSize, a21, b12, temp1);
    multiply_dnc(newSize, a22, b22, temp2);
    add_matrix(newSize, temp1, temp2, c22);

    // Join results
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
}

/* STRASSEN METHOD */
void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int a11[newSize][newSize], a12[newSize][newSize], a21[newSize][newSize], a22[newSize][newSize];
    int b11[newSize][newSize], b12[newSize][newSize], b21[newSize][newSize], b22[newSize][newSize];
    int c11[newSize][newSize], c12[newSize][newSize], c21[newSize][newSize], c22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize], M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Split input matrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
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

    // Compute M1–M7
    add_matrix(newSize, a11, a22, temp1);
    add_matrix(newSize, b11, b22, temp2);
    strassen(newSize, temp1, temp2, M1);

    add_matrix(newSize, a21, a22, temp1);
    strassen(newSize, temp1, b11, M2);

    sub_matrix(newSize, b12, b22, temp1);
    strassen(newSize, a11, temp1, M3);

    sub_matrix(newSize, b21, b11, temp1);
    strassen(newSize, a22, temp1, M4);

    add_matrix(newSize, a11, a12, temp1);
    strassen(newSize, temp1, b22, M5);

    sub_matrix(newSize, a21, a11, temp1);
    add_matrix(newSize, b11, b12, temp2);
    strassen(newSize, temp1, temp2, M6);

    sub_matrix(newSize, a12, a22, temp1);
    add_matrix(newSize, b21, b22, temp2);
    strassen(newSize, temp1, temp2, M7);

    // Compute C11–C22
    add_matrix(newSize, M1, M4, temp1);
    sub_matrix(newSize, temp1, M5, temp2);
    add_matrix(newSize, temp2, M7, c11);

    add_matrix(newSize, M3, M5, c12);
    add_matrix(newSize, M2, M4, c21);

    sub_matrix(newSize, M1, M2, temp1);
    add_matrix(newSize, temp1, M3, temp2);
    add_matrix(newSize, temp2, M6, c22);

    // Join into result matrix
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = c11[i][j];
            C[i][j + newSize] = c12[i][j];
            C[i + newSize][j] = c21[i][j];
            C[i + newSize][j + newSize] = c22[i][j];
        }
    }
}

int main()
{
    int A[N][N], B[N][N], C[N][N];
    srand(time(NULL));

    // Generate random matrices
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = rand() % 10;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Iterative multiplication
    clock_t start = clock();
    for (int i = 0; i < ITER; i++)
        multiply_iterative(A, B, C);
    clock_t end = clock();
    double time_iter = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResult (Iterative):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("Time (Iterative): %f seconds\n", time_iter);

    // DnC multiplication
    start = clock();
    for (int i = 0; i < ITER; i++)
        multiply_dnc(N, A, B, C);
    end = clock();
    double time_dnc = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResult (Divide & Conquer):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("Time (DnC): %f seconds\n", time_dnc);

    // Strassen multiplication
    start = clock();
    for (int i = 0; i < ITER; i++)
        strassen(N, A, B, C);
    end = clock();
    double time_strassen = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nResult (Strassen):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    printf("Time (Strassen): %f seconds\n", time_strassen);

    return 0;
}