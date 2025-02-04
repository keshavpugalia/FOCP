#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int marks[n];
    for(i = 0; i < n; i++) {
        printf("Enter marks-%d :",i+1);
        scanf("%d", &marks[i]);
    }

    int max = marks[0];
    int min = marks[0];

    for(i = 1; i < n; i++) {
        if(marks[i] > max) {
            max = marks[i];
        }
        if(marks[i] < min) {
            min = marks[i];
        }
    }

    printf("Maximum score: %d\n", max);
    printf("Minimum score: %d\n", min);

    return 0;
}
