#include <iostream>
using namespace std;
class HeartRates {
    string firstName;
    string lastName;
    int birthYear;
public:
    HeartRates(string first,string last,int year)
        : firstName(first),lastName(last),birthYear(year){}
    int calculateMaxHeartRate(){
        return 220-(2024-birthYear);
    }
    pair<int, int>calculateTargetHeartRate(){
        int maxHeartRate=calculateMaxHeartRate();
        return {maxHeartRate/2,maxHeartRate*85/100};
    }
    void getInput() {
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Enter birth year: ";
        cin >> birthYear;
    }
};
int main() {
    HeartRates person("", "", 0); 
    person.getInput();
    cout << "Maximum Heart Rate: " << person.calculateMaxHeartRate() <<" beats per minute" << endl;;
    auto targetHeartRate = person.calculateTargetHeartRate();
    cout << "Target Heart Rate Range:"<<targetHeartRate.first<<"-"<<targetHeartRate.second<<" beats per minute";
}

