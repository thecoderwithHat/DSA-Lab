//Write a program to find the multiplication of two matrices. 
// Write separate functions for reading the matrix, displaying the matrix and to find the multiplication of the matrices.


#include <stdio.h>

void readMatrix(int matrix[][10], int row, int col) {
    printf("Enter elements of the matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][10], int row, int col) {
    printf("Matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int matrix1[][10], int matrix2[][10], int result[][10], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("multiplication is not possible!\n");
        return;
    }
  
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Multiply the matrices
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int row1, col1, row2, col2;
    
    // Input for the first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &row1, &col1);
    readMatrix(matrix1, row1, col1);
    
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &row2, &col2);
    readMatrix(matrix2, row2, col2);
    
    printf("\nFirst Matrix:\n");
    displayMatrix(matrix1, row1, col1);
    
    printf("\nSecond Matrix:\n");
    displayMatrix(matrix2, row2, col2);
    
    // Multiply the matrices
    multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2);
    
    
    if (col1 == row2) {
        printf("\nresultant Matrix after multiplication:\n");
        displayMatrix(result, row1, col2);
    }
    
    return 0;
}
