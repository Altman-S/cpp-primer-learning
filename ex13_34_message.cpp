#include <iostream>

class Message {
    friend class Folder;
public:
	// folders被隐式初始化为空集合
	explicit Message(const std::string &str = ""): contents(str) { }
	// 拷贝控制成员，用来管理指向本Message的指针
	Message(const Message&);            // 拷贝构造函数
	Message& operator=(const Message&); // 拷贝赋值运算符
	~Message();                         // 析构函数
	// 从给定Folder集合中添加/删除本Message
	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents; // 实际文本信息
	std::set<Folder*> folders; // 包含本Message的Folder
	// 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	// 将本Message添加到指向参数的Folder中
	void add_to_Folders(const Message&);
	// 从folders中的每个Folder中删除本Message
	void remove_from_Folders();
};

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
// 拷贝构造函数
Message::Message(const Message &m): contents(m.contents), folders(m.folders) 
{
	add_to_Folders(m);        // 将本消息添加到指向m的Folder中
}

// 从对应的Folder中删除本Message
void Message::remove_from_Folders()
{
	for (auto f : folders)    // 对folders中每个指针
		f->remMsg(this);      // 从该Folder中删除本Message
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
	add_to_Folders();         // 将本Message添加到那些Folder中
	return this;
}

// Message的swap函数
void swap(Message &lhs, Message &rhs)
{
	using std::swap;  // 在本例中严格来说并不需要，但这是一个好习惯
	// 将每个消息的指针从它（原来）所在Folder中删除
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	// 交换contents和Folder中的指针set
	swap(lhs.folders, rhs.folders);    // 使用swap(set&, set&)
	swap(lhs.contents, rhs.contents);  // swap(string&, string&)
    // 将每个Message的指针添加到它的（新）Folder中
    for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}




class Folder {

};