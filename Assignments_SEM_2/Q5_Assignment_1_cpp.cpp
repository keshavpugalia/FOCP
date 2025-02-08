// Q5) first take input a matrix (elements), then rotate its element 90 degrees clockwise and print it.

#include <iostream>
using namespace std;

void rotateMatrix(int n, int matrix[][100]);
void printMatrix(int n, int matrix[][100]);

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    int matrix[100][100];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Original Matrix:\n";
    printMatrix(n, matrix);

    rotateMatrix(n, matrix);
    cout << "Rotated Matrix (90 degrees clockwise):\n";
    printMatrix(n, matrix);

    return 0;
}


// This part is to rotate the matrix by 90 degrees clockwise
void rotateMatrix(int n, int matrix[][100]) {
    // First, transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Then, This loop will reverse each row
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }
}
// This function is to print the matrix
void printMatrix(int n, int matrix[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}