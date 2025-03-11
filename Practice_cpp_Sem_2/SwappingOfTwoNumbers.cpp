/*  Using bitwise XOR operator,

#include <iostream>
using namespace std;
void swapNumbers(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    return 0;
}

Using addition and subtraction,

#include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    
    return 0;
}

    using 3rd variable

    #include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    
    return 0;
}

*/