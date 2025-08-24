#include <iostream>
using namespace std;
class ElectricBill {
    double amountPaid;
public:
    ElectricBill(double paidAmount){
        if(paidAmount<0){
            amountPaid=0;
        }else{
            amountPaid=paidAmount;
        }
    }
    void setAmountPaid(double paidAmount){
        if(paidAmount<0){
            amountPaid=0;
        }else{
            amountPaid=paidAmount;
        }
    }
    double getAmountPaid(){
        return amountPaid;
    }
    double getVAT(){
        return 0.18*amountPaid;
    }
    double getEWURA(){
        return 0.01*amountPaid;
    }
    double getREA(){
        return 0.03*amountPaid;
    }
    double getUnits(){
        double remainingAmount=amountPaid-(getVAT()+getEWURA()+getREA()+5000);
        return remainingAmount/295; 
    }
    void display(){
    cout << "Total Amount Paid:"<<getAmountPaid()<<endl;
    cout << "VAT:"<<getVAT()<<endl;
    cout << "EWURA:"<<getEWURA()<<endl;
    cout << "REA:"<<getREA()<<endl;
    cout << "Remaining Units:"<<getUnits();
	}
};
int main() {
    ElectricBill bill(98989);
    bill.display();
    
}

