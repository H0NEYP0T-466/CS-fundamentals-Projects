#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string passwordFile = "pasfile";

string readStoredPassword() {
    ifstream file(passwordFile.c_str());  
    string storedPassword;

    if (file.is_open()) {
        file >> storedPassword;
    } else {
        cerr << "Unable to open file for reading. Using default password." << endl;
        storedPassword = "pas123";
    }

    return storedPassword;
}

void writePasswordToFile(const string& np) {
    ofstream file(passwordFile.c_str());  // Convert to const char*
    if (file.is_open()) {
        file << np;
        cout << "Password changed successfully." << endl;
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

int main() {
    string defpas = readStoredPassword();
    string cp, cop, np;

    do {
        cout << "Please enter your password: ";
        cin >> cp;

        if (cp == defpas) {
            cout << "Password correct" << endl;
        } else {
            cout << "Wrong password" << endl;
        }
    } while (cp != defpas);

    cout << "Please enter a new password: ";
    cin >> np;

    cout << "Please confirm the new password: ";
    cin >> cop;

    if (cop == np) {
        writePasswordToFile(np);
    } else {
        cout << "Error: Passwords do not match. Please try again." << endl;
    }

    return 0;
}

