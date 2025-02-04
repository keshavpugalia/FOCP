#include <stdio.h>
int main() {
    int i,score[5];

    for(i=0;i<=4;i=i+1) {
        printf("Enter score-%d :",i+1);
        scanf("%d",&score[i]);
    }

    printf("\n");

    for (i=0;i<=4;i=i+1) {
        if (score[i]%2==0)
        printf("Score-%d (%d) is even\n",i+1,score[i]);
        else
        printf("Score-%d (%d) is odd\n",i+1,score[i]);
    }
    return 0;

}