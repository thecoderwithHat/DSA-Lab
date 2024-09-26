#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found, return index
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }b 
    }

    return -1; // Element not found
}

int main() {
    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements in sorted order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &target);

    int index = binarySearch(arr, size, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
