#pragma once

#include <iostream>

class String {
private:
	char* m_string;
public:
	String();
	String(const char* str);

	friend std::ostream& operator<<(std::ostream& out, const String& str);
	~String();


};

