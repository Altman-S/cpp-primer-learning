#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a[]={0,1,2,3,4,5,6,7,8,9};
	vector<int> nums(begin(a), end(a));
	for (auto i : nums)
		cout << i << " ";
	return 0;
}