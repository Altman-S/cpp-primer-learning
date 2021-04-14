#include <iostream>
#include <string>
using namespace std;

string arr[3] = {"altman", "gosla", "bigbig"};
string atr[3] = {"foyer", "sky", "tiktok"};

string (*func(int i))[3] {
    if (i % 2 == 0)
    	return &arr;
    else
    	return &atr;
}

int main() {
    int num;
    int i = 2;
    string *p;
    cin >> num;
    p = *func(num);
    for (int i = 0; i != 3; ++i) {
        cout << *p++ << ' ';
    }
    cout << endl;
    return 0;
}

