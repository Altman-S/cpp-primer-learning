// NotQuery的eval函数
// Created by Pi on 2021/4/12.
// 返回结果中不存在的文本行

#include "notquery.h"
#include <memory>


QueryResult NotQuery::eval(const TextQuery &text) const
{
    // 通过Query对象对eval进行虚调用
    QueryResult result = query.eval(text);
    // 开始时结果set为空
    std::shared_ptr<std::set<line_no>> ret_lines = std::make_shared<std::set<line_no>>();
    // 我们必须在运算对象出现的所有行之间进行迭代
    std::set<TextQuery::line_no>::iterator begin = result.begin(), end = result.end();

    StrBlob::size_type sz = result.get_file().size();

    // 对于输入文件的每一行，如果该行不在result中，则将其添加到ret_lines
    for(std::size_t n = 0; n != sz; ++n)
    {
        if(begin == end || *begin != n)
            ret_lines->insert(n);
        else if (begin != end)
            ++begin;
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}