// WAP for Binary to Decimal conversion & Decimal to Binary for a given number  as per user’s choice.
#include <stdio.h>
#include <math.h>

// Function to convert binary to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1, remainder;

    while (binary > 0) {
        remainder = binary % 10;  // Get the last digit
        decimal = decimal + remainder * base;  // Add the weighted remainder to decimal
        binary = binary / 10;  // Remove the last digit
        base = base * 2;  // Update the base (powers of 2)
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binary[32];  // Array to store binary digits
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;  // Get the remainder (binary digit)
        decimal = decimal / 2; 
        index++;  // Move to the next index
    }

    // Print the binary number in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int choice, number;

    printf("Choose an option:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Binary to Decimal conversion
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Decimal: %d\n", binaryToDecimal(number));
            break;
        case 2:
            // Decimal to Binary conversion
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            decimalToBinary(number);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}