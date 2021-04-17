#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string s_out = "";
	int s_size;
	int i = 0;
	cin >> s;
    s_size = s.size();
    while (i != s_size) {
        s_out += 'X';
        ++i;
    }
    cout << s_out <<endl;
    return 0;
}