#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int PrincipalAmount,TimePeriod,numOfTimesCompoundedPerYear;
    float RateOfIntrest;
    cout<<"Enter the Principal Amount : ";
    cin>>PrincipalAmount;
    cout<<"Enter the Time Preiod (in years): ";
    cin>>TimePeriod;
    cout<<"Enter the rate of intrest (decimal): ";
    cin>>RateOfIntrest;

    int compInterest,Amount;
    Amount= (PrincipalAmount*pow(1+RateOfIntrest/100,TimePeriod));
    compInterest = Amount - PrincipalAmount;
    cout<<"The Final amount : "<<Amount<<endl;
    cout<<"Compound Interest : "<<compInterest;
}