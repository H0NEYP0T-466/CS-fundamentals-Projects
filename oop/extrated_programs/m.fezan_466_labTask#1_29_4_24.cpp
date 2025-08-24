#include<iostream>
using namespace std;
class savingaccount
{
    double savingbalance;
    static double annualinterestrate;
 public:
 	savingaccount(double balance)
 	{
 		savingbalance=balance;
	 }
	 void calculateinterest()
	 {
	 	double monthlyinterest = savingbalance*annualinterestrate/12;
	 	savingbalance+=monthlyinterest;
	 }
	 static void modifyinterest(double newrate)
	 {
	 	annualinterestrate=newrate;
	 }
	 double getter()
	 {
	 	return savingbalance;
	 }
	 
};
double savingaccount :: annualinterestrate = 0.0;
int main()
{
	savingaccount saver1(2000.00);
	savingaccount saver2(3000.00);
	savingaccount::modifyinterest(3.0);
	saver1.calculateinterest();
	saver2.calculateinterest();
	cout<<"Month#1 interest rate of Saver 1 : "<<saver1.getter()<<endl;
	cout<<"Month#1 interest rate of Saver 2 : "<<saver2.getter()<<endl;
	savingaccount::modifyinterest(4.0);
	saver1.calculateinterest();
	saver2.calculateinterest();
	cout<<"Month#2 interest rate of Saver 1 : "<<saver1.getter()<<endl;
	cout<<"Month#2 interest rate of Saver 2 : "<<saver2.getter()<<endl;
	return 0;
}
