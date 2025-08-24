#include <iostream>
#include<limits>
using namespace std;
int main() {
    int numStudents;
    cout << "Enter the number of students: \n";
    cin >> numStudents;

  
    while (cin.fail() || numStudents <= 0) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number of students: \n";
        cin >> numStudents;
    }

    int* rollNumbers = new int[numStudents];
    string* studentNames = new string[numStudents];
    bool* isPresent = new bool[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        rollNumbers[i] = i + 1;

        cout << "Enter the name of student \n" << rollNumbers[i] << ": ";
        cin >> studentNames[i];
        while (true) {
            cout << "Is " << studentNames[i] << " present? (1 for yes, 0 for no): \n";
            cin >> isPresent[i];

            if (cin.fail() || (isPresent[i] != 0 && isPresent[i] != 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter 1 for yes or 0 for no: \n";
            } else {
                break;
            }
        }
    }

    // Display attendance
    cout << "\nAttendance Summary:\n";
    cout << "----------------------------------------\n";
    cout << "Roll No.\tName\t\tAttendance\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < numStudents; ++i) {
        cout << rollNumbers[i] << "\t\t" << studentNames[i] << "\t\t";
        if (isPresent[i]) {
            cout << "Present\n";
        } else {
            cout << "Absent\n";
        }
    }


    return 0;
}

