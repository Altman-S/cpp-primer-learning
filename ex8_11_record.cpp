//  created by pi on 11/10/20.
//
//  brief  The program in this section defined its istringstream object inside the outer while loop.
//          What changes would you need to make if record were defined outside that loop?
//          Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    getline(cin, line);
    // 防止getline(cin, line)跳不出循环
    while (line != "") {
        PersonInfo info;
        record.clear();
        // record绑定line
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        getline(cin, line);
    }
    
    for (auto &p : people) {
        cout << p.name << " ";
        for (auto &s : p.phones)
            cout << s << " ";
        cout << endl;
    }
    
    return 0;
}
