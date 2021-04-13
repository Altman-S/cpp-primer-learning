#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	string strName = "Altman";
	string strAddress = "ADC 7731";
public:
	Person() = default;
	Person(const string &name, const string &add) {
		strName = name;
		strAddress = add;
	}
//friend Person(std::istream &is) { is >> *this; }
friend string getName();
friend string getAddress();
public:
	string getName() const { return strName; }
	string getAddress() const { return strAddress; }
};

// string getName() { return strName; }
// string getAddress() { return strAddress; }

int main() {
	string s;
	string d;
	Person pp;
    s = pp.getName();
    d = pp.getAddress();
    cout << s << endl;
    cout << d << endl;
    return 0;
}