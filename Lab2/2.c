#include <stdio.h>

void deleteAtStart(int *arr, int *size) {
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements left
    }
    (*size)--;  // Decrease size
}

void deleteAtEnd(int *size) {
    (*size)--;  // Decrease size, effectively removing the last element
}

void deleteInBetween(int *arr, int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];  // Shift elements left
    }
    (*size)--;  // Decrease size
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  // Initial array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    // Deleting at the start
    deleteAtStart(arr, &size);
    printf("After deleting at the start: ");
    printArray(arr, size);

    // Deleting at the end
    deleteAtEnd(&size);
    printf("After deleting at the end: ");
    printArray(arr, size);

    // Deleting in between (e.g., at position 2)
    deleteInBetween(arr, &size, 2);
    printf("After deleting in between (position 2): ");
    printArray(arr, size);

    return 0;
}
