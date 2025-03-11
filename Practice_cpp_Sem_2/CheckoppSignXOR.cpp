#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    bool oppositeSigns = (x ^ y) < 0;
    cout << "Do " << x << " and " << y << " have opposite signs? " 
         << (oppositeSigns ? "Yes" : "No") << endl;

    return 0;
}

// Ternary Operator
// A = (condition) ? expression_if_true : expression_if_false;
