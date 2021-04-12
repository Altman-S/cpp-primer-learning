// created by pi on 11/12/20
// biref: 递减，一直到0

#include <iostream>

using namespace std;

int main() {
	int a = 5;
	auto f = [&a]() -> bool { return (a > 0) ? --a : 0; };
	while (f())
		cout << a << endl;
    return 0;
}