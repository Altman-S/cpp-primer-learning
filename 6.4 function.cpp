#include <iostream>
using namespace std;

int fuc(int val) {
    if (val == 1)
        return 1;
    else
        return val*fuc(val-1);
}

int main() {
	int num;
    cin >> num;
    cout << fuc(num) << endl;
    return 0;
}