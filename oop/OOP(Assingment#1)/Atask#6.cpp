#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name,degree,department;
    int rollNumber,age;
    double gpa;
public:
    Student(string n, int roll, int a, string deg, string dept, double initialGPA)
        : name(n), rollNumber(roll), age(a), degree(deg), department(dept), gpa(initialGPA) {}
    friend void displayStudentInfo(const Student& student)
	{
	cout<<"\t\t\t\t\tDisplaying Information\n";
    cout << "Name:"<<student.name<<endl;
    cout << "Roll Number:"<<student.rollNumber<<endl;
    cout << "Age:"<<student.age<<endl;
    cout << "Degree:"<<student.degree<<endl;
    cout << "Department:"<<student.department<<endl;
    cout << "GPA:"<<student.gpa<<endl;
    };
    void updateGPA(double newGPA)
	{
        if (newGPA >= 0.0 && newGPA <= 4.0) 
		{
			cout<<"\t\t\t\t\tUpdating Gpa\n";
            gpa=newGPA;
            cout<<"GPA updated successfully."<<endl;
        } else
		{
            cout << "Invalid GPA. Please enter a GPA between 0 and 4.0."<<endl;
        }
    }
};
int main() {
    Student student1("John Doe", 1001, 20,"Computer Science","Engineering",3.5);
    displayStudentInfo(student1);
    student1.updateGPA(3.3);
    displayStudentInfo(student1);
    return 0;
}

