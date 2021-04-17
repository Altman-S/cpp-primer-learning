//i:int
//o:int using iterator
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int num;
	vector<int> nums;
	vector<int>::iterator it;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	for (it = nums.begin(); it != nums.end(); ++it)
		cout << *it <<endl;
	return 0;
}