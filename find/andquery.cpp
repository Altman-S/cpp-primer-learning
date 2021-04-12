// AndQuery的eval函数
// Created by Pi on 2021/4/12.
// eval用于求查询的结果

#include <memory>
#include <algorithm>

#include "andquery.h"

QueryResult AndQuery::eval(const TextQuery &text) const
{
    // virtual calls through the Query operands to get result sets for the operands
    // 调用了binaryquery中的lhs和rhs
    QueryResult left = lhs.eval(text), right = rhs.eval(text);

    // set用来保存left和right的交集
    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();

    // 将两个范围的交集写到一个目标迭代器中
    // 使用标准库算法set_intersection来合并两个set
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}

