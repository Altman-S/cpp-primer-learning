//i:two strings
//o:equal/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	// string s1, s2;
	// cin >> s1 >> s2;
	// if (s1 == s2)
	// 	cout << s1 << " and " << s2 << " is equal." << endl;
	// else if (s1 < s2)
	// 	cout << s1 << " < " << s2 << endl;
	// else 
	// 	cout << s1 << " > " << s2 << endl;
 //    return 0;
    int signal;
    string s1, s2;
	cin >> s1 >> s2;
	signal = strcmp(s1, s2);
    if (signal == 0)
	 	cout << s1 << " and " << s2 << " is equal." << endl;
	else if (signal < 0 )
	 	cout << s1 << " < " << s2 << endl;
	else 
	 	cout << s1 << " > " << s2 << endl;
    return 0;
}