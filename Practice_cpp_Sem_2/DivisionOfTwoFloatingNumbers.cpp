#include <iostream>
#include<iomanip>
using namespace std;
int main(){
    float num1,num2;
    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    cout<<"The sum of two floating number is: "<<fixed<<setprecision(2)<<(num1+num2);
}