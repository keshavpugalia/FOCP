#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteFront(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteEnd(int arr[], int *size) {
    if (*size <= 0) {
        printf("Array is empty.\n");
        return;
    }
    (*size)--;
}

void deleteAtPosition(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

int main() {
    int arr[100], size, choice, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter digit-%d: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Array before deletion: ");
    printArray(arr, size);

    printf("Choose deletion method:\n");
    printf("1. Delete from front\n");
    printf("2. Delete from end\n");
    printf("3. Delete from a specific position\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteFront(arr, &size);
            break;
        case 2:
            deleteEnd(arr, &size);
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(arr, &size, position);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Array after deletion: ");
    printArray(arr, size);

    return 0;
}
