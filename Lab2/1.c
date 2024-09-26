#include <stdio.h>
#include <stdlib.h>

void insertAtBeginningAndEnd(int *arr, int size, int newValueStart, int newValueEnd, int newValueMid) {

    int *newArr = (int *)malloc((size + 3) * sizeof(int));  
    if (newArr == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }


    newArr[0] = newValueStart;
 // Copy 
    for (int i = 0; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    newArr[size / 2 + 1] = newValueMid;
    newArr[size + 2] = newValueEnd;

    // Print the new array
    printf("New array: ");
    for (int i = 0; i < size + 3; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(newArr);
}

int main() {
    int arr[] = {2, 4, 6, 8};  
    int size = sizeof(arr) / sizeof(arr[0]);

    int newValueStart = 1; 
    int newValueEnd = 10;  
    int newValueMid = 9;

    insertAtBeginningAndEnd(arr, size, newValueStart, newValueEnd, newValueMid);

    return 0;
}
