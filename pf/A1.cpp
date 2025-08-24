#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;

class Bill
{
protected:
    string Item;
    int Quantity;
    int Rate;

public:
    Bill()
    {
        Item = "";
        Quantity = 0;
        Rate = 0;
    }
    void set_Item(string _item)
    {
        Item = _item;
    }
    void set_quantity(int _quantity)
    {
        Quantity = _quantity;
    }
    void set_rate(int _rate)
    {
        Rate = _rate;
    }
    string get_Item()
    {
        return Item;
    }
    int get_quantity()
    {
        return Quantity;
    }
    int get_rate()
    {
        return Rate;
    }
};

void AddItem(Bill b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t1. Add Item." << endl;
        cout << "\t2. Close" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            string item;
            int rate, quantity;
            cout << "Enter the Item Name: ";
            cin >> item;
            b.set_Item(item);
            cout << "Enter the Quantity: ";
            cin >> quantity;
            b.set_quantity(quantity);
            cout << "Enter the Rate: ";
            cin >> rate;
            b.set_rate(rate);

            ofstream out("bbill.txt", ios::app);
            if (!out)
            {
                cout << "\tError: File Can't Open" << endl;
            }
            else
            {
                out << b.get_Item() << ":" << b.get_rate() << ":" << b.get_quantity() << endl;
                out.close();
                cout << "Item Added successfully" << endl;
            }
            Sleep(3000);
        }
        else if (choice == 2)
        {
            close = true;
            cout << "Back to Menu" << endl;
            Sleep(3000);
        }
    }
}

void print_Bill()
{
    system("cls");
    int count = 0;
    bool close = false;
    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string item;
            int quantity;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quantity;

            ifstream in("bbill.txt");
            ofstream out("bill_temp.txt");
            string line;
            bool found = false;

            while (getline(in, line))
            {
                stringstream ss(line);
                string ItemName;
                int ItemRate, ItemQuantity;
                char delimiter1, delimiter2;

                if (getline(ss, ItemName, ':') && ss >> ItemRate >> delimiter1 >> ItemQuantity && delimiter1 == ':')
                {
                    if (item == ItemName)
                    {
                        found = true;
                        if (quantity <= ItemQuantity)
                        {
                            int Amount = ItemRate * quantity;
                            cout << "\tItem  | Rate | Quantity | Amount" << endl;
                            cout << "\t" << ItemName << "\t" << ItemRate << "\t" << ItemQuantity << "\t" << Amount << endl;

                            int NewQuantity = ItemQuantity - quantity;
                            count += Amount;
                            out << ItemName << ":" << ItemRate << ":" << NewQuantity << endl;
                        }
                        else
                        {
                            cout << "Sorry, not enough quantity available." << endl;
                        }
                    }
                    else
                    {
                        out << line << endl;
                    }
                }
                else
                {
                    cout << "Error parsing line: " << line << endl;
                }
            }

            if (!found)
            {
                cout << "\tItem not Available" << endl;
            }

            out.close();
            in.close();
            remove("bbill.txt");
            rename("bill_temp.txt", "bbill.txt");
        }
        else if (choice == 2)
        {
            close = true;
            cout << "\tCounting Total Bill" << endl;
        }
        Sleep(3000);
    }

    system("cls");
    cout << "\tTotal Bill: " << count << endl
         << endl;
    cout << "\tThanks For Shopping" << endl;
    Sleep(5000);
}

int main(int argc, char const *argv[])
{
    Bill b;
    bool exit = false;
    while (!exit)
    {
        system("cls");
        int val;
        cout << "\tWelcome to the Super Market Billing System" << endl;
        cout << "\t*********************************************" << endl;
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Print Bill" << endl;
        cout << "\t3. Exit!" << endl;
        cout << "Enter choice: ";
        cin >> val;

        if (val == 1)
        {
            AddItem(b);
            system("cls");
            Sleep(3000);
        }
        else if (val == 2)
        {
            print_Bill();
        }
        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\tGood Luck" << endl;
            Sleep(3000);
        }
    }
    return 0;
}
