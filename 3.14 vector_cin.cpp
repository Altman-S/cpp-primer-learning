#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string word;
	vector<string> text;
	while (cin >> word) {
		text.push_back(word);
		if (cin.get() == '\n')
			break;
	}
	for (auto i : text)
		cout << i << ' ';
	cout << endl;
	return 0;
}