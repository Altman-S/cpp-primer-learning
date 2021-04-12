// 返回结果
// Created by Pi on 2021/4/11.
// eval函数也定义在这个里面

#ifndef FIND_QUERYRESULT_H
#define FIND_QUERYRESULT_H

#include <iostream>
using std::ostream;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include <set>
using std::set;

#include <vector>
using std::vector;

#include "textquery.h"


class QueryResult
{
    friend ostream& operator<<(ostream&, const QueryResult&);

public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> l, StrBlob f) :
        sought(s), lines(l), file(f) { }

    set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    set<TextQuery::line_no>::iterator end() { return lines->end(); }
    const StrBlob& get_file() const{ return file; }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    StrBlob file;
};

std::ostream&
print(std::ostream&, const QueryResult &);


#endif //FIND_QUERYRESULT_H
