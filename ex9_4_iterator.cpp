// created by pi on 11/10/20
// brief: find a number between a pair of iterators in the vector
// return bool

#include <iostream>
#include <vector>

using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val) {
    for (auto i = beg; i != end; ++i) {
    	if (*i == val)
    		return true;
    }
    return false;
}

int main() {
    vector<int> nums{2, 4, 6, 8, 10};
    vector<int>::iterator b = nums.begin();
    vector<int>::iterator e = nums.end();
    int inum;
    cout << "Please enter a number." << endl;
    cin >> inum;
    cout << search_vec(b, e, inum) << endl;
    return 0;
}
