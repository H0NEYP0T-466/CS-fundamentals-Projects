#include<iostream>
using namespace std;
template<typename t>
t add(t num1,t num2)
{
	return (num1+num2);
}
template<typename t>
t sub(t num1,t num2)
{
	return(num1-num2);
}
int main()
{
	int add0, sub0;
	double add1,sub1;
	add0=add<int>(10,15);
	cout<<"the reuslt of int is:"<<add0<<endl;
	add1=add<double>(99.98,27.56);
	cout<<"the result of double is:"<<add1<<endl;
	sub0=sub<int>(10,5);
	cout<<"the result of sub of int is:"<<sub0<<endl;
	sub1=sub<double>(4.5,2.2);
	cout<<"the result of sub of double is:"<<sub1;
}
