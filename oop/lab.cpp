#include<iostream>
using namespace std;
class account
{
	private:
		string account_number;
		double balance;
	public:
		account(string an,double b)
		{
			account_number=an;
			balance=b;
		}
	void withdraw()
	{
		double amount;
		try
		{
			cout<<"enter the amount you want to withdraw\n";
			cin>>amount;
			if(amount>balance)
			{
				throw (amount);
			}
			balance=balance-amount;
			cout<<"remaining balance is"<<balance;
		}
		catch(double a)
		{
			cout<<"Insuficient balance:your account balance is less balance than"<<a;
		}
	}
		
};
int main()
{
	account obj("1234",1000);
	obj.withdraw();
}

