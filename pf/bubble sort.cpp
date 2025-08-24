#include<iostream>
using namespace std;
int main(){
     int temp[5]={};
     cout<<"enter five random numbers\n";
     for(int i=0;i<5;i++){
     	cin>>temp[i];
	 }
	 cout<<"you entered\n";
	 for(int i=0;i<5;i++){
     	cout<<temp[i]<<endl;}
     	int cont=1;
     	int n;
     	while(cont<5){
     		for(int i=0;i<5-cont;i++){
     			if(temp[i]>temp[i+1]){
     				 n=temp[i];
     				temp[i]=temp[i+1];
     				temp[i+1]=n;     				
				 }
			 }
			 cont++;
		 }
		 cout<<"sorted array is\n";
       for(int i=0;i<5;i++){
       	cout<<temp[i]<<" ";
	   }cout<<"";
	   return 0;
}
