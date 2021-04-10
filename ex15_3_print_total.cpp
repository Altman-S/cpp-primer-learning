// created by Pi in 10/4/2021
// 定义自己Quote类和print_total函数

#include <iostream>
#include <string>
using namespace std;

class Quote 
{
public:
	Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    // 返回指定数量的销售额
    // 派生类负责改写并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;  // 对析构函数进行动态绑定
private:
	std::string bookNo;          // 书籍的isbn编号
protected:
	double price = 0.0;          // 代表普通状态下不打折的价格
};


double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;  
}

int main()
{
    Quote abc("ajgdjha123", 100);
    print_total(cout, abc, 2);
    return 0;
}