#include <iostream>
using namespace std;
class Invoice {
    string partNumber,partDescription;
    int quantity,pricePerItem;
    double taxRate,discountRate;
public:
    Invoice(string partNum, string partDesc, int qty, int price, double tax = 0.20, double discount = 0.0)
        : partNumber(partNum), partDescription(partDesc), quantity(qty), pricePerItem(price), taxRate(tax), discountRate(discount) {}
    double getInvoiceAmount()const{
        double amount=quantity*pricePerItem;
        amount*=(1+taxRate); 
        amount*=(1-discountRate);
        return amount;
    }
    void displayInvoice() const {
        cout<<"Part Number:"<<partNumber<<endl;
        cout<<"Part Description:"<<partDescription<<endl;
        cout<<"Quantity:"<<quantity<<endl;
        cout<<"Price Per Item:"<<pricePerItem<<endl;
        cout<<"Tax Rate:"<<taxRate<<endl;
        cout<<"Discount Rate:"<<discountRate<<endl;
        cout<<"Invoice Amount:"<<getInvoiceAmount()<<endl;
    }
};
int main() {
    string partNum, partDesc;
    int quantity, price;
    cout<<"\t\t\t\t\t\tInvoice Bill"<<endl;
    cout<<"Enter Part Number:";
    getline(cin,partNum);
    cout<<"Enter Part Description:";
    getline(cin,partDesc);
    cout<<"Enter Quantity:";
    cin>>quantity;
    cout<<"Enter Price Per Item:";
    cin>>price;
    Invoice invoice(partNum, partDesc, quantity, price);
    invoice.displayInvoice();
    return 0;
}

