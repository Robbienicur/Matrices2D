#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int i, j;

    // Solicitar al usuario el tamaño de las matrices
    printf("Ingrese el numero de filas: ");
    scanf("%d", &rows);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &cols);

    // Reserva dinámica de memoria para las dos matrices A y B
    int *A = (int *)malloc(rows * cols * sizeof(int));
    int *B = (int *)malloc(rows * cols * sizeof(int));
    int *C = (int *)malloc(rows * cols * sizeof(int)); // matriz resultado

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // Llenar matriz A con datos del usuario
    printf("\nIngrese los elementos de la matriz A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", (A + i * cols + j)); // usando aritmética de punteros
        }
    }

    // Llenar matriz B con datos del usuario
    printf("\nIngrese los elementos de la matriz B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", (B + i * cols + j));
        }
    }

    // Calcular la suma C = A + B
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(C + i * cols + j) = *(A + i * cols + j) + *(B + i * cols + j);
        }
    }

    // Mostrar el resultado
    printf("\nMatriz resultado C = A + B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", *(C + i * cols + j));
        }
        printf("\n");
    }

    // Liberar memoria
    free(A);
    free(B);
    free(C);

    return 0;
}
