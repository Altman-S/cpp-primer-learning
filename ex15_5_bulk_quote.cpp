// created by Pi in 10/4/2021
// 定义自己的基类和派生类

#include <iostream>
#include <string>
using namespace std;


class Quote   // 基类
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


class Bulk_quote : public Quote  // 派生类 
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double sales_price, std::size_t qyt, double disc) : 
	           Quote(book, sales_price), min_qyt(qyt), discount(disc) { }
	double net_price(std::size_t) const override;
private:
	std::size_t min_qyt = 0;
	double discount = 0.0;
};
double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt > min_qyt)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;      // 代表protected里面的price
}


double print_total(ostream &os, const Bulk_quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn() << "    #sold: " << n << "    total due: " << ret << endl;
    return ret;  
}




int main() 
{
	Bulk_quote abc("ajsdasgdk123", 100, 5, 0.3);  // 超过5个打折
	print_total(cout, abc, 3);  // 3个不打折
	print_total(cout, abc, 10); // 10个就打折
	return 0;
}
