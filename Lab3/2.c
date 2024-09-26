/*Write a program to find the transpose of a matrix. Write separate functions for reading, displaying and to find the transpose 
of the matrix.*/
#include <stdio.h>

// Function to read the matrix from user
void readMatrix(int matrix[10][10], int row, int col) {
    printf("Enter the elements of the matrix (%d elements):\n", row * col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display the matrix
void displayMatrix(int matrix[10][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to compute the transpose of the matrix
void transposeMatrix(int matrix[10][10], int transpose[10][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int row, col;
    int matrix[10][10], transpose[10][10];

    // Input matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    // Reading the matrix
    readMatrix(matrix, row, col);

    // Displaying the original matrix
    printf("Original matrix:\n");
    displayMatrix(matrix, row, col);

    // Computing the transpose
    transposeMatrix(matrix, transpose, row, col);

    // Displaying the transposed matrix
    printf("Transpose of the matrix:\n");
    displayMatrix(transpose, col, row); // Note: Rows and columns are swapped in the transpose

    return 0;
}
