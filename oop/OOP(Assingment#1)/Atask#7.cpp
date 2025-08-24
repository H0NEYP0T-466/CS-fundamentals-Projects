#include <iostream>
#include <string>
using namespace std;
class Product {
protected:
    string productName;
    double price;
    int quantity;
public:
    Product(string name,double p,int q)
        : productName(name),price(p),quantity(q) {}
    void displayProductInfo() 
	{
		cout<<"\t\t\t\t\tDisplaying  Product information\n";
        cout << "Product Name:"<<productName<<endl;
        cout << "Price: $"<<price<<endl;
        cout << "Quantity:"<<quantity<<endl;
    }
};
class Supplier {
protected:
    string supplierName;
    string address;
public:
    Supplier(string name,string addr)
        : supplierName(name),address(addr){}
    void displaySupplierInfo() 
	{
		cout<<"\t\t\t\t\tDisplaying Supplier Informantion\n";
        cout << "Supplier Name: "<<supplierName<<endl;
        cout << "Address: "<<address<<endl;
    }
};
class ProductInfo : public Product, public Supplier {
private:
    string category;
    string expiryDate;
public:
    ProductInfo(string name, double p, int q, string sName, string sAddr, string cat, string expDate)
        : Product(name, p, q), Supplier(sName, sAddr), category(cat), expiryDate(expDate) {}
    void displayProductInfo() {
        Product::displayProductInfo();
        Supplier::displaySupplierInfo(); 
        cout<<"Category: "<<category<<endl;
        cout<<"Expiry Date:"<<expiryDate<<endl;
    }
};
int main() {
    ProductInfo product1("Bag", 19.99, 100, "Ali Suppliers", "Shadara lahore", "Luagage", "2023-12-31");
     product1.displayProductInfo();
    return 0;
}

