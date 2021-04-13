#include <iostream>
#include <string>
using namespace std;


class NoDefault {
public:
	NoDefault() = default;
	NoDefault(int ht) : height(ht) { }
	int height;
};


class C {
public:
	NoDefault nd;
	C(int j = 666) : nd(j) { }
};


int main() {
    C c;
    cout << c.nd.height << endl;
    return 0;
}