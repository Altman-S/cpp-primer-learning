// created by pi on 11/10/20
// brief: classify numbers in the list<int>, odd to deque1, even to deque2

#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main() {
	list<int> num_list = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
	deque<int> odd_list, even_list;
	int a;
	for (auto i = num_list.begin(); i != num_list.end(); ++i) {
        a = *i;
        if ((a % 2) == 0) 
        	even_list.push_back(a);
        else
        	odd_list.push_back(a);
	}

	cout << "The odd number is:" << endl;
	for (auto j = odd_list.begin(); j != odd_list.end(); ++j) {
		cout << *j << ' ';
	}
	cout << endl;
	cout << "The even number is:" << endl;
	for (auto k = even_list.begin(); k != even_list.end(); ++k) {
		cout << *k << ' ';
	}
	cout << endl;

	return 0;
}