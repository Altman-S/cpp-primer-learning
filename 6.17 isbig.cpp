#include <iostream>
#include <string>
using namespace std;

bool is_big(const string &s) {
	bool flag = false;
	for (string::size_type i = 0; i != s.size(); ++i) {
        if ((s[i] >= 'A') && (s[i]) <= 'Z') {
        	flag = true;
        	break;
        }
	}
	return flag;
}

void to_small(string &s) {
    for (string::size_type j = 0; j != s.size(); ++j) {
    	if ((s[j] >= 'A') && (s[j]) <= 'Z') {
        	s[j] = tolower(s[j]);
        }
    }
}



int main() {
    string str;
    cin >> str;
    cout << is_big(str) << endl;
    to_small(str);
    cout << str << endl;
    return 0;
}