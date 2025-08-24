//question#2 product using template
#include <iostream>
using namespace std;
template <typename T>
class Calculator {
    T num1;
    T num2;
public:
    Calculator(T n1,T n2)
	{
        num1=n1;
        num2=n2;
    }
    T product() 
	{
        return num1*num2;
    }
};
int main()
{
	int num1,num2,res;
	double num3,num4,res1;
	cout<<"enter first number\n";
	cin>>num1;
	cout<<"enter second number\n";
	cin>>num2;
	Calculator<int>obj(num1,num2);
	res=obj.product();
	cout<<"the product of the number are:"<<res<<endl;
	cout<<"enter double 1st number\n";
	cin>>num3;
	cout<<"enter double 2st number\n";
	cin>>num4;
	Calculator<double>obj1(num3,num4);
	res1=obj1.product();
	cout<<"the product of double numbers are"<<res1<<endl;
}

