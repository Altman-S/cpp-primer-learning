//input:vector
//output:0+n-1 1+n-2 2+n-3 ...  using size()
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int num_add;
	int num_two;
	int cnt;
	vector<int> nums;
	while (cin >> num_add) {
		nums.push_back(num_add);
		if (cin.get() == '\n')
			break;
	}
	cnt = nums.size();
    for (int i =0; i != (cnt/2); ++i) {
    	num_two = nums[i] + nums[cnt-1-i];
    	cout << num_two << endl;
    }
    if ((cnt%2) != 0) {
        num_two = nums[cnt/2];
        cout << num_two << endl;  
    }
    return 0;
}