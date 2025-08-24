#include<iostream>
using namespace std;
int main() {
    float num1, num2, result;
    int operation;
    char choice;
    cout << "\t\t\t\t\tWELCOME TO CALCULATOR APP" << endl;
    do {
        while (true) {
            cout << "Please Enter First Number:\n";
            cin >> num1;
            if (cin.fail()) {
                cout << "Error: Please Enter Integers Or Decimals\n";
                cin.clear();  
                cin.ignore(); 
            } else {
                break;
            }
        }
        while (true) {
            cout << "Please Enter The Corresponding Operation:\n";
            cout << "1 For Addition\n2 For Subtraction\n3 For Multiplication\n4 For Division\n";
            cin >> operation;

            if (cin.fail() || operation > 4||operation<=0) {
                cout << "Error: Please Enter a Valid Operation\n";
                cin.clear();
                cin.ignore();
            } else {
                break;
            }
        }
        do {
            cout << "Please Enter Second Number:\n";
            cin >> num2;
            if (cin.fail()) {
                cout << "Error: Please Enter Integers Or Decimals\n";
                cin.clear();
                cin.ignore();
            } else if (operation == 4 && num2 == 0) {
                cout << "Error: Division by zero is not allowed.\n";
            } else {
                break;
            }
        } while (true);
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
            default:
                cout << "Invalid operation selected." << endl;
        }
        cout << "Do you want to perform another calculation? (y/any other key): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}

