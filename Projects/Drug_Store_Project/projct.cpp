#include <iostream>
#include <fstream>
#include<sstream>
#include<vector>
#include<limits>
using namespace std;
class Store { // Base class
public:
    virtual void show() = 0; // Pure virtual function
};

class Login : public Store { // Derived class of Store
private:
    string username, password;

public:
    void setUsername(const string& user) {
        username = user;
    }
    string getUsername() const {
        return username;
    }
    void setPassword(const string& pass) {
        password = pass;
    }
    string getPassword() const {
        return password;
    }
    void show() override {
        cout << "\n\t\t\t\t\t\t\t ADMIN LOGIN PAGE.";
    loginLabel:
        cout << "\nENTER THE USERNAME: ";
        cin >> username;
        cout << "\nENTER THE PASSWORD: ";
        cin >> password;
        if (username == "abc" && password == "123") {
            cout << "\n" << endl;
        } else {
            cout << "INVALID CREDENTIALS, TRY AGAIN:";
            goto loginLabel;
        }
    }
    Login() : username(""), password("") {}
    ~Login() {}
};

class Drug { // Base class
private:
    string name, quantity;
    int price, id;

public:
    Drug() : name(""), quantity(""), price(0), id(0) {}

    void setId(int d) {
        id = d;
    }
    int getId() const {
        return id;
    }
    void setName(const string& n) {
        name = n;
    }
    string getName() const {
        return name;
    }
    void setPrice(int p) {
        price = p;
    }
    int getPrice() const {
        return price;
    }
    void setQuantity(const string& q) {
        quantity = q;
    }
    string getQuantity()
    const {
        return quantity;
    }
    void display() { // to show
        system("cls");
        cout << "\n\n\t\t\t\tENTER NEW DRUG DETAILS." << endl;
        ofstream fout;
        fout.open("items.txt",ios::app); // ios::out is to open a file for writing.
        o5:
        cout << "ENTER DRUG ID: ";
        cin >> id;
       if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto o5;
} 
o6:
        cout << "ENTER DRUG NAME: ";
        cin >> name;
       if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto o6;
} 
o7:
        cout << "ENTER PRICE: ";
        cin >> price;
        if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto o7;
} 
        
        fout<<"\n"<<id<<"."<<"                       "<<name<<"                 "<<price;
        fout.close();
    }
};

class ShowDrugs : public Drug {
private:
    string name, quantity;
    double id, price, qu, total, total_bill, ID;
public:
    ShowDrugs() : id(0), price(0), name(""), quantity(""), total(0), total_bill(0) {}
    void showMedicineMenu();
    void sell();
    void Order();
    void Payment();
    void showSoldItems();
    void deleteDrug();
};
void ShowDrugs::showMedicineMenu(){
    system("cls");
    cout << "\n\n\t\t\t\tDRUGS AVAILABLE IN THE STORE." << endl;
    cout <<"***************************************************************\n";
    cout<<"DRUGS ID"<<" \t\tDRUGS NAME"<<" \t\tDRUGS PRICE(RM)"<<endl;
    cout<<"***************************************************************\n";
    ifstream reatefile;
    string s;
    reatefile.open("items.txt");
    while(getline(reatefile,s)) {
        cout << s << endl;
    }
    reatefile.close();
}
void ShowDrugs::sell() {
    showMedicineMenu(); // Display the medicine menu to choose from
    int ID;
    bool idFound = false;
o3:
    while (!idFound) {
        cout << "\nEnter the ID of the medicine you want to buy: ";
        cin >> ID;
	if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto o3;
} 

        ifstream fin("items.txt");
        ofstream sold("SOLD_ITEMS.TXT", ios::out | ios::app);

        if (!fin) {
            cout << "File does not exist";
        } else {
            while (fin >> id >> name >> price) {
                if (ID == id) {
                    idFound = true; // Set idFound to true if the ID is found
                    cout << "ID OF THE DRUG: " << id << endl;
                    cout << "NAME OF THE DRUG: " << name << endl;
                    cout << "PRICE OF THE DRUG: " << price << endl;
                    o4:
                    cout << "ENTER THE QUANTITY YOU WANT TO BUY: ";
                    cin >> qu;
                    if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto o4;
} 
                    total = price * qu;
                    total_bill += total;
                    cout << "Total: " << total << endl;
                    sold << "\n" << name << "\t" << price << "\t" << qu;
                    
                }
            }
        }

        if (!idFound) { // Check if the ID is not found
            cout << "No ID found. Please try again.";
        }

        fin.close();
        sold.close();
    }
}

