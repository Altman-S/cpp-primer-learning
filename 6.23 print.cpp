#include <iostream>
using namespace std;

void print(int a, const int *p, int sz) {
    cout << a << endl;
    for (int i = 0; i != sz; ++i) {
    	cout << *p << ' ';
    	++p;
    }
    cout << endl;
}

int main() {
	int i = 0, j[2] = {0, 1};
	int size = sizeof(j)/sizeof(*j);
	print(i, j, size);
	return 0;
}