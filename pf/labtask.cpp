#include<iostream>
using namespace std;
class invoice{
	private:
	string partnumber,partdescription;
	int quantity,priceperitem;
	double value,discount;
	public:
		invoice(string d,e){
			partnumber=d;
			partdescription=e;
			}
			invoice(int f,g,double value,discount){
			
			quantity=f;
			priceperite=g;
			value=0.20;
			discount=0.20;}
		}
		void getinvoiceamount(){	
			int x=f*g;
			cout<<"The total amount is:"<<x<<endl;
			cout<<"Amount after tax is (tax=10%):"<<x/0.90<<endl;
			cout<<"Amount after discount is(discount=33)"<<x-33<<endl;
		}
		void input(){
			cout<<"Enter part number\n";
			cin>>partnumber;
			cout<<"Enter part description\n";
			cin>>partdescription;
			cout<<"Enter quanity number\n";
			cin>>quantity;
			cout<<"Enter price per item\n";
			cin>>priceperitem;
		}
};
int main(){
	invoice b(string d,e,int f,g);
	b.input();
	b.getinvoiceamount();
}
