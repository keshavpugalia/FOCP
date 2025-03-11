#include <iostream>
using namespace std;
void printFibonacci(int n);
int findNthFibonacci(int n);

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        printFibonacci(n);
        cout << "The " << n << "th Fibonacci number is: " << findNthFibonacci(n) << endl;
    }
    return 0;
}

int findNthFibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, next;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

void printFibonacci(int n) {
    int a = 0, b = 1, next;
    
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}