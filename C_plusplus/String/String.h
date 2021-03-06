#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	typedef char* iterator;
public:
	String(const char* str="");
	String(size_t n, char ch);
	String(char* begin, char* end);
	String(const String& s);
	String& operator=(String s);
	~String();

	//capacity
	size_t size()const;
	size_t capacity()const;
	bool empty()const;
	void resize(size_t newsize, char ch);
	void reserve(size_t newcapacity);

	//access
	char& operator[](size_t index);
	const char& operator[](size_t index)const;

	//modify
	void push_back(char ch);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator<(const String& s);
	bool operator<=(const String& s);

	friend ostream& operator<<(ostream& _cout, const String& s);
	friend istream& operator>>(istream& _cout, String& s);


	//�������
	size_t find(char ch, size_t pos);
	size_t rfind(char ch, size_t npos);
	String substr(size_t pos, size_t n);
	const char* c_str()const;

	//iterator
	iterator begin();
	iterator end();
private:
	size_t _size;
	size_t _capacity;
	char* _str;
	static size_t npos;
};

void TestString1();
void TestString2();
void TestString3();
//_STRING_H_