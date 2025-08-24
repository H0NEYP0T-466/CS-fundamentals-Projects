#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    int age;
    string address;
    string phoneNumber;
public:
    Person(string n, int a, string addr, string phone)
        : name(n), age(a), address(addr), phoneNumber(phone) {}
    void displayInfo() 
	{
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Phone Number:"<<phoneNumber<<endl;
    }
};
class Student : public Person 
{
private:
    int rollNumber;
    string department;
public:
    Student(string n, int a, string addr, string phone, int roll, string dept)
        : Person(n, a, addr, phone), rollNumber(roll), department(dept) {}
    void displayInfo() 
	{
        Person::displayInfo();
        cout<<"Roll Number:"<<rollNumber<<endl;
        cout<<"Department:"<<department<<endl;
    }
};
class Staff : public Person 
{
private:
    string designation;
    double salary;
public:
    Staff(string n, int a, string addr, string phone, string desig, double sal)
        : Person(n, a, addr, phone), designation(desig), salary(sal) {}
    void displayInfo() 
	{
        Person::displayInfo();
        cout<<"Designation:"<<designation<<endl;
        cout<<"Salary: $"<<salary<<endl;
    }
};
int main() {
    Student student1("Umer Malik",20,"Shadara Lahore","0303987838",1001,"Computer Science");
    Staff staff1("Umer Malik",20,"Shadara Lahore", "0303987838", "Manager",60000.0);
    cout<<"\t\t\t\t\tDisplaying Student Information\n";
	student1.displayInfo();w
    cout << "\t\t\t\t\tStaff Information\n";
    staff1.displayInfo();
    return 0;
}

