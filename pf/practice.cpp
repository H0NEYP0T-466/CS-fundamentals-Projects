#include<iostream>
using namespace std;
class gta
{
	private:
int a=13;
public:
   int get(){
   	return a;
   }	
   ~gta(){
   cout<<"defalut ";
   };
};
int main(){
	gta l;

	cout<<l.get();
}

