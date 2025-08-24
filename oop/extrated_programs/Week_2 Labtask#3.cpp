/**
Name:m.fezan
roll no:466
week 2 labtask
**/#include <iostream>
using namespace std;
struct phone {
	string mynum="(212) 767-8900";
    int areaCode;
    int exchange;
    int number;
    void input(){
    	cout<<"Enter your area code, exchange, and number: ";
    cin>>areaCode>>exchange>>number;
	}
	void display(){
		 cout<<"My number is "<<mynum<<endl;
    cout<<"Your number is("<<areaCode<<")"<<exchange<<"-"<<number<<endl;
	}
};
int main() {
 phone p;
 p.input();
 p.display();
}


