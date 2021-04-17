//i:text
//o:text[0] upper  using iterator
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string word;
	vector<string> text;
	vector<string>::iterator it;
	while (cin >> word) {
		text.push_back(word);
		if (cin.get() == '\n')
			break;
	}
	for (auto c : text)
		cout << c << endl;
	for (it = text.begin(); it != text.end(); ++it) { 
		if (it == text.begin())
			for (auto &s : *it)
				s = toupper(s);
		cout << *it << endl;
	}
	return 0;
}