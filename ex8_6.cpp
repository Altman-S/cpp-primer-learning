//  ex8_06.cpp
//  Exercise 8.6
//
//  Created by pezy on 11/27/14.
//
//  @Brief  Rewrite the bookstore program from ¡ì7.1.1 (p.256) to read its transactions from a file. 
//          Pass the name of the file as an argument to main (¡ì6.2.5, p.218). 
//  @See    ex7_26.h (use the Sales_data)   Sales_data.h
//  @Run    give a parameter: "book.txt"
//  @Output 0-201-78345-X 7 790
//          0-211-12345-Y 3 180
//          0-233-35628-Z 1 30

#include <fstream>
#include <iostream>

#include "ex7_26.h"
using std::ifstream; using std::cout; using std::endl; using std::cerr;

int main(int argc, char **argv) 
{
    ifstream input("/Users/altman/Downloads/C++ small/book.txt");
    
    Sales_data total;
    if (read(input, total)) 
    {
        Sales_data trans;
        while (read(input, trans)) 
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else 
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        // 输出最后一个
        print(cout, total) << endl;
    } 
    else 
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}