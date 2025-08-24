#include<iostream>
using namespace std;
class heartrate
{
string firstname,lastname;
int month,year,date;
public:	
int info(){	
	cout<<"Enter your First name:";
	cin>>firstname;
	cout<<"Enter your last name:";
	cin>>lastname;
	cout<<"Enter your Date of birth(d/m/y)";
	cin>>date>>month>>year;
	
}
int calculate(){
	double heartrate=year-220;
	int maxrate=heartrate/60;
	cout<<"your maximun heart rate per minute is:"<<maxrate;
	double targerrate=maxrate;
	cout<<"Your targeted heart rate per minute is:"<<
}
int getter(){
		return firstname,lastname,month,date,year;
	}
};
int main(){
	heartrate obj;
	obj.info();
	obj.calculate();
}
