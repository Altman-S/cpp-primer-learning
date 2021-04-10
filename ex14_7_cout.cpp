#include <iostream>

using namespace std;

class String {
public:
	String();
	String(const char *str);
	friend ostream& operator<<(ostream &os, const String &str);
private:
	char *str;
};

ostream& operator<<(ostream &os, const String &str)
{
	cout << str;
	return os;
}