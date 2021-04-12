// 抽象基类，我们不希望用户直接使用Query_base
// Created by Pi on 2021/4/11.
//

#ifndef FIND_QUERY_BASE_H
#define FIND_QUERY_BASE_H

#include <string>
using std::string;

#include "textquery.h"
#include "QueryResult.h"

class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;  // 用于eval函数
    virtual ~Query_base() = default;
private:
    // eval返回与当前匹配的QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0; // 纯虚函数
    // rep表示查询的一个string
    virtual string rep() const = 0;
};

#endif //FIND_QUERY_BASE_H
