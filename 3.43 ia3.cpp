#include <iostream>
#include <cctype>
using namespace std;

int main() {
	int ia[][4]={1,1,2,2,3,3,4,4,5,5,6,6};
	for (int (*p)[4] = begin(ia); p != end(ia); ++p) {
		for (int *q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ';
		cout << endl;
	}
	return 0;
}