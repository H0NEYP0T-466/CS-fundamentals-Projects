/**
**/
#include<iostream>
using namespace std;
class toolboth
{
private:
    int numcar;
    double money;
    char a;
public:
	 toolboth(){
    	numcar = 0;
    	money=0;
	}
    void paycar()
	 {
        cout<<"Car paid the toll tax!\n"<<endl;
        numcar++;
        money+=0.50;
    }
    void nopay() 
	{
        cout<<"Car not paid the toll tax!\n"<<endl;
        numcar++;
    }
    void display() 
	{
        cout<<"Total number of cars are:"<<numcar<<endl;
        cout<<"Total amount of money is:"<<money<<"$"<<endl;
    }
    void input() 
	{
        cout<<"Enter 1 for paying cars:\nEnter 2 for not paying cars:\nEnter 3 to display total list:\n";
        cin>>a;
        if(a=='3')
		{
            display();
        } else if(a=='1') 
		{
            paycar();
        } else if(a=='2') 
		{
            nopay();
        } else{
            cout<<"Invalid input! Please enter 1,2 or 3"<<endl;
        }
    }
    char res() 
	{ 
        return a;
    }
};
int main() {
    cout<<"\t\t\t\t\tWelcome to tollbooth application"<<endl;
    toolboth x;
    while (true) 
	{
        x.input();
        if(x.res()=='3') 
            break; 
    }
    cout<<"Exiting the program."<<endl;
    return 0;
}

