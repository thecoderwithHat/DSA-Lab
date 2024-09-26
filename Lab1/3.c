#include <stdio.h>

// Function to swap two numbers (call by reference)
void swap(int *a, int *b) {
    int temp;

    // Swapping logic
    temp = *a;
    *a = *b;
    *b = temp;

    // Display values after swapping inside the function
    printf("Inside swap function - after swapping: a = %d, b = %d\n", *a, *b);
}

int main() {
    int num1, num2;

   num1 = 1;
   num2 = 5;

    // Display values before swapping
    printf("Before swapping in main: num1 = %d, num2 = %d\n", num1, num2);

    // Call swap function (this will swap values in the actual variables)
    swap(&num1, &num2); // Passing the addresses of num1 and num2

    // Display values after swapping in main
    printf("After swapping in main: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
