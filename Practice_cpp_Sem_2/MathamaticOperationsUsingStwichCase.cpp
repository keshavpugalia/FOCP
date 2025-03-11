#include<iostream>
using namespace std;
int main(){
    int num1,num2;
    int operation;

    cout<<"Enter first number : ";
    cin>>num1;
    cout<<"Enter second number : ";
    cin>>num2;
    cout<<"Enter 1 for Sum(+)\n";
    cout<<"Enter 2 for Subtraction(-)\n";
    cout<<"Enter 3 for Multiplaction(*)\n";
    cout<<"Enter 4 for Division(/)";
    cout<<"Enter Your Choice: ";
    cin>>operation;

    switch (operation){
        case 1 :
        cout<<"The Sum is "<<num1+num2<<endl;
        break;
        case 2 :
        cout<<"The Subtraction is "<<num1-num2<<endl;
        break;
        case 3 :
        cout<<"The Multiplication is "<<num1*num2<<endl;
        break;
        case 4 :
        cout<<"The Division is "<<num1/num2<<endl;
        break;
        default : 
        cout<<"Invalid Choice"<<endl;
        break;
    }
    return 0;
    }
