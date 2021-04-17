#include <iostream>
using namespace std;

int main() {
	int ia[][4]={1,1,2,2,3,3,4,4,5,5,6,6};
	for (int i = 0; i != 3; ++i) {
		for (int j = 0; j != 4; ++j)
			cout << ia[i][j] << ' ';
	    cout << endl;
	}
	return 0;
}