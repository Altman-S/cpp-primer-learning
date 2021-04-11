// created by Pi in 11/4/2021
// 默认构造函数 拷贝构造函数 移动构造函数 拷贝赋值 移动赋值

#include <iostream>

using namespace std;

class Message {
public:
	Message() { std::cout << "normal construct: " << this << std::endl; }
	Message(const Message&) { std::cout << "copy construct: " << this << std::endl; };
	Message(Message&&) noexcept { std::cout << "move construct: " << this << std::endl; };
	~Message() { std::cout << "destruct: " << this << std::endl; };
	Message& operator=(const Message& m) {
		std::cout << "copy: " << this << " = " << &m << std::endl;
		return *this;
	}
	Message& operator=(Message&& m) noexcept
	{
		std::cout << "move: " << this << " = " << &m << std::endl;
		return *this;
	}
};


// main.cpp
Message getMes_a()
{
	Message a;
	return a;
}

Message getMes()
{
	return Message();
}

int main()
{
	cout << "======================test1======================" << endl;
	getMes_a();

	cout << endl << "======================test2======================" << endl;
	Message m1 = getMes_a();

	cout << endl << "======================test3======================" << endl;
	m1 = getMes_a();

	cout << endl << "======================test4======================" << endl;
	getMes();

	cout << endl << "======================test5======================" << endl;
	Message m2 = getMes();

	cout << endl << "======================test6======================" << endl;
	m2 = getMes();

	cout << endl << "=======================end=======================" << endl;
	return 0;
}


