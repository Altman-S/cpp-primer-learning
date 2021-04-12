// ~ 具体的类
// Created by Pi on 2021/4/11.
// 运算符动态分配一个NotQuery对象

#ifndef FIND_NOQUERY_H
#define FIND_NOQUERY_H

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include "query_base.h"
#include "query.h"


class QueryResult;
class TextQuery;

class NotQuery : public Query_base
{
    friend Query operator~(const Query&);
    // ~ 构造函数
    NotQuery(const Query &q) : query(q) { }
    // 具体的类，NotQuery将定义所继承来的纯虚函数
    string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

#endif //FIND_NOQUERY_H
