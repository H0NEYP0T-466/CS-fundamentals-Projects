#include<iostream>
using namespace std;
class payroll
{ 
    private:
        string employeename;
        double employeeid,hourlyrate,hoursworked,totalpay;
    public:
    	void setemployeename(string newname)
	{
		employeename=newname;
	}
	void setemployeeid(double newid)
	{
		employeeid=newid;
	}
		void sethourlyrate(double newhourlyrate)
	{
		hourlyrate=newhourlyrate;
	}
	void sehoursworked(double newhoursworked)
	{
		hoursworked=newhoursworked;
	}
	string getemployeename()
	{
		return employeename;
	}
	double getemployeeid()
	{
		return employeeid;
	}
	double gethoursworked()
	{
		return hoursworked;
	}
	double gethourlyrate()
	{
		return hourlyrate;
	}
	void displaypalrollinfo()
	{
		cout<<"\t\t\t\t\tDisplaying Information\n";
		cout<<"Name:"<<getemployeename()<<endl;
		cout<<"Employeeid:"<<getemployeeid()<<endl;
		cout<<"HoursWorked:"<<gethoursworked()<<endl;
		cout<<"Hourlyrate:"<<gethourlyrate()<<endl;
	}
	double calculatepay()
	{
		cout<<"\t\t\t\t\tCalculating pay\n";
		totalpay=gethourlyrate()*gethoursworked();
		cout<<"The amount of pay is $:"<<totalpay;
	}
};
int main()
{
	payroll obj;
	obj.setemployeename("Faizn");
	obj.setemployeeid(466);
	obj.sehoursworked(13);
	obj.sethourlyrate(450);
	obj.displaypalrollinfo();
	obj.calculatepay();
	
}
