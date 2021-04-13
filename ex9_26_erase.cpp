// created by pi on 11/10/20
// brief: erase odd from list, erase even from vector

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	list<int> nums_l(begin(ia), end(ia));
	vector<int> nums_v(begin(ia), end(ia));
	auto list_it = nums_l.begin();
	auto vector_it = nums_v.begin();

	while (list_it != nums_l.end()) {
        if (*list_it % 2)
            list_it = nums_l.erase(list_it);
        else
        	++list_it;
	}
    while (vector_it != nums_v.end()) {
        if (*vector_it % 2)
        	++vector_it;
        else
        	vector_it = nums_v.erase(vector_it);
	}

	cout << "The numbers in list are: " << endl;
	for (auto i = nums_l.begin(); i != nums_l.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
    cout << "The numbers in vector are: " << endl;
	for (auto j = nums_v.begin(); j != nums_v.end(); ++j) {
		cout << *j << ' ';
	}
	cout << endl;

	return 0;
}