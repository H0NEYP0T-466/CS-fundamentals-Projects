#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream obj;
	obj.open("C:\\Users\\ST\\Desktop\\kratos.txt",::ios_base::app);
	obj<<"thanks for asking i am good";
	return 0;
		
	
} 
