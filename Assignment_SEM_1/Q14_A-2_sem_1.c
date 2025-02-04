#include <stdio.h>

void printDuplicates(int arr[], int n) {
    int foundDuplicate = 0;
    int count[n];

    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 1) {
            printf("%d ", arr[i]);
            count[arr[i]] = 0; 
            foundDuplicate = 1;
        }
    }

    if (!foundDuplicate) {
        printf("-1");
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printDuplicates(arr, n);

    return 0;
}