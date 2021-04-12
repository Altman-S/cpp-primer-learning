// Query类对外提供接口，同时又隐藏了Query_base的继承体系，每个对象都含有一个指向Query_base的shared_ptr
// Created by Pi on 2021/4/11.
// eval用于求查询的结果，rep用于生成查询的string版本

#ifndef FIND_QUERY_H
#define FIND_QUERY_H

#include <ostream>
using std::ostream;

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include "query_base.h"
#include "queryresult.h"
#include "wordquery.h"


class TextQuery;

class Query
{
    // 这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string&);    // 构建一个新的wordquery
    // 接口函数：调用对应的Query_base操作
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    string rep() const { return q->rep(); }
private:
    Query(shared_ptr<Query_base> query) : q(query) { }
    shared_ptr<Query_base> q;
};

ostream &operator<<(ostream &os, const Query &query)
{
    // Query::rep通过它的Query_base指针对rep()进行了虚调用
    return os << query.rep();
}

inline Query::Query(const string &s) : q(new WordQuery(s)) { }


#endif //FIND_QUERY_H
