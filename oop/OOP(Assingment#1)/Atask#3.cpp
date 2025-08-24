#include<iostream>
using namespace std;
class bankaccount                                                                                                                                                         
{ 
    private:
          string holdername,accounttype,branchname; 	
          double balance,interestrate,accountnumber; 
    public:
	      bankaccount(string newholdername,string newaccounttype,string newbranchname,double newbalance,double newinterestrate,double newaccountnumber)
		  {
           holdername=newholdername;
		   accounttype=newaccounttype;
		   branchname=newbranchname;
		   balance=newbalance;
		   interestrate=newinterestrate;
		   accountnumber=newaccountnumber;		  	
		  }
		void display()
		{
			cout<<"\t\t\t\t\tDisplaying Account Information\n";
			cout<<"Holder's Name:"<<holdername<<endl;
			cout<<"Account Type:"<<accounttype<<endl;
			cout<<"Branch Name:"<<branchname<<endl;
			cout<<"Balance in the account is:$"<<balance<<endl;
			cout<<"The interest rate is:"<<interestrate<<endl;
			cout<<"The account number is:"<<accountnumber<<endl;
		}
		double deposit(double depositamount)
		{
			cout<<"\t\t\t\t\tDepositing Funds\n";
			cout<<"Your Current Balance is:"<<balance<<endl;
			balance+=depositamount;
			cout<<"Your Updated Balance is:"<<balance<<endl;
		}
		double withdraw(double withdrawamount)
		{
			cout<<"\t\t\t\t\tWithdrawing Funds\n";
			cout<<"Your Current balance is:"<<balance<<endl;
			balance-=withdrawamount;
			cout<<"Your Updated balance is:"<<balance<<endl;
		}
};
int main()
{
	bankaccount obj("faizan","Savings","Shadara",100,9.9,8989);
	obj.display();
	obj.deposit(100);
	obj.withdraw(9);
}
