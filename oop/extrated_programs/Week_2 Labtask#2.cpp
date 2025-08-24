/**
Name:m.fezan
roll no:466
week 2 labtask
**/
#include<iostream>
using namespace std;
struct point{
int x,y;
};
int main(){
	point p1,p2,p3;
	cout<<"Enter coordinates of p1:(x,y)";
	cin>>p1.x>>p1.y;
	cout<<"Enter coordinates of p2:(x,y)";
	cin>>p2.x>>p2.y;
	p3.x=p1.x+p2.x;
	p3.y=p1.y+p2.y;
	cout<<"Coordinates of p1+p2 are:"<<p3.x<<","<<p3.y;
	
}s
