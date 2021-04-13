#include <iostream>
#include <string>
using namespace std;

class Sales_data {
friend std::istream& operator >> (std::istream&, Sales_data&);
friend std::ostream& operator << (std::ostream&, const Sales_data&);
friend bool operator < (const Sales_data&, const Sales_data&);
friend bool operator == (const Sales_data&, const Sales_data&);
public:  //构造函数的3种形式
    Sales_data() = default;
    Sales_data(const std::string &book) : bookNo(book) { }
    Sales_data(std::istream &is) { is >> *this; }
public:
    Sales_data& operator += (const Sales_data&);
    std::string isbn() const { return bookNo; }
private:
    std::string bookNo;         //书籍编号
    unsigned units_sold = 0;    //销售量
    double sellingprice = 0.0;  //原始价格
    double saleprice = 0.0;     //实售价格
    double discount = 0.0;      //折扣
} ;

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{ return lhs.isbn() == rhs.isbn(); }

Sales_data operator + (const Sales_data&, const Sales_data&);

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.units_sold == rhs.units_sold && lhs.sellingprice == rhs.sellingprice &&
           lhs.saleprice == rhs.saleprice && lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);    //基于运算符==给出！=的定义
}

Sales_data& Sales_data::operator += (const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) 
        / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data ret(lhs);    //把lhs的内容拷贝到临时变量ret中，这种做法便于计算
    ret += rhs;             //把rhs的内容加入其中
    return ret;             //返回ret
}

std::istream& operator>>(std::istream& in, Sales_data& s) {
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
        s.discount =s.saleprice / s.sellingprice;
    else
        s = Sales_data();
    return in;
}

std::ostream& operator << (std::ostream& out, const Sales_data& s) {
    out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " " 
        << s.saleprice << " " << s.discount;
    return out;
}



