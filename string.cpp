#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

/*
浅拷贝: 值拷贝对象
深拷贝: 既拷贝对象模型的内容, 也拷贝资源, 每个对象都有自己的独立资源, 对象之间不共享资源
	优势: 不会发生多次释放的问题.
*/

class String
{
public:
	String(const char* str)
		:_data(new char[strlen(str) + 1])
	{
		strcpy(_data, str);
	}

	//深拷贝： 拷贝构造
	String(const String& str)
		:_data(new char[strlen(str._data) + 1])
	{
		strcpy(_data, str._data);
	}

	//深拷贝：赋值运算符重载
	String& operator=(const String& str)
	{
		if (this != &str)
		{
			//判断是否需要释放已有资源
			if (_data)
				delete[] _data;
			//开新的空间
			_data = new char[strlen(str._data) + 1];
			strcpy(_data, str._data);
		}
		return *this;
	}

	~String()
	{
		//释放资源
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
		}
	}
private:
	char* _data;
	/*int _size;
	int _capacity;*/
};

void test()
{
	String str1("123");
	String str2(str1); //拷贝构造
	String str3("456");
	str3 = str2;  //赋值运算符重载函数
}

int main()
{
	test();
	return 0;
}