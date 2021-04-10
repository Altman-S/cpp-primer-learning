// created by Pi in 10/4/2021
// 解释每个print的原理

#include <iostream>
#include <string>

class base 
{
public:
	base() = default;
	base(string szNm) : basename(szNm) { }
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
	virtual ~base() = default;
private:
	string basename;
};


class derived : pubilc base
{
public:
	derived() = default;
	derived(string szName, int iVal) : base(szName), mem(iVal) { }   // 调用base的print
	void print() { print(base::ostream &os);  os << "--" << mem; }   // base::ostream是什么意思？？？
private:   
	int mem;
};


