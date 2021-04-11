// created by Pi in 10/4/2021
// D1类覆盖它继承而来的fcn函数

#include <iostream>
#include <string>

class Base
{
public:
	virtual int fcn();
};


class D1 : public Base
{
public:
	// 隐藏基类的虚函数fcn，这个fcn不是虚函数
	// D1继承了Base::fcn()的定义，实际上fcn()这个虚函数载D1中是隐藏的
	int fcn(int);          // 形参列表与Base中的fcn不一致
	virtual void f2();     // 是一个新的虚函数，在Base中不存在
};


class D2 : public D1
{
public:
	int fcn(int);     // 是一个非虚函数，隐藏了D1::fcn(int)
	int fcn();        // 覆盖了Base的虚函数fcn()
	void f2();        // 覆盖了D1的虚函数f2()
};

