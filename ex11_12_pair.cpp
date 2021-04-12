// created by pi on 11/14/20
// brief: string => pair => vector

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
	string word;
	int num;
	vector<pair<string, int>> vp;

	cout << "Please enter a string and a number: ";
	cin >> word >> num;
	pair<string, int> p (word, num);
	// pair<string, int> p = {word, num};
	// pair<string, int> p = mak_pair(word, num);
    vp.push_back(p);

    for (const auto &s : vp)
    	cout << s.first << ' ' << s.second << endl;
    return 0;
}