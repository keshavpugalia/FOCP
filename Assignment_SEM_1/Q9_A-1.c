//WAP to print Pyramid: 
#include <stdio.h>
int main() {
    int rows = 5; 
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            if (j % 2 == 1) {
                printf("0");
            } else {
                printf("1");
            }
        }
        for (int j = 1; j <= (2 * (rows - i) - 1); j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            if (j % 2 == 1) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }
    return 0;
}

