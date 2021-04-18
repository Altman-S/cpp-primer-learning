#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string word;
	vector<string> text;
	while (cin >> word)
		text.push_back(word);
	for (auto &i : text)
		i = toupper(i);
	for (auto i : text)
		cout << i << endl;
	return 0;
}