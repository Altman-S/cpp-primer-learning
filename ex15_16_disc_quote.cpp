// created by Pi in 10/4/2021
// 定义自己的Disc_quote和Bulk_quote，实现数量受限的折扣策略

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


class Disc_quote : public Quote   // 抽象基类，无法建立对象，只存储数量和折扣
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
	           Quote(book, price), quantity(qty), discount(disc) { }
	double net_price(std::size_t) const = 0;   // 纯虚函数
protected:
	std::size_t quantity;
	double discount;
};


class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
	           Disc_quote(book, price, qty, disc) { }
	// 新的折扣策略
	double net_price(std::size_t) const override;
};
double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt > quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;      // 代表protected里面的price
}


class Boss_quote : public Disc_quote
{
public:
	Boss_quote() = default;
	Boss_quote(const std::string &book, double price, std::size_t qty, double disc) :
	           Disc_quote(book, price, qty, disc) { }
	// 新的折扣策略
	double net_price(std::size_t) const override;
};
double Boss_quote::net_price(std::size_t cnt) const
{
    if (cnt > quantity)
		return cnt * price - 200;
	else
		return cnt * price;      // 代表protected里面的price
}


double print_total(ostream &os, const Quote &item, size_t n)  // Bulk_quote改成了Quote
{
    double ret = item.net_price(n);
    os << "ISBN:" << item.isbn() << "    #sold: " << n << "    total due: " << ret << endl;
    return ret;  
}




int main()
{
	Bulk_quote abc1("altmanniubi", 100, 5, 0.3);
	print_total(cout, abc1, 3);
	Bulk_quote def1("altmanniubi", 100, 5, 0.3);
	print_total(cout, def1, 10);
	cout << endl;
	Boss_quote abc2("altmanniubi", 100, 5, 0.3);
	print_total(cout, abc2, 3);
	Boss_quote def2("altmanniubi", 100, 5, 0.3);
	print_total(cout, def2, 10);
	return 0;
}

