#include<iostream>
using namespace std;
template<typename t>
t max(t& a,t& b)
{
	return(a>b)? a:b;
}
int main()
{
	int q,w;
	cout<<"enter first number\n";
	cin>>q;
	cout<<"enter second number\n";
	cin>>w;
	int intmax=max(q,w);
	cout<<"the max number is:"<<intmax;
	double p,o;
	cout<<"enter double 1st number\n";
	cin>>p;
	cout<<"enter double 2st number\n";
	cin>>o;
	double dmax;
	dmax=max(p,o);
	cout<<"the max value of double max is:"<<dmax<<endl;
	
}
