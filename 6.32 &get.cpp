#include <iostream>
using namespace std;

int &get(int *array, int index) {return array[index];}

int main() {
	int ia[10];
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;
	for (int j = 0; j != 10; ++j)
		cout << ia[j] << ' ';
	cout << endl;
	return 0;
}