#include <iostream>
#include <string>
using namespace std;
class Patient 
{
protected:
    string patientname;
    int patientid;
    string disease;
public:
    int age;
    char gender;
    bool admitted;
    Patient(string name, int id, string illness)
        : patientname(name), patientid(id), disease(illness), age(0), gender(' '), admitted(false) {}
    void admitpatient()
	{
        admitted=true;
        cout<<"Patient"<<patientname<<"has been admitted"<<endl;
    }
    void dischargePatient() 
	{
        admitted=false;
        cout<<"Patient"<<patientname<<"has been discharged"<<endl;
    }
    void displayPatientInfo() 
	{
        cout<<"Patient ID:"<<patientid<<endl;
        cout<<"Name:"<<patientname<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"Gender:"<<gender<<endl;
        cout<<"Disease:"<<disease<<endl;
        cout<<"Admitted:"<<(admitted ? "Yes" : "No") << endl;
    }
};
class EmergencyPatient : public Patient {
private:
    string emergencycontact;
public:
    EmergencyPatient(string name,int id,string illness,string contact)
        : Patient(name, id, illness),emergencycontact(contact) {}
    void displayEmergencyPatientInfo() 
	{
        displayPatientInfo();
        cout<<"Emergency Contact:"<<emergencycontact<<endl;
    }
};
int main() {
    Patient obj1("Ali Raza",1001,"Fever");
    obj1.age=35;
    obj1.gender='M';
    obj1.admitpatient();
    obj1.displayPatientInfo();
    cout<<endl;
    EmergencyPatient obj2("Shoaib Rafiq",2001,"Heart Attack"," 0304567890");
    obj2.age=45;
    obj2.gender='F';
    obj2.admitpatient();
    obj2.displayEmergencyPatientInfo();
    return 0;
}

