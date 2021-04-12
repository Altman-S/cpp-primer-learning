// & 具体的类
// Created by Pi on 2021/4/11.
//

#ifndef FIND_ANDQUERY_H
#define FIND_ANDQUERY_H

#include <memory>
using std::shared_ptr;

#include "binaryquery.h"


class QueryResult;
class TextQuery;

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    // & 构造函数
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { }
    // 具体的类，AndQuery定义了其他的纯虚函数
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


#endif //FIND_ANDQUERY_H
