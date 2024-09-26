#include <stdio.h>

// Function to double the values of each element in the array
void doubleValues(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2; // Double the value of each element
    }
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the function to double the values
    doubleValues(arr, n);

    // Display the modified array
    printf("Modified array after doubling values:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
