#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> num{0,1,2,3,4,5,6,7,8,9};
	for (auto it = num.begin(); it != num.end(); ++it)
		*it = (*it) * 2;
	for (auto it = num.begin(); it != num.end(); ++it){
		cout << *it << " ";
	}
}