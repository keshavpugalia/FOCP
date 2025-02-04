/* WAP to print below mentioned pattern: 
1  
01  
101  
0101  
10101 */

#include <stdio.h>
int main() {
    int i=1;
    for (i=0;i<=1;i=i+1) {
        switch (i) {
            case 1:
            printf("1\n");
            case 2:
            printf("01\n");
            case 3:
            printf("101\n");
            case 4:
            printf("0101\n");
            case 5:
            printf("10101");
            break;
        }
    }
    return 0;
}