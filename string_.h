#pragma once
#ifndef STRING_
#define STRING_
#include<memory>
#include<iostream>
using namespace std;
class string_
{
	friend std::ostream& operator<<(std::ostream& os, const string_& s);
public:
	string_() :begin(nullptr), end(nullptr), cap(nullptr) {}
	string_(const string_& s) :begin(nullptr), end(nullptr), cap(nullptr)
	{
		*this = s;
	}
	string_(const char* s)
	{
		int size = strlen(s);
		begin = alloc.allocate(size);
		end = begin + size;
		cap = begin + size;
		for (int i = 0; i < size; ++i)
		{
			alloc.construct(begin + i, s[i]);
		}
	}
	int size()const { return end - begin; }
	int capacity()const { return cap - begin; }
	char operator[](int i)const { return begin[i]; }
	char& operator[](int i) { return begin[i]; }
	string_& operator=(const string_& s)
	{
		int size = s.size();
		for (; end != begin; alloc.destroy(--end));
		begin = alloc.allocate(size);
		end = begin + size;
		cap = end;
		for (int i = 0; i < size; ++i)
		{
			alloc.construct(begin + i, s[i]);
		}
	}
	bool operator==(const string_& s)
	{
		int len = size();
		if (s.size() != len)return false;
		for (int i = 0; i < len; ++i)if (s[i] != begin[i])return false;
		return true;
	}

private:
	static std::allocator<char>alloc;
	char* begin;
	char* end;
	char* cap;
};
std::ostream& operator<<(std::ostream& os, string_& s)
{
	int len = s.size();
	for (int i = 0; i < len; ++i)os << s[i];
	return os;

}



#endif // STRING_
