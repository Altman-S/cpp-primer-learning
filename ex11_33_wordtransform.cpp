// created by pi on 11/14/20
// brief: word transform

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

// 将字符转换文件转换成map形式
map<string, string> buildMap(ifstream &map_file) {
    map<string, string> trans_map;   // 保存转换规则
    string key, value;    // 转换前的单词， 替换后的内容
    while (map_file >> key && getline(map_file, value))
    	if (value.size() > 1)
    		trans_map[key] = value.substr(1);
    	else
    		throw runtime_error("no rule for " + key);
    return trans_map;
}

// input:转换前的字符 转换规则   output:转换后的字符
const string &transform(const string &s, const map<string, string> &m) {
	// 实际的转换工作，此部分是程序的核心
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
    else
    	return s;
}

// input:转换前字符文件 转换规则文件  output:转换后的字符文件
void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);    // 保存转换规则
    string text;                            // 保存输入中的每一行
    while (getline(input, text)) {          // 读取一段输入
        istringstream stream(text);         // 读取每个单词
        string word;
        bool firstword = true;              // 控制是否打印空格
        while (stream >> word) {
        	if (firstword)
        		firstword = false;
        	else
        		cout << " ";                // 在单词间打印一个空格
        	cout << transform(word, trans_map);
        }
        cout << endl;                       // 完成一行的转换
    }
}

int main() {
    ifstream zhuanhuan("/Users/altman/Downloads/C++ small/ex11_33_zhunhuan.txt");
    ifstream zifu("/Users/altman/Downloads/C++ small/ex11_33_zifu.txt");
    word_transform(zhuanhuan, zifu);
    return 0;
}