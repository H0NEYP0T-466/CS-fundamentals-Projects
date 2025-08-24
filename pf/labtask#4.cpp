/*name:M.fezan
roll no:466
week no:4
vat=18 ,monthly service =5000,addition 3(rea),addition 1 ewura*/
#include<iostream>
using namespace std;
class electricbill
{
 double amountpaid;
    public:
    electricbill(int a)
   { 
    amountpaid=a;
 	if(amountpaid<0){
 		amountpaid=0;
	 }
	 else
	 {
	 	amountpaid=amountpaid;
	 	cout<<"Amount Paid:"<<amountpaid<<endl;
	 }
 	
	};  
double getvat()
  {
  	cout<<"VAT tax is 18%:";
 	cout<<amountpaid*0.18<<endl;
 		
  }
double getewura()
{
	
   cout<<"EWURA is additonal 1%:";
    cout<<amountpaid*0.1<<endl;
    
}
double getrea()
{
 	cout<<"REA tax is 3%:";
 	cout<<amountpaid*0.3<<endl;
 	}
double getunits()
{
	double unit=amountpaid*0.18+amountpaid*0.1+amountpaid*0.3;
	cout<<"Units:"<<unit/295;
}
 int setter(int a){
   	amountpaid=a;
   }
   int getter(){
   	return amountpaid;
   }

};
int main(){
electricbill obj(5080);
obj.getewura();
obj.getrea();
obj.getvat();
obj.getunits();
	
	
	
}
