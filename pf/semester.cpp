#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
int main() {
    float num1, num2, result;
    int operation;
    char choice;
    cout << "\t\t\t\t\tWELCOME TO CALCULATOR APP" << endl;
    do {
        cout << "Please Enter First Number:\n";
        cin >> num1;
        while (cin.fail()) {
            cout << "Error: Please Enter Integers Or Decimals\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please Enter First Number:\n";
            cin >> num1;
        }
        cout << "Please Enter The Corresponding Operation:\n";
        cout << "1 For Addition\n2 For Subtraction\n3 For Multiplication\n4 For Division\n";
        cout << "5 For Sin\n6 For Cos\n7 For Tan\n";
        cout << "8 For Inverse sin\n9 For Inverse cos\n10 For Inverse tan\n";  
        cin >> operation;
        while (cin.fail() || operation > 10 || operation <= 0) {
            cout << "Error: Please Enter a Valid Operation\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please Enter The Corresponding Operation:\n";
            cin >> operation;
        }
        if (operation >= 1 && operation <= 4) {
            cout << "Please Enter Second Number:\n";
            cin >> num2;
            while (cin.fail()) {
                cout << "Error: Please Enter Integers Or Decimals\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please Enter Second Number:\n";
                cin >> num2;
            }
            while (operation == 4 && num2 == 0) {
                cout << "Error: Division by zero is not allowed\n";
                cout << "Please enter second number\n";
                cin >> num2;
            }
        }
        switch (operation) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4:
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                break;
            case 5:
                result = sin(num1);
                cout << "Result: sin(" << num1 << ") = " << result << endl;
                break;
            case 6:
                result = cos(num1);
                cout << "Result: cos(" << num1 << ") = " << result << endl;
                break;
            case 7:
                result = tan(num1);
                cout << "Result: tan(" << num1 << ") = " << result << endl;
                break;
            case 8:
                result = asin(num1); 
                cout << "Result: Inverse sin(" << num1 << ") = " << result << " radians" << endl;
                break;
            case 9:
                result = acos(num1);  
                cout << "Result:  Inverse cos(" << num1 << ") = " << result << " radians" << endl;
                break;
            case 10:
                result = atan(num1);  
                cout << "Result: Inverse tan(" << num1 << ") = " << result << " radians" << endl;
                break;
            default:
                cout << "Invalid operation selected." << endl;
        }
        cout << "Do you want to perform another calculation? (y/any other key): ";
        cin >> choice;
    } while (choice == 'y');
    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}

