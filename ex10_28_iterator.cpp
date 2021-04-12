// created by pi on 11/12/20
// brief: three inserter

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> lst1, lst2, lst3;

	copy(nums.begin(), nums.end(), inserter(lst1, lst1.begin()));
	copy(nums.begin(), nums.end(), front_inserter(lst2));
	copy(nums.begin(), nums.end(), back_inserter(lst3));

	for (auto i = lst1.begin(); i != lst1.end(); ++i)
		cout << *i << ' ';
	cout << endl;
	for (auto i = lst2.begin(); i != lst2.end(); ++i)
		cout << *i << ' ';
	cout << endl;
	for (auto i = lst3.begin(); i != lst3.end(); ++i)
		cout << *i << ' ';
	cout << endl;
	return 0;
}