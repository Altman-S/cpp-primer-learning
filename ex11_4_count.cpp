// created by pi on 11/13/20
// brief: count how many times different words occur

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "An", "A", "the", "but", "and", "an", "a", ","};
    string word;
    cout << "Please enter some words.(enter 'end' to quit)" << endl;

    cin >> word;
    // 泛型算法将字符串转化为小写
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (word != "end") {
        if (exclude.find(word) == exclude.end())
        	++word_count[word];
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    for (auto &w : word_count) {
    	cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time"); 
    	cout << endl;
    }
    return 0;
}