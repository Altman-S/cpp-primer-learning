// WordQuery用于查找一个给定的string，它是在给定的TextQuery对象上执行查询的唯一操作
// Created by Pi on 2021/4/11.
// 和Query_base一样，WordQuery没有public成员。Query必须作为WordQuery友元，Query才能访问它的构造函数

#ifndef FIND_WORDQUERY_H
#define FIND_WORDQUERY_H

#include <string>
using std::string;

#include "query_base.h"


class WordQuery : public Query_base
{
    friend class Query;  // Query使用WordQuery构造函数
    WordQuery(const string &s) : query_word(s) { }
    // 具体的类，WordQuery将定义所继承来的纯虚函数
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    string rep() const { return query_word; }
    string query_word;   // 需要查找的单词
};

#endif //FIND_WORDQUERY_H
