// 读取给定文件并构建一个查找图
// Created by Pi on 2021/4/12.
//

#ifndef FIND_TEXTQUERY_H
#define FIND_TEXTQUERY_H

#include <fstream>
using std::ifstream;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;

#include "StrBlob.h"


class QueryResult;

class TextQuery {
public:
    typedef StrBlob::size_type line_no;

    TextQuery(ifstream &fin);

    QueryResult query(const string &) const;

private:
    //! data members
    StrBlob file;

    map<string, shared_ptr<set<line_no>>> wordMap;
};


#endif //FIND_TEXTQUERY_H
