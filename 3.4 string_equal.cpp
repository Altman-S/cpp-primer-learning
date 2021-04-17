#include <iostream>
#include <string>
using namespace std;

int main() {
	////bigger
	// string s1, s2;
	// cout << "Please enter two strings:" << endl;
	// cin >> s1 >> s2;
	// if (s1 == s2)
	// 	cout << s1 << " and " << s2 << " is equal." << endl;
	// else{
 //        if (s1 < s2)
 //    	    cout << "The bigger string is: " << s2 << endl;
 //        else
 //            cout << "The bigger string is: " << s1 << endl;
 //    }

    ////length
    string s1, s2;
    cout << "Please enter two strings:" << endl;
	cin >> s1 >> s2;
	if (s1.size() == s2.size())
		cout << "The length of " << s1 << " and " << s2 << " is equal." << endl;
	else{
        if (s1.size() < s2.size())
    	    cout << "The longer string is: " << s2 << endl;
        else
            cout << "The longer string is: " << s1 << endl;
    }

    return 0;

}