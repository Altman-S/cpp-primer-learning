//input:vector
//output:string upper
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main() {
	string word;
	string s;
	vector<string> text;
    while (cin >> word){
        cout << word << endl;
    	text.push_back(word);
    	if (cin.get() == '\n')
    		break;
    }
    for (auto &mem : text) {
    	for (auto &c : mem)
    		c = toupper(c);
    	cout << mem << ' ' << endl;
    }
    return 0;
}