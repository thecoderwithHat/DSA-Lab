#include <stdio.h>

int main() {
    int num = 25;    // Declare an integer variable and assign it a value
    int *ptr;        // Declare a pointer variable that can hold the address of an integer

    // Use the address-of operator (&) to get the address of 'num'
    ptr = &num;

    // Print the value of 'num', its address, and the value at the pointer
    printf("Value of num: %d\n", num);                 // Prints the value of 'num'
    printf("Address of num: %p\n", (void*)&num);       // Prints the address of 'num'
    printf("Value of ptr (address stored in ptr): %p\n", (void*)ptr); // Prints the value of 'ptr' (address of 'num')
    printf("Value at address stored in ptr: %d\n", *ptr);  // Prints the value at the address stored in 'ptr' (value of 'num')

    // Modify the value of 'num' through the pointer
    *ptr = 50;
    printf("Modified value of num using pointer: %d\n", num);  // Prints the modified value of 'num'

    return 0;
}
