#include<iostream>

using namespace std;
class student
{
   private:
   	string name,degree,cnic,mobilenumber;
   	int rollnumber,age,semester;
   public:
   	void setname(string newname)
   	{
   		name=newname;
	}
	void setdegree(string newdegree)
	{
		degree=newdegree;
	}
	void setcnic(string newcnic)
	{
		cnic=newcnic;
	}
	void setmobilenumber(string newmobilenumber)
	{
		mobilenumber=newmobilenumber;
	}
	void setrollnumber(int newrollnumber)
	{
		rollnumber=newrollnumber;
	}
	void setage(int newage)
	{
		age=newage;
	}
	void setsemester(int newsemester)
	{
		semester=newsemester;
	}
	string getname()
	{
		return name;
	}
	string getmobilenumber()
	{
		return mobilenumber;
	}
	string getdegree()
	{
		return degree;
	}
	string getcnic()
	{
		return cnic;
	}
	int getrollnumber()
	{
		return rollnumber;
	}
	int getage()
	{
		return age;
	}
	int getsemester()
	{
		return semester;
	}
	void display_information()
	{
		cout<<"Name:"<<getname()<<endl;
        cout<<"Roll Number:"<<getrollnumber()<<endl;
        cout<<"Age:"<<getage()<<endl;
        cout<<"Degree:"<<getdegree()<<endl;
        cout<<"Semester:"<<getsemester()<<endl;
        cout<<"Mobile Number:"<<getmobilenumber()<<endl;
        cout<<"CNIC:"<<getcnic()<<endl;
	}
};
int main()
{
	student obj;
	obj.setname("Shoaib Rafiq");
	obj.setdegree("Computer Science");
	obj.setcnic("35202-0511484-5");
	obj.setage(18);
	obj.setmobilenumber("03097413565");
	obj.setrollnumber(466);
	obj.setsemester(2);
    obj.display_information();
	
}
