#include<iostream>
using namespace std;
class cal{
	int num;

	public:
			int choise;
		void input(){
			cout<<"Enter a number \n";
			cin>>num;
			cout<<"Enter 1 for table \nEnter 2 for factorial\n";
			cin>>choise;
		}
		void table(){
			for (int i=1;i<=10;i++){
				int res=num*i;
				cout<<num<<"*"<<i<<"="<<res<<endl;
			}
		}
		void fac(){
			int a=1;
			for (int i=1;i<=num;i++){
				a*=i;
				
				
			}
			cout<<a;
		}
};
int main(){
	cal a;
	a.input();
	if (a.choise==1){
		a.table();
	}
	else if(a.choise==2){
		a.fac();
		
	}
	else{
		cout<<"invalid";
	} 
	
}
