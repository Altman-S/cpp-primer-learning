#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> grade{0,20,40,60,70,80,90,100};
	vector<string> level;
	vector<int>::iterator it;
	vector<string>::iterator its;
	string lv;
	for (it = grade.begin() ;it != grade.end(); ++it) {
        lv = (*it >= 90) ? "high pass" : (*it >= 75) ? "pass" : (*it >= 60) ? "low pass" : "fail";
        level.push_back(lv);
	}
	for (it = grade.begin() ;it != grade.end(); ++it)
		cout << *it << ' ';
	cout << endl;
	for (its = level.begin() ;its != level.end(); ++its)
		cout << *its << ' ';
	cout << endl;
	return 0;
}