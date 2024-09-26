/*Write a program to find check whether the matrix is lower triangular or not. Write separate functions for reading
 the matrix and to check whether the matrix is lower triangular or not*/
 #include <stdio.h>
#include <stdbool.h>

// Function to read the matrix from the user
void readMatrix(int matrix[10][10], int n) {
    printf("Enter the elements of the matrix (%d elements):\n", n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to check if the matrix is lower triangular
bool isLowerTriangular(int matrix[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] != 0) {
                return false;  // If any element above the diagonal is non-zero
            }
        }
    }
    return true;  // All elements above the diagonal are zero
}

// Function to display the matrix
void displayMatrix(int matrix[10][10], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, matrix[10][10];

    // Input matrix dimension (square matrix)
    printf("Enter the dimension of the matrix (n x n): ");
    scanf("%d", &n);

    // Reading the matrix
    readMatrix(matrix, n);

    // Displaying the matrix
    printf("Matrix:\n");
    displayMatrix(matrix, n);

    // Checking if the matrix is lower triangular
    if (isLowerTriangular(matrix, n)) {
        printf("The matrix is lower triangular.\n");
    } else {
        printf("The matrix is not lower triangular.\n");
    }

    return 0;
}
