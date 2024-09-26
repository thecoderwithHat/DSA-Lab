#include <stdio.h>
#include <stdbool.h>

#define MAX 15  

void readMatrix(int matrix[MAX][MAX], int n) {
    printf("Enter the matrix row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int n) {
    printf("The Matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool isUpperTriangular(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return false;  
            }
        }
    }
    return true;
}

int main() {
    int n;
    int matrix[MAX][MAX];
    
   
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    readMatrix(matrix, n);

    displayMatrix(matrix, n);


    if (isUpperTriangular(matrix, n)) {
        printf("\nthe matrix is an Upper Triangular Matrix.\n");
    } else {
        printf("\nThe matrix is NOT an Upper Triangular Matrix.\n");
    }

    return 0;
}
