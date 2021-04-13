// Created by Pi on 11/09/20
// Brief: read file, stored in vector<string>, using istringstream to read vector
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream in("/Users/altman/Downloads/C++ small/ex8_10.txt");
    if (!in) {
    	cerr << "无法打开输入文件！" << endl;
    	return -1;
    }

    string w;
    vector<string> words;
    while (in >> w) {
    	words.push_back(w);
    }

    in.close();
    
    // for (auto i = words.begin(); i != words.end(); ++i){
    // 	cout << *i << endl;
    // }
    
    
    for (auto &s : words) {
        istringstream iss(s);
        string word;
        while (iss >> word) {
            cout << word << endl;
        }
    }
    
    

    return 0;
}





