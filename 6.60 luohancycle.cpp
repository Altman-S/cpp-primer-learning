#include <iostream>
using namespace std;

void move(int x, char src, char dest){
    cout << src << "--" << x << "-->" << dest << endl;
}

void luohan(int n, char src, char medium, char dest){
    if (n == 1) {
        move(n, src, dest);
    }
    else{
        luohan(n-1, src, dest, medium);
        move(n, src, dest);
        luohan(n-1, medium, src, dest);
    }
}


int main() {
    int num;
    char s='A';
    char m='B';
    char d='C';

    cout << "A-->C" << endl;
    cout << "输入罗汉塔的层数：";
    cin >> num;
    luohan(num, s, m, d);
    return 0;
}
