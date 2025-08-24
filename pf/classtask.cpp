#include <iostream>
#include <string>
using namespace std;
class Package {
protected:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZIP;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZIP;
    double weight;  
    double costPerOunce;  
public:
    Package(string senderName, string senderAddress,  string senderCity,
             string senderState, string senderZIP, string recipientName,
             string recipientAddress, string recipientCity, string recipientState,
             string recipientZIP, double weight, double costPerOunce)
            : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity),
              senderState(senderState), senderZIP(senderZIP), recipientName(recipientName),
              recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState),
              recipientZIP(recipientZIP), weight(weight), costPerOunce(costPerOunce) {
        if (weight < 0) {
            this->weight = 0;
        }
        if (costPerOunce < 0) {
            this->costPerOunce = 0;
        }
    }
     double calculateCost() {
        return weight * costPerOunce;
    }
};
class TwoDayPackage : public Package {
private:
    double flatFee;
public:
    TwoDayPackage(string senderName,  string senderAddress, string senderCity,
                  string senderState,string senderZIP, string recipientName,
                   string recipientAddress, string recipientCity, string recipientState,
                   string recipientZIP, double weight, double costPerOunce, double flatFee)
            : Package(senderName, senderAddress, senderCity, senderState, senderZIP, recipientName,
                      recipientAddress, recipientCity, recipientState, recipientZIP, weight, costPerOunce),
              flatFee(flatFee) {}
    double calculatecost(){
        return Package::calculateCost()+flatFee;
    }
};
class OvernightPackage : public Package {
private:
    double additionalFeePerOunce;
public:
    OvernightPackage(string senderName, string senderAddress,  string senderCity,
                      string senderState, string senderZIP, string recipientName,
                      string recipientAddress, string recipientCity, string recipientState,
                      string recipientZIP, double weight, double costPerOunce, double additionalFeePerOunce)
            : Package(senderName, senderAddress, senderCity, senderState, senderZIP, recipientName,
                      recipientAddress, recipientCity, recipientState, recipientZIP, weight, costPerOunce),
              additionalFeePerOunce(additionalFeePerOunce) {}
    double calculatEcost() {
        return Package::calculateCost() + (additionalFeePerOunce * weight);
    }
};
int main(){
    string senderName, senderAddress, senderCity, senderState, senderZIP;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight, costPerOunce;
    cout << "Enter sender's name: ";
    getline(cin, senderName);
    cout << "Enter sender's address: ";
    getline(cin, senderAddress);
    cout << "Enter sender's city: ";
    getline(cin, senderCity);
    cout << "Enter sender's state: ";
    getline(cin, senderState);
    cout << "Enter sender's ZIP code: ";
    getline(cin, senderZIP);
    cout << "Enter recipient's name: ";
    getline(cin, recipientName);
    cout << "Enter recipient's address: ";
    getline(cin, recipientAddress);
    cout << "Enter recipient's city: ";
    getline(cin, recipientCity);
    cout << "Enter recipient's state: ";
    getline(cin, recipientState);
    cout << "Enter recipient's ZIP code: ";
    getline(cin, recipientZIP);
    cout << "Enter package weight in ounces: ";
    cin >> weight;
    cout << "Enter cost per ounce: ";
    cin >> costPerOunce;
    Package package(senderName, senderAddress, senderCity, senderState, senderZIP,
                    recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,weight, costPerOunce);
    cout << "Standard Package Cost: $" << package.calculateCost() << endl;

    return 0;
}

