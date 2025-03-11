#include<iostream>
using namespace std;
int main(){
    int age;
    string name;
    cout<<"Enter your Name : ";
    cin>>name;
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Hello, "<<name<<" Congrats you completed "<<(age*365)<<" Days Of Your Life Sucessfully!"<<endl;
    return 0;
}