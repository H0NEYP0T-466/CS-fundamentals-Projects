#include<iostream>
using namespace std;
class parent
{
	public:
		void show_parent(){
			cout<<"parent function is called";
		}
};
class child : public parent
{
	public:
		void show_child(){
			cout<<"child function is called\n";
			}
};
int main(){

	child c1;
	c1.show_child();
	c1.show_parent();
	
}
