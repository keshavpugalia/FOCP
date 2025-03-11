#include <iostream>
int main()
{
    using namespace std;
    int num1, num2, choice;
    bool cal = true;
    while (cal)
    {
        cout << "\n Welcome to calculator" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit the Program" << endl;
        cout << "Enter a Choice" << endl;
        cin >> choice;
        cout << "Enter Number 1: " << endl;
        cin >> num1;
        cout << "Enter Number 2: " << endl;
        cin >> num2;

        switch (cal)
        {
        case 1:
            if (choice == 1)
            {
                cout << "Addition of two numbers is : " << (num1 + num2);
                break;
            }
        case 2:
            if (choice == 2)
            {
                cout << "Subtraction of two numbers is : " << (num1 - num2);
                break;
            }
        case 3:
            if (choice == 3)
            {
                cout << "Multiplication of two numbers is : " << (num1 * num2);
                break;
            }
        case 4:
            if (choice == 4)
            {
                cout << "Division of two numbers is : " << (num1 / num2);
                break;
            }
        case 5:
            if (choice == 5)
            {
                bool cal = false;
                cout << "Thank you For Using!!";
                break;
            }
        }
    }
    return 0;
}