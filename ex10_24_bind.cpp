// created by pi on 11/12/20
// brief: find int which is bigger than the length of a string in a vector 

#include <iostream>
#include <string>
#include <vector>
//#include <functional>

using namespace std;
using namespace std::placeholders;


int check_size(const vector<int> &num, string::size_type sz) {
	for (auto i = num.begin(); i != num.end(); ++i) {
		if (*i > sz)
			return *i;
	}
	return 0;
}

int main() {
	string s = "yaomengke";
	int s_len = s.size();
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	auto g = bind(check_size, _1, s_len);
	cout << g(nums) << endl;
	return 0;
}
