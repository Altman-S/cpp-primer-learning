// created by pi on 11/11/20
// brief: find numbers in a string

#include <iostream>
#include <string>

using namespace std;

int main() {
	string numbers("0123456789");
	string target("ab2c3d7R4E6");

	string::size_type pos = 0;
	while ((pos = target.find_first_of(numbers, pos)) != string::npos) {
		cout << "found number at index: " << pos << " element is " << target[pos] << endl;
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = target.find_first_not_of(numbers, pos)) != string::npos) {
		cout << "found char at index: " << pos << " element is " << target[pos] << endl;
		++pos;
	}

	return 0;
}