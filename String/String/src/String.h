#pragma once

#include <iostream>
#include <cstring>

class String {
private:
	char* m_str;

public:
	String();
	String(const char* str);
	String(const String& str);
	String& operator=(const String& str);
	
	char& operator[](int index);
	friend String operator+(const String& str1, const String& str2);
	String& operator+=(const String& str);	// returns reference to string object to consider a statement like 
											/// String s; (s += "Oh") = "WOW";

	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);

	int Size() const;	//returns the the string length added to the null terminator. e.g. "Oh!" has size equal to 4

	void Upper();
	void Lower();
	void Capitalize();

	void Swap(String& str);
	bool Empty() const;
	void Clear();
	
	~String();
};

