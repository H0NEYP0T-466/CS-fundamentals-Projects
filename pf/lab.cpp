#include<iostream>
using namespace std;
class toolbooth{
	int numcar;
	double money;
	toolbooth(){
		money=0;
		numcar=0;
	}
	public:
	void paycar(){
		cout<<"Car paid the tax!"<<endl;
		numcar++;
		money+=0.50;
	}
	void nopay(){
		cout<<"Car donot paid the tax"<<endl;
		numcar++;
	}
	void display(){
		cout<<"The total number of cars are"<<numcar<<endl;
		cout<<"The total money is"<<money<<endl;
	}
	void process(){
		char a;
		cout<<"Enter 1 for paying cars\nEnter 2 for not paying cars\nEnter 3 for display list"<<endl;
		cin>>a;
		if(a==1)
		{
			toolbooth.paycar();
		}
		else if(a==2)
		{
			toolbooth.nopay();
		}
		else if(a==3){
			toolbooth.display();
		}
		
	}
};
int mian(){
	toolbooth a;
	while(a==1||a==2){
	a.process();	
	}
	
}

