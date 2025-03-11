#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, D, root1, root2, realPart, imagPart;
    cout << "Enter coefficients a, b, and c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "This is not a quadratic equation (a cannot be 0)." << endl;
        return 0;
    }

    D = (b * b) - (4 * a * c);

    if (D > 0) {  
        root1 = (-b + sqrt(D)) / (2 * a);
        root2 = (-b - sqrt(D)) / (2 * a);
        cout << "The roots are real and distinct: " << root1 << " and " << root2 << endl;
    }
    else if (D == 0) {  
        root1 = -b / (2 * a);
        cout << "The roots are real and equal: " << root1 << endl;
    }
    else {  
        realPart = -b / (2 * a);
        imagPart = sqrt(-D) / (2 * a);
        cout << "The roots are complex: " 
             << realPart << " + " << imagPart << "i and " 
             << realPart << " - " << imagPart << "i" << endl;
    }

    return 0;
}