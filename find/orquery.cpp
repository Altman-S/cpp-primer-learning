// Orquery的eval函数
// Created by Pi on 2021/4/12.
//

#include <memory>

#include "orquery.h"


QueryResult OrQuery::eval(const TextQuery &text) const
{
    QueryResult right = rhs.eval(text), left= lhs.eval(text);

    // 将左侧运算对象的行号拷贝到结果set中
    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());

    // 插入右侧对象所得到的行号
    ret_lines->insert(right.begin(), right.end());

    // 返回一个新的QueryResult，它表示lhs和rhs的并集
    return QueryResult(rep(), ret_lines, left.get_file());
}