//  ex8_7.cpp
//  Exercise 8.7
//
//  Created by pezy on 11/09/20.
//
//  @Brief  Rewrite the bookstore program from ¡ì7.1.1 (p.256) to read its transactions from a file. 
//          Pass the name of the file as an argument to main (¡ì6.2.5, p.218). 
//  @See    ex7_26.h (use the Sales_data)   Sales_data.h
//  @Run    give a parameter: input "book.txt"   output "book1.txt"
//  @Output 0-201-78345-X 7 790
//          0-211-12345-Y 3 180
//          0-233-35628-Z 1 30
//          out to book1.txt

#include <fstream>
#include <iostream>

#include "ex7_26.h"
using std::ifstream; using std::ofstream; using std::cout; using std::endl; using std::cerr;

int main(int argc, char **argv) 
{
    ifstream input("/Users/altman/Downloads/C++ small/book.txt");
    // 输出模式+app模式
    ofstream output("/Users/altman/Downloads/C++ small/book1.txt", ofstream::out | ofstream::app);
    
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
                print(output, total) << endl;
                total = trans;
            }
        }
        // 输出最后一个
        print(output, total) << endl;
    } 
    else 
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}