void ShowDrugs::Payment() {
    if (total_bill == 0) {
        cout << "No order has been placed yet." << endl;
        return;
    }

    cout << "\nYour Total Bill is: " << total_bill << endl;
    p:
    cout << "\t\t\tChoose your payment method:\n";
    cout << "1. Credit Card\n";
    cout << "2. Debit Card\n";
    cout << "3. Net Banking\n";
    cout << "4. Cash on Delivery\n";
    cout << "Enter your choice: ";
    int paymentMethod;
    cin >> paymentMethod;
     if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto p;
} 
    switch (paymentMethod) {
        case 1:
        case 2:
        case 3:
            cout << "Payment successful! Thank you for your order." << endl;
            break;
        case 4:
            cout << "Your order has been placed. Payment will be collected on delivery." << endl;
            break;
        default:
            cout << "Invalid payment method." << endl;
            break;
    }
}
void ShowDrugs::showSoldItems() {
    system("cls");
    ifstream sold;
    sold.open("SOLD_ITEMS.TXT", ios::in);
    if (!sold) {
        cout << "File does not exist";
    } else {
       
        cout << "\n\t\tALL SOLD ITEMS.\n\n";
        cout<<"==================================";
        cout << "\nDRUG NAME\tPRICE\tQUANTITY";
        cout<<"\n==================================";
        while (!sold.eof()) {
            sold >> name >> price >> qu;
            cout << "\n" << name << "\t" << price << "\t" << qu << "\n";
        }
    }
    system("pause");
    sold.close();
}
void ShowDrugs::deleteDrug() {
    int ID;
    system("cls");
    ifstream fin("items.txt", ios::in);
    ofstream file("COPY.TXT", ios::out | ios::app);
    if (!fin) {
        cout << "NO SUCH FILE EXISTS." << endl;
    } else {
    	o8:
        cout << "ENTER DRUG ID TO DELETE: ";
        cin >> ID;
        if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid number.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto o8;
} 
        string line;
        vector<string>lines;
        bool idFound = false;
        while (getline(fin, line)) {
            stringstream ss(line);
            string idStr;
            getline(ss, idStr, ' ');
            int id = atoi(idStr.c_str());
            if (ID == id) {
                idFound = true;
            } else {
                lines.push_back(line);
            }
        }
        if (!idFound) {
            cout << "INVALID ID. NO DRUG FOUND WITH THIS ID." << endl;
            goto o8;
        } else {
            cout << "SUCCESSFULLY DELETED." << endl;
        }
        for (int i = 0; i < lines.size(); i++) {
            file << lines[i] << "\n";
        }
    }
    system("pause");
    fin.close();
    file.close();
    remove("items.txt");
    rename("COPY.TXT", "items.txt");
}

int main() {
    int choice;
    char moreItems, morePurchases;
     // pointer to base class
    Login login;
    Drug newDrug;
    ShowDrugs showDrugs;
     // address of login object
    //call show method using pointer to base class
start:
        cout<<"\n";
	    cout<<"\t\t\t\t\t\t DRUG STORE \n";
	    cout<<"\t\t\t\t\t\t************\n";
	    cout<<"\n\t\t\t\tLOGIN PAGE \n";
	    cout<<  "\t\t\t\t=========="<<endl;
        cout<<"\t\t\t1. Customer side  \n";
		cout<<"\t\t\t2. Admin side     \n";
		cout<<"  Enter choice: ";
        cin>>choice;
        if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid input.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto start;
} 
        if(choice==2)
        {
        	
        	Store* store;
        	store = &login;
            store->show();
		   abc:
		   	cout<<"\t\t\t   ***Admin side***   \n";
            cout << "\t\t\t1. TO SHOW ALL DRUGS.\n";
		    cout << "\t\t\t2. TO ADD NEW DRUGS.\n";	
		    cout << "\t\t\t3. TO SHOW SOLD ITEMS.\n";
            cout << "\t\t\t4. TO DELETE DRUGS.\n";
            cout << "\t\t\t5. TO EXIT.\n";
            cout<<"Enter choice: ";
            cin>>choice; 
           if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid input.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto abc;
} 
            if (choice == 1) {
            	showDrugs.showMedicineMenu();
            	system("pause");
            	goto abc;
			} 
             else if (choice == 2) {
             	do {
             		newDrug.display();
             	    cout << "PRESS 'Y' TO ADD MORE DRUGS: ";
                    cin >> moreItems;
                } while (moreItems == 'y' || moreItems == 'Y');
                   goto abc;
                   }
             else if (choice == 3) {
             	showDrugs.showSoldItems();
             	goto abc;
				}
             else if (choice == 4) {
                showDrugs.deleteDrug();
                goto abc;
                }
	         else if (choice == 5) {
	         	system("cls");
	         	cout << "\t\t**************\n";
                cout << "\t\t* THANK YOU *\n";
                cout << "\t\t**************\n";
                return 1;
             }
             else
             {
             	cout<<"Invalid PLease enter a valid input for proceding futher\n";
             	goto abc;
			 }

		   }
	        if(choice==1)
		    {
		    	cout<<"\n";
		    	cout<<"\t\t\t   ***Customer side*** \n";
		    }else{
			cout<<"Invalid input PLease enter valid input for proceding futher\n";
			goto start;
			
		    }
    cba:
    	cout << "\t\t\t1. TO SHOW ALL DRUGS.\n";
        cout << "\t\t\t2. TO ORDER.\n";
        cout << "\t\t\t3. TO EXIT.\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        if (cin.fail() || (cin.peek() != EOF)) {
    cout << "Invalid input! Please enter a valid input.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    goto cba;
} 
        if (choice == 1) {
        	showDrugs.showMedicineMenu();
        	system("pause");
            goto cba;
        } else if (choice == 2) {
           do {
            showDrugs.sell();
            cout << "\nPRESS 'Y' TO BUY MORE DRUGS: ";
            cin >> morePurchases;
            
        } while (morePurchases == 'y' || morePurchases == 'Y');
        showDrugs.Payment();
          goto cba;
       } else if (choice == 3) {
        system("cls");
        cout << "\t\t**************\n";
        cout << "\t\t* THANK YOU *\n";
        cout << "\t\t**************\n";
        return 1;
    }
    else
    {
    	cout<<"Invalid Please Enter a valid input for proceding futher\n";
    	goto cba;
	}
    return 0;
}


