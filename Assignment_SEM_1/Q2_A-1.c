#include <stdio.h>

//Programme to print HCF of two integers

int main() {
    int num1,num2,i,HCF;
    printf("Enter first number :");
    scanf("%d",&num1);
    printf("Enter second number :");
    scanf("%d",&num2);

    for (i=1;i<=num1 && i<=num2;i=i+1) {
        if (num1%i==0 && num2%i==0)
        HCF=i;
    
    }
    printf("HCF of %d , %d is %d",num1,num2,HCF);
    return 0;

}