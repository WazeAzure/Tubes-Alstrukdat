#include <stdio.h>
#include "matrix.c" 

int main() {
    Matrix m1, m2, m3;

    int rows, cols;
    printf("Masukkan ukuran matrixs:\n");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements for matrix 1:\n");
    readMatrix(&m1, rows, cols); 

    printf("Matrix 1:\n");
    displayMatrix(m1); 

    printf("Enter elements for matrix 2:\n");
    readMatrix(&m2, rows, cols); 

    printf("Matrix 2:\n");
    displayMatrix(m2);

    // menambahkan m1 dan m2
    m3 = addMatrix(m1, m2);
    printf("Result of matrix addition:\n");
    displayMatrix(m3); // Display the result

    
    return 0;
}