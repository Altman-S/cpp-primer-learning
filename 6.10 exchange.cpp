#include <iostream>
using namespace std;

void exchange(int &a, int &b) {
    int t;
    t = a;
    a = b;
    b = t;
}

int main() {
    int i = 10, j = 20;
    cout << "i=" << i << ' ' << "j=" << j << endl;
    exchange(i,j);
    cout << "i=" << i << ' ' << "j=" << j << endl;
    return 0;
}