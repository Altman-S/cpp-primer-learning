#include <iostream>
using namespace std;

int main() {
	int ia[][4]={1,1,2,2,3,3,4,4,5,5,6,6};
	for (int (&row)[4] : ia) {
		for (int &col : row)
			cout << col << ' ';
	    cout << endl;
	}
    return 0;
}