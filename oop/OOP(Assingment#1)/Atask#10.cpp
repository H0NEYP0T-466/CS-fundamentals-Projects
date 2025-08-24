#include <iostream>
#include <string>
using namespace std;
class Student 
{
protected:
    string name;
    int rollNumber;
    string department;
public:
    Student(string n, int roll, string dept)
        : name(n), rollNumber(roll), department(dept) {}
    void displayStudentInfo() 
	{
        cout<<"Name:"<<name<<endl;
        cout<<"Roll Number:"<<rollNumber<<endl;
        cout<<"Department:"<<department<<endl;
    }
};
class Results : public Student 
{
private:
    double gpa;
    int totalCredits;
public:
    Results(string n, int roll, string dept, double g, int credits)
        : Student(n, roll, dept), gpa(g), totalCredits(credits) {}
    void displayResultsInfo() 
	{
        
        cout<<"GPA:"<<gpa<<endl;
        cout<<"Total Credits:"<<totalCredits<<endl;
    }
};
class Scholarship : public Student 
{
private:
    string scholarshipType;
    double scholarshipAmount;
public:
    Scholarship(string n, int roll, string dept, string type, double amount)
        : Student(n, roll, dept), scholarshipType(type), scholarshipAmount(amount) {}
    void displayScholarshipInfo() 
	{
        displayStudentInfo();
        cout<<"Scholarship Type:"<<scholarshipType<<endl;
        cout<<"Scholarship Amount: $"<<scholarshipAmount<<endl;
    }
    double getamount()
    { 
       return scholarshipAmount;
	}
};
class Fee : public Results, public Scholarship
{
public:
    Fee(string n, int roll, string dept, double g, int credits, string type, double amount)
        : Results(n, roll, dept, g, credits), Scholarship(n, roll, dept, type, amount) {}
    void displayFeeInfo() 
	{
         displayScholarshipInfo();
		 displayResultsInfo();
        double fes=12000;
		cout<<"The amount of fees is:$"<<fes<<endl;
		cout<<"The amount of fees after scholarship is:$"<<fes-getamount();
    }
};
int main() {
    Fee studentFee("Faizan", 466, "Computer Science", 3.9, 120, "Merit", 1000.0);
    cout << "\t\t\t\t\tStudent Fee Information:\n";
    studentFee.displayFeeInfo();
    return 0;
}

