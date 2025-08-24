#include<iostream>
using namespace std;
class employee
{
	private:
		string employeename;
		int employeeid,hoursworked,hourlyrate;
	public:
	void setemployeename(string newname)
	{
		employeename=newname;
	}
	void setemployeeid(int newid)
	{
		employeeid=newid;
	}
	void sehoursworked(int newhoursworked)
	{
		hoursworked=newhoursworked;
	}
	void sethourlyrate(int newhourlyrate)
	{
		hourlyrate=newhourlyrate;
	}
	string getemployeename()
	{
		return employeename;
	}
	int getemployeeid()
	{
		return employeeid;
	}
	int gethoursworked()
	{
		return hoursworked;
	}
	int gethourlyrate()
	{
		return hourlyrate;
	}
	void displayinformation()
	{
		cout<<"Name:"<<getemployeename()<<endl;
		cout<<"Employeeid:"<<getemployeeid()<<endl;
		cout<<"HoursWorked:"<<gethoursworked()<<endl;
		cout<<"Hourlyrate:"<<gethourlyrate()<<endl;
	}
	double calculatingpay()
	{
		double pay=gethourlyrate()*gethoursworked();
		cout<<"The amount of pay is $:"<<pay;
	}
};
Int main()
{
	employee obj;
	obj.setemployeename("Azan");
	obj.setemployeeid(466);
	obj.sehoursworked(15);
	obj.sethourlyrate(879);
	obj.displayinformation();
	obj.calculatingpay();
	
	
}
