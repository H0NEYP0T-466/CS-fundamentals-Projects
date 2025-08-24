#include <iostream>
#include <string>
using namespace std;

char convertToLower(char c) {
    // If the character is uppercase, convert it to lowercase
    if (c >= 'A' && c <= 'Z') {
        return c + 32; // ASCII difference between uppercase and lowercase letters
    }
    return c; // If the character is already lowercase or not an alphabet, return it as is
}

char convertToUpper(char c) {
    // If the character is lowercase, convert it to uppercase
    if (c >= 'a' && c <= 'z') {
        return c - 32; // ASCII difference between lowercase and uppercase letters
    }
    return c; // If the character is already uppercase or not an alphabet, return it as is
}

string convertCase(const string& str) {
    string convertedStr = "";
    for (char ch : str) {
        convertedStr += convertToLower(ch); // Convert each character to lowercase
    }
    return convertedStr;
}

int main() {
    string userInput;
    cout << "Enter a string: ";
    getline(cin, userInput);

    string convertedString = convertCase(userInput);

    cout << "Converted string: " << convertedString << endl;

    return 0;
}

