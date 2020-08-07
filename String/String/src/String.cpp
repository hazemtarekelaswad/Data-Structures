#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

String::String() : m_str(nullptr) {
	m_str = new char[1];
	m_str[0] = '\0';
}

String::String(const char* str) {
	int length = strlen(str) + 1;
	m_str = new char[length];
	strcpy_s(m_str, length, str);
}

String::String(const String& str) {
	int length = strlen(str.m_str) + 1;
	m_str = new char[length];
	strcpy_s(m_str, length, str.m_str);
}

String& String::operator=(const String& str) {
	if(m_str)
		delete[] m_str;

	int length = strlen(str.m_str) + 1;
	m_str = new char[length];
	strcpy_s(m_str, length, str.m_str);

	return *this;
}

char& String::operator[](int index) {
	return m_str[index];
}

String operator+(const String& str1, const String& str2) {
	int length = strlen(str1.m_str) + strlen(str2.m_str) + 1;
	char* tempStr = new char[length];
	strcpy_s(tempStr, length, str1.m_str);
	strcat_s(tempStr, length, str2.m_str);
	String resStr(tempStr);
	delete[] tempStr;
	return resStr;
}

std::ostream& operator<<(std::ostream& out, const String& str) {
	out << str.m_str;
	return out;
}

std::istream& operator>>(std::istream& in, String& str) {
	if (str.m_str)
		delete[] str.m_str;
	char tempStr[300];
	in.getline(tempStr, size(tempStr));
	int length = strlen(tempStr) + 1;
	str.m_str = new char[length];
	strcpy_s(str.m_str, length, tempStr);
	return in;
}

String::~String() {
	if (m_str) {
		delete[] m_str;
		cout << "Destructed!\n";
	}
}

