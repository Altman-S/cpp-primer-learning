//i:score
//o:level num     using iterator
#include <iostream>
#include <vector>
using namespace std;

int main() {
	unsigned num;
	vector<unsigned> nums;
	vector<unsigned> score(11, 0);
	vector<unsigned>::iterator s;
	auto s_b = score.begin();
	auto s_e = score.end();
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	for (auto it = nums.begin(); it != nums.end(); ++it) {
       if (*it <= 100) {
           s = s_b + (*it/10);
           *s = *s + 1;
       }
	}
	for (auto i : score)
		cout << i << ' ';
	cout << endl;
	return 0;
} 