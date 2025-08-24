#include<iostream>
using namespace std;
int printTable(int num){
    cout<<"Table of"<<num<<"\n";
    for(int i=1;i<=10;i++)
        cout<<num<<"*"<<i<<"="<<num*i<<endl;
}
int printFac(int num){
    int fac=1;
    for(int i=1;i<=num;i++)
        fac*=i;
    cout<<"Factorial of"<<num<<"="<<fac<<endl;
}
int main(){
    int x,choice;
    cout<<"Please Enter a Value: ";
    cin>>x;
    cout<<"Please Enter your choice\n1 for printing the table of the given number.\n2 for printing the factorial of the given number.\n";
    cin>>choice;
    if (choice<1||choice>2){
        cout<<"Please Enter valid choice\nExiting...";
        return 1;
    }else{
        switch(choice){
            case 1:
                printTable(x);
                break;
            case 2:
                printFactorial(x);
                break;
            default:
                cout<<"Invalid\nExiting program...";
                return 1;
        }
    }
    return 0;
}

