// created by pi on 11/11/20
// brief: initiate a string through vector<char>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<char> s_char = {'A', 'l', 't', 'm', 'a', 'n'};
	string s(s_char.begin(), s_char.end());
	cout << s << endl;
	return 0;
}