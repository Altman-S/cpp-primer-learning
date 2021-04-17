#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;
	for (auto &i: word)
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
			cout << i;	
    cout << endl;
    return 0;
}