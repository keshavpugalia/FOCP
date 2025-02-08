#include <iostream>
using namespace std;
void printSpiral(int n);
int main() {
    int n;
    cout << "\nEnter the size of the matrix: ";
    cin >> n;
    printSpiral(n);
    return 0;
}

void printSpiral(int n){
    int arr[n][n];
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;

    // Generate the spiral matrix
    while (top <= bottom && left <= right) {
        // Fill top row
        for (int i = left; i <= right; i++)
            arr[top][i] = num++;
        top++;
        // Fill right column
        for (int i = top; i <= bottom; i++)
            arr[i][right] = num++;
        right--;
        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                arr[bottom][i] = num++;
            bottom--;
        }
        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                arr[i][left] = num++;
            left++;
        }
    }
    // This part will print the matrix in grid form
    cout << "\nSpiral Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout<< arr[i][j] << "\t";
        cout << endl;
    }
    // This part will print all elements in a straight line
    cout << "\nElements of matrix : ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
    }
    cout << endl;
}
