#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>     
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the number between 1 and 100." << endl;
    do {
	while(true){
	cout << "Enter your guess: ";
        cin >> guess;
        if(cin.fail()){
        	cout<<"please enter an integer\n";
        	cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else{
			break;
		}
	}
        attempts++;
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}

