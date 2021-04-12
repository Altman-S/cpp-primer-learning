// created by pi on 11/12/20
// brief: the length is greater than 5
// using partition

#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isGreater5(const string &word) {
	return word.size() >= 5;
}

int main() {
    vector<string> words = {"woyapcao", "maoling", "he", "yaomengke", "zhen", "shuang"};
    partition(words.begin(), words.end(), isGreater5);
    for (auto i = words.begin(); i != (words.begin() + words.size()/2); ++i)
    	cout << *i << ' ';
    cout << endl;
    return 0;
}
