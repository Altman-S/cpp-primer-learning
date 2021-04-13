// created by pi on 11/11/20
// brief: insert and append

#include <iostream>
#include <string>

using namespace std;

void add(string &s, string const &front, string const &back) {
    s.insert(s.begin(), front.begin(), front.end());
    s.append(back.begin(), back.end());
}

int main() {
    string name = "Altman";
    add(name, "Mr. ", " Jr.");
    cout << name << endl;
    return 0;
}