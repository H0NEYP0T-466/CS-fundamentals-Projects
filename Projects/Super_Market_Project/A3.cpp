#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
using namespace std;
class shoping {
private:
    int pcode;
    float price;
    float discount;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void modify();
    void Remove();
    void list();
    void receipt();
};

void shoping::menu() {
    int choice;
    string email;
    string password;

    while (true) {
        try {
            cout << "\t\t\t\t________________________________\n"
                 << endl;
            cout << "\t\t\t\t                                \n"
                 << endl;
            cout << "\t\t\t\t  Super Market Main Menu        \n"
                 << endl;
            cout << "\t\t\t\t                                 \n"
                 << endl;
            cout << "\t\t\t\t________________________________\n"
                 << endl;
            cout << "\t\t\t\t  1) Administrator                " << endl;
            cout << " \t\t\t\t  2) Buyer                         " << endl;
            cout << " \t\t\t\t  3) Exit                         " << endl;
            cout << "\t\t\t\t                                 \n"
                 << endl;
            cout << " \t\t\t\t  Please Select: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid choice input.");
            }

            switch (choice) {
            case 1: {
                cout << "\t\t\t\t  Please Login             " << endl;
                cout << "\t\t\t\t  Please Enter Email: ";
                cin >> email;
                cout << "\t\t\t\t  Please Enter Password: ";
                cin >> password;
                if (email == "abc" && password == "123") {
                    administrator();
                } else {
                    throw invalid_argument("Incorrect Email or Password");
                }
                break;
            }
            case 2: {
                buyer();
                break;
            }
            case 3: {
                exit(0);
                break;
            }
            default: {
                throw invalid_argument("Please enter a valid number");
            }
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void shoping::administrator() {
o:
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

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid choice input.");
            }

            if (choice == 1) {
                add();
            } else if (choice == 2) {
                modify();
            } else if (choice == 3) {
                Remove();
            } else if (choice == 4) {
                menu();
            } else {
                throw invalid_argument("Please choose a valid number");
                goto o;
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void shoping::buyer() {
    int choice;
    while (true) {
        try {
            cout << "\t\t\t Buyer " << endl;
            cout << "\t\t\t 1) Buy Product " << endl;
            cout << "\t\t\t 2) Go Back" << endl;
            cout << "\t\t\t Enter your choice: ";
            cin >> choice;

            if (cin.fail()) {
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

void shoping::add() {
    fstream data;
    int c;
    int tokken = 0;
    float p;
    float d;
    string n;
    try {
        cout << "\n\n\n\t\t\tAdd new product" << endl;
        cout << "\n\t\t\tProduct code of the product: ";
        cin >> pcode;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for product code.");
        }
        cout << "\n\t\tName of the Product: ";
        cin >> pname;
        cout << "\n\t\tPrice of the Product: ";
        cin >> price;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for price.");
        }
        cout << "\n\n\t\tDiscount of the product: ";
        cin >> discount;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for discount.");
        }

        data.open("database.txt", ios::in);

        if (!data) {
            data.open("database.txt", ios::app | ios::out);
            data << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
        } else {
            while (data >> c >> n >> p >> d) {
                if (c == pcode) {
                    tokken++;
                    break;
                }
            }
            data.close();

            if (tokken == 0) {
                data.open("database.txt", ios::app | ios::out);
                data << pcode << " " << pname << " " << price << " " << discount << "\n";
                data.close();
            } else {
                throw runtime_error("Product code already exists. Try again!");
            }
        }
        cout << "\t\t\trecord inserted!" << endl;
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void shoping::modify() {
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
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for product code.");
        }
        data.open("database.txt", ios::in);

        if (!data) {
            throw runtime_error("File doesn't exist");
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            while (data >> pcode >> pname >> price >> discount) {
                if (pkey == pcode) {
                    cout << "\t\t\tEnter the new product code: ";
                    cin >> c;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input for product code.");
                    }
                    cout << "\t\t\tEnter the Name of the product: ";
                    cin >> n;
                    cout << "\t\t\tPrice: ";
                    cin >> p;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input for price.");
                    }
                    cout << "\t\t\tEnter the discount on the product: ";
                    cin >> d;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Invalid input for discount.");
                    }
                    data1 << c << " " << n << " " << p << " " << d << "\n";
                    cout << "\t\t\tRecord Edited" << endl;
                    token++;
                } else {
                    data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
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

void shoping::Remove() {
    fstream data, data1;
    int pkey;
    int tokken = 0;
    try {
        cout << "\t\t\tDelete the Product" << endl;
        cout << "\t\t\tProduct Key: ";
        cin >> pkey;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input for product code.");
        }
        data.open("database.txt", ios::in);

        if (!data) {
            throw runtime_error("File not found");
        } else {
            data1.open("database1.txt", ios::app | ios::out);
            while (data >> pcode >> pname >> price >> discount) {
                if (pcode == pkey) {
                    cout << "Product deleted successfully" << endl;
                    tokken++;
                } else {
                    data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
                }
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if (tokken == 0) {
                throw runtime_error("Record not found");
            }
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void shoping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File not found!" << endl;
        return;
    }
    cout << "\n\n___________________________________\n";
    cout << "Product Code\tProduct Name\tPrice\tDiscount\n";
    cout << "___________________________________\n";
    while (data >> pcode >> pname >> price >> discount) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t" << discount << endl;
    }
    data.close();
}

void shoping::receipt() {
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, discount = 0, total = 0;

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
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input for product code.");
            }
            cout << "Enter Product Quantity: ";
            cin >> arrq[c];
            if (cin.fail()) {
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
        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof()) {
            if (pcode == arrc[i]) {
                amount = price * arrq[i];
                discount = amount - (amount * discount / 100);
                total += discount;
                cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << discount << endl;
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
    }
    cout << "\n__________________________________________________________________________________";
    cout << "\nTotal Amount: " << total << endl;
}

int main() {
    shoping s;
    s.menu();
    return 0;
}
