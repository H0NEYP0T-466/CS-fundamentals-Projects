/**
Name:m.fezan
roll no:466
week 2 labtask
**/#include<iostream>
using namespace std;
struct time{
	int hour,min,sec;
	void input(){
	cout<<"Enter time in hour:";
	cin>>hour;
		cout<<"Enter time in min:";
		cin>>min;
		cout<<"Enter time in sec:";
	cin>>sec;
}
void display(){
	cout<<"You entered\t"<<hour<<":"<<min<<":"<<sec<<endl;
	int totalsec=hour*3600+min*60+sec;
	cout<<"The time in seconds is:"<<totalsec;
}
};
int main(){
   time t;
   t.input();
   t.display();
}
