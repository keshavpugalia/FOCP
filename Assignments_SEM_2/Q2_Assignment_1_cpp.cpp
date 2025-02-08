/*      
        Q2) Take input integers and store theme in an array,
            Find the second largest and second smallest element
            Also Reverse the array
*/

// Code Starts,

#include<iostream>
using namespace std;
int main(){
    // This Part Will Ask for No of elements and will store in an array.
    int num;
    cout<<"Enter the Number of Integres: ";
    cin>>num;
        int arr[num];
        cout<<"Enter "<<num<<" integers \n";
        int i;
            for(i=0; i<num;i++){
            cin>>arr[i];
            }
        if(num<2){
            cout<<"There should be at least 2 integers"<<endl;
            return 0;
        }
    // This part will reverse the entered array,
        for(int i = num; i < 0 ; i--){
            cout<<"Reverse of the Element Entered: "<<endl;
            cout<<i<<" "<<endl;
        }
        
    // This part will Assign the intitial values to the variables.

    int largest,Second_Largest;
    int Smallest,Second_Smallest;
    
    if (arr[0]>arr[1]) {
        largest = arr[0];
        Second_Largest = arr[1];
        Smallest = arr[1];
        Second_Smallest = arr[0];
    }
    else {
        Second_Largest= arr[0];
        largest = arr[1];
        Smallest = arr[0];
        Second_Smallest = arr[1]; 
        }

    // This loop will itrate till the total number of integer entered by the user.

        for (i=2;i<num;i++){
            if(arr[i] > largest){
                Second_Largest = largest;
                largest= arr[i];
            
            } else if (arr[i] > Second_Largest && arr[i] != largest){
                 Second_Largest = arr[i]; }

                if (arr[i] < Smallest){
                Second_Smallest = Smallest;
                Smallest = arr[i]; 

                } else if (arr[i] < Second_Smallest && arr[i] != Smallest){
                        Second_Smallest = arr[i];
                        }
        }

    // This part will reverse the entered array and print it
        
        cout << "Reverse of the Element Entered: " << endl;
        for (int i = num - 1; i >= 0; i--) {
        cout << arr[i] << " ";
        }
        cout << endl;

    //This part will print all the special cases messages.

    if (largest == Second_Largest){
         cout << "No second largest element found." << endl;
    } else {
        cout << "The second largest element is " << Second_Largest << endl;
    } if (Smallest == Second_Smallest){
        cout << "No second smallest element found." << endl;
    } else {
        cout << "The second smallest element is " << Second_Smallest << endl;
    }
    return 0;   
}