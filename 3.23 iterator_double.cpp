//i:int
//o:int*2 uisng iterator
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	vector<int> nums;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		*it = *it * 2;
		cout << *it << endl;
	}
	return 0;
}