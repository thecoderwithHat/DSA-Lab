#include <stdio.h>

// Function to swap two numbers (call by value)
void swap(int a, int b) {
    int temp;

    // Swapping logic
    temp = a;
    a = b;
    b = temp;

    // Display values after swapping inside the function
    printf("Inside swap function - after swapping: a = %d, b = %d\n", a, b);
}

int main() {
    int num1, num2;

    // Input two integers from the user
   num1 =1;
   num2 = 4;

    // Display values before swapping
    printf("Before swapping in main: num1 = %d, num2 = %d\n", num1, num2);

    // Call swap function (this will swap values locally in the function only)
    swap(num1, num2);

    // Display values after swapping in main (values will remain the same)
    printf("After swapping in main: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
