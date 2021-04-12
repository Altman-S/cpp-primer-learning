// created by pi on 11/12/20
// brief: stable sort

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    vector<string> words = {"wo", "xiang", "zao", "ml", "he", "yaomengke"};
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    for (const string &s : words)
    	cout << s << ' ';
    cout << endl;
    return 0;
}