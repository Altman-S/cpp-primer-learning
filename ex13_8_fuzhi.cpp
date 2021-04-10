#include <iostream>


class HasPtr {
public:
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);

private:
	std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &hp) {
	ps = new string(*hp.ps);
	i = hp.i;
}
HasPtr&HasPtr::operator=(const &HasPtr &rhs) {
	auto newps = new string(*rhs.ps);  //拷贝指针指向的对象
	delete ps; //销毁原string
	ps = newps; //指向新string
	i = rhs.i; //使用内置的int赋值
    return *this; //返回一个此对象的引用
}