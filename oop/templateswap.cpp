//question#3 swapp using template
#include <iostream>
using namespace std;
template <typename T>
void swapvalue(T& a,T& b) {
    T temp=a;
    a=b;
    b=temp;
}
template <typename T>
class Swapper {
public:
    void swap(T& a,T& b) {
        swapvalue(a,b);
    }
};
int main() {
    cout<<"Enter the first integer: ";
    int num1;
    cin>>num1;
    cout<<"Enter the second integer: ";
    int num2;
    cin>>num2;
    cout<<"before Swapp values:"<<num1<<"and"<<num2<<endl;
    Swapper<int> swapper;
    swapper.swap(num1, num2);
    cout<<"Swapped values:"<<num1<<"and"<<num2<<endl;
cout << "Enter the first double:";
   double num3;
    cin>>num3;
    cout<<"Enter the second double:";
    double num4;
    cin>>num4;
    cout<<"before Swapp values:"<<num3<<"and"<<num4<<endl;
    Swapper<double> swapperDouble;
    swapperDouble.swap(num3, num4);
    cout<<"Swapped values: "<<num3<<" and " <<num4<<endl;
    return 0;
}

