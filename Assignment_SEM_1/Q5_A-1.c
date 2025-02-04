#include <stdio.h>

//Programme to check whether number is perfect or not.

int main() {
    int num,i,sum=0,sum1;
    printf("Enter a number :");
    scanf("%d",&num);

    for (i=1;i<=num;i=i+1) {
        while(num%i==0) {
        printf("%d, ",i);
        sum=sum+i;
        i=i+1;
    }
    }
    sum1=sum-num;
    
    if (sum1==num)
    printf("\n%d is a perfect number",num);
    else 
    printf("\n%d is not a perfect number",num);

    return 0;


}