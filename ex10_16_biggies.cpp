// created by pi on 11/12/20
// brief: bigger than 5

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// plus 's'
string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr >1) ? word + ending : word;
}

// 字母排序
void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    // 长度排序
    stable_sort(words.begin(), words.end(), 
    	        [](const string &a, const string &b) { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), 
    	        [sz](const string &a) { return a.size() > sz; });
    // 长度大于5的word数量
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length "
         << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s) { cout << s << ' '; });
    cout << endl; 
}

int main() {
    vector<string> words = {"woyapcao", "maoling", "he", "yaomengke", "zhen", "shuang"};
    biggies(words, 5);
    return 0;
}