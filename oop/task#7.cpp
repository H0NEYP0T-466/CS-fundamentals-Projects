#include<iostream>
using namespace std;
class carbonfootprint
{
	public:
    virtual void getcarbonfootprint()
    {
    	cout<<"main class getcarbonfootprint called\n";
	}
};
class building : public carbonfootprint
{
	private:
		int a,b;
	public:
		building(int x,int y)
		{
			a=x;
			b=y;
		}
		void showvariables()
		{
			cout<<"the value of a is"<<a<<"the value of b is"<<b<<endl;
		}
		void getcarbonfootprint()
		{
			cout<<"building getcarbonfootprint called\n";
		}
		void show()
		{
			cout<<"building fucntion is called\n";
		}
		void show1()
		{
			cout<<"building function 2 is called\n";
		}
};
class car :public carbonfootprint
{
	private:
		int ac,ca;
		public:
	car(int x,int y)
	{
	  ac=x;
	  ca=y;	
	}
	void printvariables()
	{
		cout<<"the value of ac is"<<ac<<"the value of ca is"<<ca<<endl;
	}
	void getcarbonfootprint()
		{
			cout<<"car getcarbonfootprint called\n";
		}
	void print()
	{
		cout<<"car function is called\n";
    }
    void print1()
    {
    	cout<<"car function 2 is called\n";
	}
};
class bicycle : public carbonfootprint
{
	private:
		int az,pz;
		public:
			bicycle(int po,int xi)
			{
				az=po;
				pz=xi;
			}
			void displayvariables()
			{
				cout<<"the value of az is"<<az<<"the value of pz is"<<pz<<endl;
			}
	void getcarbonfootprint()
		{
			cout<<"bicycle getcarbonfootprint called\n";
		}
	void display()
	{
		cout<<"bicycle function  is called\n";
	}
	void display1()
	{
		cout<<"bicycle function 2 is called\n";
	}
};

int main()
{
     carbonfootprint* plo;
     building b(11,9);
     plo = &b;
     plo->getcarbonfootprint();	
     car c(22,33);
     plo=&c;
     plo->getcarbonfootprint();
     bicycle bi(9,10);
     plo=&bi;
     plo->getcarbonfootprint();
     b.showvariables();
     c.printvariables();
     bi.displayvariables();
     b.show();
     c.print();
     bi.display();
}
