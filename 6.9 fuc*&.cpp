#include <iostream>
using namespace std;

int main() {
	int i = 0;
	int j = 1;
	int *p = &i;
	*p = 10;
	cout << i << endl;
	return 0;
}