#include <iostream>
using namespace std;

int num_add() {
	static int num = 0;
	return num++;
}

int main() {
	int num_i;
	cin >> num_i;
	for (int i = 0; i != num_i; ++i)
		cout << num_add() << endl;
	return 0;
}