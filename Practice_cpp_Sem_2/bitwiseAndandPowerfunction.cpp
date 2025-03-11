#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a, b, c, d;
    cout << "Enter values for a, b, c, and d: ";
    cin >> a >> b >> c >> d;
    int result = (pow(a, b) + (c & d));
    cout << "Result of (a^b + c&d) is: " << result << endl;
    return 0;
}
/* The Precidance of the operator is
1 brackets
2 power fun.
3 addition
4 bitwise and

and bitwise precidance,
1 not 
2 shift right/ left (<<,>>)
3 and (&)
4 xor(^)
5 or (|)

*/
