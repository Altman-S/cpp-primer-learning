// created by pi on 11/11/20
// replace oldVal in s with newval
// using replace

#include <iostream>
#include <string>

using namespace std;


void replace_with(string &s, string const& oldVal, string const& newVal) {
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
        if (oldVal == string(cur, cur + oldVal.size())) {
            s.replace(cur, cur + oldVal.size(), newVal.begin(), newVal.end());
            cur += newVal.size();
        }
        else  
            ++cur;
}

int main()
{
    string s = "To drive straight thru is a foolish, tho courageous act.";
    cout << s << endl;
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    cout << s << endl;

    return 0;
}