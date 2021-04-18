#include <iostream>
#include "Sales_item.h"
using namespace std;

int main(int argc, char const *argv[])
{
    //读取两个，输出一个
    //Sales_item book1, book2;
    //cout << "Enter 2 transactions:" << endl;
    //cin >> book1 >> book2;
    //cout << "ISBN           sold   price   revenue" << endl;
    //cout << book1 + book2 << endl;
    
    //读取一个，输出一个
    //while(cin >> book){
    //    cout << "ISBN          sold   price   revenue" << endl;
    //    cout << book << endl;
    //}

    //读取多个，输出一个
    Sales_item book,sumbook;
    cin >> sumbook;
    while (cin >> book) {
        sumbook += book;
    }
    cout << "ISBN           sold     price   revenue" << endl;
    cout << sumbook << endl;
    return 0;
}