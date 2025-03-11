#include <iostream>
using namespace std;

bool isPrime(int num);

int main() {
    int n;
    cout << "Enter the number of prime numbers to display: ";
    cin >> n;
    int count = 0;
    int num = 2; 
    while (count < n) { 
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;
    return 0;
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}
