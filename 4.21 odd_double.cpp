#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> nums{0,1,2,3,4,5,6,7,8,9};
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end(); ++it) {
		*it = ((*it % 2) == 1) ? *it * 2 : *it;
	}
	for (it = nums.begin(); it != nums.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
    return 0;
}