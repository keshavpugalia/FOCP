#include <stdio.h>

void rotateByOne(int arr[], int n) {
    int temp = arr[n-1]; // Store the last element in a temporary variable
    for (int i = n-1; i > 0; i--) {
        arr[i] = arr[i-1]; // Shift elements to the right
    }
    arr[0] = temp; // Place the last element at the first position
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    rotateByOne(arr, n);

    printf("\nRotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
