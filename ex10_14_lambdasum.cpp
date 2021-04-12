// created by pi on 11/12/20
// brief: lambda sum

#include <iostream>

using namespace std;

int main() {
	int a, b;
	cout << "Enter two numbers: " << endl;
	cin >> a >> b;
	auto sum = [a, b] { return a + b; };
	cout << "The sum is: " << sum() << endl;
	return 0;
}