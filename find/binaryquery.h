// 抽象类，保存操作两个运算对象的查询类型所需的数据
// Created by Pi on 2021/4/11.
// rep()用于生成查询的string版本

#ifndef FIND_BINARYQUERY_H
#define FIND_BINARYQUERY_H

#include <string>
using std::string;

#include "query.h"
#include "query_base.h"


class QueryResult;
class TextQuery;

class BinaryQuery : public Query_base
{
protected:
    // 构造函数，希望自己的派生类去使用
    BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s) { }
    // 抽象类，BinaryQuery不定义eval
    string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
    Query lhs, rhs; // 左侧和右侧运算对象
    string opSym;   // 运算符的名字
};

#endif //FIND_BINARYQUERY_H
