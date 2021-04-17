//i:nums
//o:begin+end begin+1+end-1  using iterator
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	int num_add;
	vector<int> nums;
	vector<int>::iterator it_b;
	vector<int>::iterator it_e;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
    auto beg = nums.begin();
    auto end = nums.end();
    auto mid = beg + (end - beg)/2;
    for (auto it = beg; it != mid; ++it) {
        it_b = it;
        it_e = end - (it_b - beg) - 1;
        num_add = *it_b + *it_e;
        cout << num_add << ' ';
    }
    if ((nums.size()%2) != 0)
    	cout << nums[nums.size()/2];
    cout << endl;
    return 0;
}