#include <iostream>
#include <cmath>
using namespace std;

// Integer division using repeated subtraction
int manualIntDivision(int dividend, int divisor) {
    if (divisor == 0) {
        cout << "Error: Division by zero!" << endl;
        return -1;  // Handle division by zero
    }
    
    int quotient = 0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1; // Determine sign
    
    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }

    return sign * quotient;
}

// Floating-point division using subtraction
float manualFloatDivision(float dividend, float divisor, int precision = 5) {
    if (divisor == 0) {
        cout << "Error: Division by zero!" << endl;
        return -1;  // Handle division by zero
    }

    float quotient = 0.0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1; // Determine sign
    
    dividend = abs(dividend);
    divisor = abs(divisor);

    // Compute integer part
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }

    // Compute decimal part
    float factor = 1.0;
    for (int i = 0; i < precision; i++) {
        factor /= 10;
        dividend *= 10;
        int count = 0;
        while (dividend >= divisor) {
            dividend -= divisor;
            count++;
        }
        quotient += count * factor;
    }

    return sign * quotient;
}

int main() {
    int a, b;
    float x, y;

    // Integer division
    cout << "Enter two integers for integer division: ";
    cin >> a >> b;
    cout << "Integer Division Result: " << manualIntDivision(a, b) << endl;

    // Floating-point division
    cout << "Enter two floating-point numbers for division: ";
    cin >> x >> y;
    cout << "Floating-Point Division Result: " << manualFloatDivision(x, y) << endl;

    return 0;
}
