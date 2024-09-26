#include <stdio.h>

int linearSearch(int arr[], int size, int target_val){
     for (int i = 0; i < size; i++) {
        if (arr[i] == target_val) {
            return i; 
        }
    }
    return -1; // Element not found
}

int main() {
    int size, target_val;

    // Read the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    // Read the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search for: ");
    scanf("%d", &target_val);

    
    int index = linearSearch(arr, size, target_val);

     if (index != -1) {
        printf("Element %d found at index %d.\n", target_val, index);
    } else {
        printf("Element %d not found in the array.\n", target_val);
    }

    return 0;
}



