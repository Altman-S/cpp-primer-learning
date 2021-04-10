#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	static int sn;
public:
	Employee() { mysn = sn++; }
	Employee(const string&s) { name = s; mysn = sn++; }
	const string& get_name() { return name; }
	int get_mysn() { return mysn; }
private:
	string name;
	int mysn;
};


int Employee::sn = 0;

void f(Employee &s) 
{
	cout << s.get_name() << ":" << s.get_mysn() << endl;
}

int main()
{
	Employee a("彭"), b = a, c;  //使用合成的拷贝构造函数，只进行简单复制
	c = b;
	f(a);f(b);f(c);

	return 0;
}