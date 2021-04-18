#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned height = 6;
	unsigned width = 6;
	string contents(height * width, 's');
	cout << contents << endl;
	return 0;
}