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

	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator>>(std::istream& in, String& str);
	~String();
};

