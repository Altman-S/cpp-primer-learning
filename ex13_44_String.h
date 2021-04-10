#ifndef CP5_STRING_H__
#define CP5_STRING_H__

#include <memory>
#include <iostream>

class String
{
public:
    friend std::ostream& operator << (std::ostream &os, const String &str);
    friend std::istream& operator >> (std::istream &is, String &item);
    String(): String("") { }           // 默认构造函数
    String(const char *);              // 构造函数
    String(const String&);             // 拷贝构造函数
    String& operator=(const String&);  // 拷贝赋值运算符
    ~String();                         // 析构函数
    
    const char *c_str() const { return elements; }       // 返回头元素指针
    size_t size() const { return end - elements; }       // 显示字符串所占空间的大小
    size_t length() const { return end - elements - 1; } // 显示字符串的长度

private:
    // 分配足够的内存来保存给定范围内的元素，返回的两个指针分别是新空间的开始位置和拷贝的尾后位置
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    // 分配空间，设置初始位置elements和结束位置end
    void range_initializer(const char*, const char*);
    // destroy元素，释放内存空间
    void free();

private:
    char *elements; // 分配内存的首元素
    char *end;      // 分配内存的尾元素
    std::allocator<char> alloc; // 分配char的allocator对象
};

#endif
