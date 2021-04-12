//
// Created by Pi on 2021/4/12.
//

/***************************************************************************
 *  @file       queryresult.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     using class StrBlob
 ***************************************************************************/


#include "queryresult.h"


/**
 * @brief   输出结果
 * @note    class QueryResult's friend
 */

std::ostream&
operator <<(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.sp_lines->size() << " " << "times"   <<  "\n";

    // 打印出现单词的每一行
    for ( auto &index : *qr.sp_lines)
    {
        os << "\t(line " << index + 1 << ") ";
        const StrBlobPtr wp(qr.file, index);
        os << wp.deref() << "\n";
    }
    return os;
}