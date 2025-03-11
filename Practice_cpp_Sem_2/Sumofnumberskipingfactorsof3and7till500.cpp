#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 1; i <= 500; i++) {
        if (i % 3 == 0 && i % 7 == 0) {
            continue;
        }
        if (sum + i > 1000) {
            break;
        }
        cout << i << " ";
        sum += i;
    }
    cout << "\nSum of printed numbers: " << sum << endl;
    return 0;
}