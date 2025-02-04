// WAP to subtract two integers without using Minus (-) operator. 

#include <stdio.h>
int subtract(int a, int b) {
    while (b != 0) {
        // Find the carry and shift it left
        int carry = (~a) & b;
        // Perform subtraction using XOR
        a = a ^ b;
        // Update b to the carry
        b = carry << 1;
    }
    return a;
}

int main() {
    int num1, num2, result;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    result = subtract(num1, num2);
    printf("Subtraction of %d and %d is %d\n", num1, num2, result);

    return 0;
}
