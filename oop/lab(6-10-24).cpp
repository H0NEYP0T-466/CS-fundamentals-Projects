#include <iostream>
#include <string>
using namespace std;
class Package {
private:
    string senderName,senderAddress,senderCity, senderState;
    int senderZIP;
	double weight,cost;
public:
    Package(string n, string a, string c, string s, int z, double w, double co)
        : senderName(n), senderAddress(a), senderCity(c), senderState(s), senderZIP(z), weight(w), cost(co) {
        if (w <= 0) {
            cout<<"Please enter a positive value for weight"<<endl;
            weight = 0;
        }
        if (co <= 0) {
            cout<<"Please enter a positive value for cost"<<endl;
            cost = 0;
        }
    }
    void printInfo() {
        cout<<"Sender Name: "<<senderName<<endl;
        cout<<"Sender Address: "<<senderAddress<<endl;
        cout<<"Sender City: "<<senderCity<<endl;
        cout<<"Sender State: "<<senderState<<endl;
        cout<<"Sender ZIP: "<<senderZIP<<endl;
        cout<<"Weight: "<<weight<<"ounces"<<endl;
        cout<<"Cost per ounce: $"<<cost<<endl;
    }
    double calculateCost() {
        return weight * cost;
    }
};
class TwoDayPackage : public Package {
private:
    double flatFee;
public:
    TwoDayPackage(string n, string a, string c, string s, int z, double w, double co, double f)
        : Package(n, a, c, s, z, w, co), flatFee(f) {}
    int calculateCost() {
        return Package::calculateCost() + flatFee;
    }
};
class nightpakage : public Package
{
	private:
		double fee;
		public:
	nightpakage(string n,string a,string c,string s,int z,double w,double co,double fe)
	: Package(n,a,c,s,z,w,co),fee(fe){}
	double nightpakagefee()
	{
		return Package::calculateCost()*fee;
	}
	
};
int main() {
    Package p("Faizan", "Shadara", "Lahore", "Punjab", 54989, 25, 13);
    TwoDayPackage t("Shoaib", "Jail-Road", "Lahore", "Punjab", 8798, 33, 4, 10);
    nightpakage n("ali", "Bund-Road", "Lahore", "Sindh", 898, 43, 8, 19);
    cout<<"Information of Standard Package:"<<endl;
    p.printInfo();
    cout<<"Information of Two-Day Package:"<<endl;
    t.printInfo();
    cout<<"Information of Night-Package:"<<endl;
    n.printInfo();
    cout<<"Standard Package Cost: $"<<p.calculateCost()<<endl;
    cout<<"Two-Day Package Cost: $"<<t.calculateCost()<<endl;
    cout<<"Nigh-Package Cost: $"<<n.nightpakagefee()<<endl;

}

