#include "ex13_34_35_36.h"
#include <iostream>

// Message的swap函数
void swap(Message &lhs, Message &rhs)
{
	using std::swap;  // 在本例中严格来说并不需要，但这是一个好习惯
	// 将每个消息的指针从它（原来）所在Folder中删除
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	// 交换contents和Folder中的指针set
	swap(lhs.folders, rhs.folders);    // 使用swap(set&, set&)
	swap(lhs.contents, rhs.contents);  // swap(string&, string&)
    // 将每个Message的指针添加到它的（新）Folder中
    lhs.add_to_Folders(lhs);  //私有的函数用友元进行访问
    rhs.add_to_Folders(rhs);
}

// Message implementation

void Message::save(Folder &f)
{
	folders.insert(&f);       // 将给定Folder添加到我们的Folder列表中
	f.addMsg(this);           // 将本Message添加到f的Message集合中
}

void Message::remove(Folder &f)
{
	folders.erase(&f);        // 将给定Folder从我们的Folder列表中删除
	f.remMsg(this);           // 将本Message从f的Message集合中删除
}

// 将本Message添加到指向m的Folder中
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)  // 对于每个包含m的Folder
		f->addMsg(this);      // 向该Folder添加一个指向本Message的指针
}

// 从对应的Folder中删除本Message
void Message::remove_from_Folders()
{
	for (auto f : folders)    // 对folders中每个指针
		f->remMsg(this);      // 从该Folder中删除本Message
}

// 拷贝构造函数
Message::Message(const Message &m): contents(m.contents), folders(m.folders) 
{
	add_to_Folders(m);        // 将本消息添加到指向m的Folder中
}

// 析构函数
Message::~Message()
{
	remove_from_Folders();
}

// 拷贝赋值运算符
Message& Message::operator=(const Message &rhs)
{
	// 通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders();    // 更新已有Folder
	contents = rhs.contents;  // 从rhs拷贝消息内容
	folders = rhs.folders;    // 从rhs拷贝Folder指针
	add_to_Folders(rhs);         // 将本Message添加到那些Folder中
	return *this;
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
}

// Folder Implementation

void swap(Folder &lhs, Folder &rhs)
{
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();

	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

void Folder::add_to_Message(const Folder &f)
{
	for (auto m : f.msgs)
		m->addFldr(this);
}

void Folder::remove_from_Message()
{
	for (auto m : msgs)
		m->remFldr(this);
}

Folder::Folder(const Folder &f)
    : msgs(f.msgs)
{
    add_to_Message(f);
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug()
{
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}




int main()
{
	return 0;
}
