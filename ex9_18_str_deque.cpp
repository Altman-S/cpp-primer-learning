// created by pi on 11/10/20
// brief: input:string  output:deque<string>

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	string s;
	deque<string> dq;
	cout << "Please enter several strings(enter 'end' to quiz)" << endl;
	cin >> s;
	while (s != "end") {
		dq.push_back(s);
		cin >> s;
	}
    
    cout << endl;

	for (auto i = dq.begin(); i != dq.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}