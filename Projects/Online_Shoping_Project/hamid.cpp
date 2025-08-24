#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
using namespace std;
class store
{
	public:
	virtual	void menu()=0;
     virtual void administrator()=0;
    virtual void buyer()=0;
   virtual void add()=0;
   virtual void modify()=0;
    virtual void Remove()=0;
    virtual void list()=0;
    virtual void receipt()=0;
};
class shopping : public store
{
private:
    int pcode;
    float price;
    float discount;
    int q;
    string pname;
    public:
    	void menu() {
    int choice;
    while (true) {
        try {
            cout << "\t\t\t\t_________________________________" << endl;
            cout << "\t\t\t\t|                                |" << endl;
            cout << "\t\t\t\t|  Online Shopping Main Menu     |" << endl;
            cout << "\t\t\t\t|                                |" << endl;
            cout << "\t\t\t\t|  1) Seller                     |" << endl;
            cout << "\t\t\t\t|  2) Buyer                      |" << endl;
            cout << "\t\t\t\t|  3) Exit                       |" << endl;
            cout << "\t\t\t\t|                                |" << endl;
            cout << "\t\t\t\t________________________________\n" << endl;

            cout << " \t\t\t\t  Please Select: ";
            cin >> choice;

            if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid choice input.");
            }

            switch (choice) {
            case 1:
                administrator();
                break;
            case 2:
                buyer();
                break;
            case 3:
                exit(0);
                break;
            default:
                throw invalid_argument("Please enter a valid number");
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void administrator() {
    int choice;
    while (true) {
        try {
            cout << "\t\t Admin Menu \t\t\t" << endl;
            cout << " \t\t\t 1) Add the product" << endl;
            cout << "\t\t\t 2) Modify the Product" << endl;
            cout << "\t\t\t 3) Delete the Product" << endl;
            cout << "\t\t\t 4) Back to the Main Menu" << endl;
            cout << "\t\t\t Please Enter your choice: ";
            cin >> choice;

            if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid choice input.");
            }

            switch (choice) {
            case 1:
                add();
                break;
            case 2:
                modify();
                break;
            case 3:
                Remove();
                break;
            case 4:
                menu();
                return;
            default:
                throw invalid_argument("Please choose a valid number");
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void buyer() {
    int choice;
    while (true) {
        try {
            cout << "\t\t\t Buyer " << endl;
            cout << "\t\t\t 1) Buy Product " << endl;
            cout << "\t\t\t 2) Go Back" << endl;
            cout << "\t\t\t Enter your choice: ";
            cin >> choice;

            if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid choice input.");
            }

            switch (choice) {
            case 1:
                receipt();
                break;
            case 2:
                return;
            default:
                throw invalid_argument("Please enter a valid option");
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void add() {
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    try {
        cout << "\n\n\n\t\t\tAdd new product" << endl;
        cout << "\n\t\t\tProduct code of the product: ";
        cin >> pcode;
        if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for product code.");
        }
        cout << "\n\t\tName of the Product: ";
        cin >> pname;
        cout << "\n\t\tQuantity of the Product: ";
        if (!(cin >> q)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for quantity.");
        }
        cout << "\n\t\tPrice of the Product: ";
        if (!(cin >> price)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for price.");
        }
        cout << "\n\n\t\tDiscount of the product: ";
        if (!(cin >> discount)||discount>100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for discount.");
        }

        data.open("database.txt", ios::in);
        if (!data) {
            throw runtime_error("Unable to open database file for reading.");
        }

        while (data >> c >> ws && getline(data, n, ' ') >> p >> q >> d) {
            if (c == pcode) {
                token++;
                break;
            }
        }

        data.close();

        if (token == 0) {
            data.open("database.txt", ios::app | ios::out);
            if (!data) {
                throw runtime_error("Unable to open database file for writing.");
            }
            data << pcode << " " << pname << " " << price << " " << q << " " << discount << "\n";
            data.close();
            cout << "Product added successfully!" << endl;
        } else {
            throw runtime_error("Product code already exists. Try again!");
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}
void modify() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    try {
        cout << "\n\n\nModify the record" << endl;
        cout << "\t\t\tProduct code: ";
        cin >> pkey;
        if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for product code.");
        }
        data.open("database.txt", ios::in);
        if (!data) {
            throw runtime_error("File doesn't exist");
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            while (data >> pcode >> pname >> price >> q >> discount) {
                if (pkey == pcode) {
                    cout << "\t\t\tEnter the new product code: ";
                    cin >> c;
                    if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input for product code.");
                    }
                    cout << "\t\t\tEnter the Name of the product: ";
                    cin >> n;
                    cout << "\t\t\tPrice: ";
                    cin >> p;
                    if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input for price.");
                    }
                    cout << "\t\t\tEnter the discount on the product: ";
                    cin >> d;
                    if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input for discount.");
                    }
                    cout << "\t\t\tEnter the new quantity: ";
                    cin >> q; // Update the quantity
                    data1 << c << " " << n << " " << p << " " << q << " " << d << "\n";
                    cout << "\t\t\tRecord Edited" << endl;
                    token++;
                } else {
                    data1 << pcode << " " << pname << " " << price << " " << q << " " << discount << "\n";
                }
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (token == 0) {
                throw runtime_error("Record not found");
            }
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}


void Remove() {
    fstream data, data1;
    int pkey;
    int token = 0;
    try {
        cout << "\t\t\tDelete the Product" << endl;
        cout << "\t\t\tProduct Key: ";
        cin >> pkey;
        if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for product code.");
        }
        data.open("database.txt", ios::in);

        if (!data) {
            throw runtime_error("File not found");
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            while (data >> pcode >> pname >> price >> q >> discount) {
                if (pcode == pkey) {
                    cout << "Product deleted successfully" << endl;
                    token++;
                } else {
                    data1 << pcode << " " << pname << " " << price << " " << q << " " << discount << "\n";
                }
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (token == 0) {
                throw runtime_error("Record not found");
            }
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void list() {
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File not found!" << endl;
        return;
    }
    cout << "\n\n___________________________________\n";
    cout << "Product Code\tProduct Name\tPrice\tQuanity\tDiscount\n";
    cout << "___________________________________\n";
    while (data >> pcode >> pname >> price >> q >> discount) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t" << q << "\t" << discount << endl;
    }
    data.close();
}

void receipt() {
    fstream data, data1;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, dis = 0, total = 0;
    cout << "\n\n\t\t\tRECEIPT" << endl;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "Database is empty!" << endl;
        return;
    }
    data.close();
    do {
        try {
            list();
            cout << "\n\nEnter Product Code: ";
            cin >> arrc[c];
            if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input for product code.");
            }
            cout << "Enter Product Quantity: ";
            cin >> arrq[c];
            if (cin.fail()||cin.peek()!=EOF&&cin.peek()!='\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input for product quantity.");
            }
            c++;
            cout << "Do you want to buy another product? (y/n): ";
            cin >> choice;
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice == 'y' || choice == 'Y');
    
    cout << "\n\n\t\t\t______________________RECEIPT____________________\n";
    cout << "Product No\t Product Name \t Quantity \t Price \t Amount \t Amount with Discount\n";
    cout << "__________________________________________________________________________________\n";

    for (int i = 0; i < c; i++) {
        bool productFound = false;
        data.open("database.txt", ios::in);
        data1.open("database1.txt", ios::out | ios::app);
        
        while (data >> pcode >> pname >> price >> q >> discount) {
            if (pcode == arrc[i]) {
                if (q < arrq[i]) {
                    cout << "Not enough quantity in stock for product code " << pcode << "." << endl;
                    productFound = true;
                } else {
                    amount = price * arrq[i];
                    dis = amount - (amount * discount / 100);
                    total += dis;
                    cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis << endl;
                    
                    // Update quantity
                    q -= arrq[i];
                    productFound = true;
                }
            }
            data1 << pcode << " " << pname << " " << price << " " << q << " " << discount << "\n";
        }

        data.close();
        data1.close();

        if (!productFound) {
            cout << "Product code " << arrc[i] << " not found in the database." << endl;
        }

        // Remove the old database and rename the temporary file to database
        remove("database.txt");
        rename("database1.txt", "database.txt");
    }

    cout << "\n__________________________________________________________________________________";
    cout << "\nTotal Amount: " << total << endl;
    
    int temp;
    cout << "Enter Payment Method:\n1-Cash on delivery\n2-Credit card\n";
    cin >> temp;
    if (temp == 1) {
        cout << "Cash On delivery selected. Order Placed\n";
    } else if (temp == 2) {
        cout << "Payment Successful. Thanks for shopping\n";
    } else {
        cout << "Invalid. Please enter a valid input\n";
    }
}
};
int main() {
    store* ptr;
    shopping obj;
    ptr=&obj;
    ptr->menu();
    return 0;
}

