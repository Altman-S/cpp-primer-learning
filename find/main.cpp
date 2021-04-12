//
// created by Pi on 2021/4/12
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"
#include "notquery.h"

int main()
{
    std::ifstream file("test.txt");

    TextQuery tQuery(file);

    Query q = Query("fieryzzz")  | Query("wind");

    std::cout << q.eval(tQuery);

    return 0;
}



