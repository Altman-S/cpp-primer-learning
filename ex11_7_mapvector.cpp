// created by pi on 11/13/20
// brief: map, key:string  value:vector<string>

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<string, vector<string>> family = {{"James", {"angel", "altman", "QT"}},
                                          {"Thomas", {"big", "small", "ok"}}};
    string word, fam, name;
    cout << "Please add family name and your children names:" << endl;   
    cin >> fam;
    family[fam] = {};
    cin >> name;
    while (name != "end") {
        family[fam].push_back(name);
        cin >> name;
    }
    cout << endl;

    for (const auto &w : family) {
        cout << w.first << "   ";
        for (const auto &s : w.second) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}