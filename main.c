#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int i, j;

    // Ask the user for the matrix dimensions
    printf("Ingrese el numero de filas: ");
    scanf("%d", &rows);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the two matrices A and B
    int *A = (int *)malloc(rows * cols * sizeof(int));
    int *B = (int *)malloc(rows * cols * sizeof(int));
    int *C = (int *)malloc(rows * cols * sizeof(int)); 

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Fill matrix A with user input
    printf("\nIngrese los elementos de la matriz A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", (A + i * cols + j)); 
        }
    }

    // Fill matrix B with user input
    printf("\nIngrese los elementos de la matriz B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", (B + i * cols + j));
        }
    }

    // Compute the sum C = A + B using pointer arithmetic
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(C + i * cols + j) = *(A + i * cols + j) + *(B + i * cols + j);
        }
    }

    // Display the resulting matrix
    printf("\nMatriz resultado C = A + B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(C + i * cols + j));
        }
        printf("\n");
    }

    // Free the allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}
