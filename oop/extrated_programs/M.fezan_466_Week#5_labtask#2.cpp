/*
Name:M.fezan
Roll_no:466
Week#5_labTask_2
*/
#include<iostream>
using namespace std;
class account
{
private:
    double accountbalance;
public:
    account(double ac)
    {
        if (ac > 0) {
            accountbalance = ac;
        }
        else
        {
            cout << "The initial balance was invalid" << endl;
            accountbalance = 0.0;
        }
    }
    void credit(double amount)
    {
        accountbalance += amount;
        cout << "Total amount after credit: " << accountbalance << endl;
    }
    void debit()
    {
        double d; 
        cout << "Enter the debit amount: ";
        cin >> d;
        if (d > accountbalance)
        {
            cout << "Debit amount exceeded account balance" << endl;
        }
        else
        {
            accountbalance -= d;
            cout << "Remaining amount after debit: " << accountbalance << endl;
        }
    }
    double getBalance() const {
        return accountbalance;
    }
    virtual ~account() {}
};
class savingaccount : public account
{
private:
    double interestrate;

public:
    savingaccount(double i) : account(i)
    {
        interestrate = i;
    }
    double calculateinterest()
    {
        double interest = getBalance() * interestrate;
        cout << "Interest rate: " << interest << endl;
        return interest;
    }
};
class checkingaccount : public  account
{
private:
    double feecharged;
public:
    checkingaccount(double initialBalance, double fee) : account(initialBalance)
    {
        feecharged = fee;
    }
    void fees()
    {
        cout << "Fee charged: " << feecharged << endl;
        double newBalance = getBalance() - feecharged;
        cout << "Remaining amount after fee deduction: " << newBalance << endl;
    }
    void setFeeCharged(double fee) {
        feecharged = fee;
    }
};
int main() {
    double creditAmount;
    cout << "Enter the credit amount: ";
    cin >> creditAmount;
    account p(456.98);
    p.credit(creditAmount);
    p.debit();
    savingaccount o(9.7);
    double interest = o.calculateinterest();
    o.credit(interest);
    checkingaccount a(456.98, 10); 
    a.fees();
    return 0;
}

