#include <iostream>
using namespace std;

void pexchange(int *&a, int *&b) {
    int *t = a;
    a = b;
    b = t;
}

int main() {
	int i = 1, j = 2;
	int *p = &i;
	int *q = &j;
	cout << "*p=" << *p << "  " << "*q=" << *q <<endl;
    pexchange(p, q);
    cout << "*p=" << *p << "  " << "*q=" << *q <<endl;
    return 0;
}