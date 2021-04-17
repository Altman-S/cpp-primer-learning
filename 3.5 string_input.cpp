#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	string line = "";
	cout << "Please enter words:" << endl;
	while (cin >> word){
        line = line + word + ' ';
        if (cin.get() == '\n')
        	break;
    }
    cout << line << endl;
	return 0;
}