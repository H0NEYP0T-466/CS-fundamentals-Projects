#include <iostream>
#include <string>
using namespace std;
class User
{
protected:
    string username;
    string email;
    string phoneNumber;
public:
    User(string uname, string mail, string phone)
        : username(uname), email(mail), phoneNumber(phone) {}
    void displayInfo() 
	{
		cout<<"\t\t\t\t\tDisplaying Order's Information\n";
        cout<<"Username:"<<username<<endl;
        cout<<"Email:"<<email<<endl;
        cout<<"Phone Number:"<<phoneNumber<<endl;
    }
};
class Customer : public User
{
private:
    string address;
    double walletBalance;
public:
    Customer(string uname, string mail, string phone, string addr, double balance)
        : User(uname, mail, phone), address(addr), walletBalance(balance) {}
    void displayInfo() 
	{
        User::displayInfo();
        cout<<"Address:"<<address<<endl;
        cout<<"Wallet Balance:$"<<walletBalance<<endl;
    }
};
class FoodOrder : public Customer 
{
private:
    string orderDetails;
    double orderAmount;
public:
    FoodOrder(string uname, string mail, string phone, string addr, double balance, string details, double amount)
        : Customer(uname, mail, phone, addr, balance), orderDetails(details), orderAmount(amount) {}
    void displayInfo() 
	{
        Customer::displayInfo();
        cout<<"Order Details:"<<orderDetails<<endl;
        cout<<"Order Amount: $"<<orderAmount<<endl;
    }
};
int main() {
    FoodOrder order1("Ali Raza", "alirza@gmail.com", "+923097413565", "Shadara lahore", 518.0, "Pizza and Soda", 23.0);
    order1.displayInfo();
    return 0;
}

