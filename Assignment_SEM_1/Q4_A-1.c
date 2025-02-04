// WAP to accept two integer numbers and swap them using 4 different methods in C language. 
// Method 1: Using a temporary variable

#include <stdio.h>
int main() {
    int num1, num2, temp;

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    printf("\nBefore swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("\nAfter swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
// Method 2 : Swapping using arithmetic operations (addition and subtraction)
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    printf("\nBefore swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    num1 = num1 + num2;  // a becomes the sum of a and b
    num2 = num1 - num2;  // b becomes the original value of a
    num1 = num1 - num2;  // a becomes the original value of b

    printf("\nAfter swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

// Method 3 : Swapping using XOR

#include <stdio.h>
int main() {
    int num1, num2;

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    printf("\nBefore swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    num1 = num1 ^ num2;  // Step 1: XOR num1 and num2, and store the result in num1
    num2 = num1 ^ num2;  // Step 2: XOR the new num1 with num2 to get the original num1, and store it in num2
    num1 = num1 ^ num2;  // Step 3: XOR the new num1 with the new num2 to get the original num2, and store it in num1

    printf("\nAfter swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}