#include <stdio.h>

#define MAX_SIZE 100

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtFront(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}

void insertAtPosition(int arr[], int *size, int value, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

int main() {
    int arr[MAX_SIZE];
    int size, value, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter the elements-%d: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Array before insertion:\n");
    printArray(arr, size);

    printf("Enter the value to insert at the front: ");
    scanf("%d", &value);
    insertAtFront(arr, &size, value);
    printf("Array after inserting at the front:\n");
    printArray(arr, size);

    printf("Enter the value to insert at the end: ");
    scanf("%d", &value);
    insertAtEnd(arr, &size, value);
    printf("Array after inserting at the end:\n");
    printArray(arr, size);

    printf("Enter the value to insert and the position: ");
    scanf("%d %d", &value, &position);
    insertAtPosition(arr, &size, value, position);
    printf("Array after inserting at position %d:\n", position);
    printArray(arr, size);

    return 0;
}
