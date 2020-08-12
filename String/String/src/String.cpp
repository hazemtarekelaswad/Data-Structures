#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;

String::String() {
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

String& String::operator+=(const String& str) {
	int length = strlen(m_str) + strlen(str.m_str) + 1;
	char* tempStr = new char[length];
	strcpy_s(tempStr, length, m_str);
	strcat_s(tempStr, length, str.m_str);

	*this = String(tempStr);
	return *this;
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

int String::Size() const{
	return strlen(m_str);
}

void String::Upper() {
	for (int i = 0; i < strlen(m_str); ++i) {
		if (m_str[i] >= 'a' && m_str[i] <= 'z')
			m_str[i] -= 32;
	}
}

void String::Lower() {
	for (int i = 0; i < strlen(m_str); ++i) {
		if (m_str[i] >= 'A' && m_str[i] <= 'Z')
			m_str[i] += 32;
	}
}

void String::Capitalize() {
	if (m_str[0] >= 'a' && m_str[0] <= 'z')
		m_str[0] -= 32;

	if (strlen(m_str) == 1)
		return;

	for (int i = 1; i < strlen(m_str); ++i) {
		if (m_str[i] >= 'A' && m_str[i] <= 'Z')
			m_str[i] += 32;
	}

}

void String::Swap(String& str) {
	String tempStr(*this);
	*this = str;
	str = tempStr;
}

bool String::Empty() const {
	return this->Size() == 1;	// if it contains nothing but '\0', returns true
}

void String::Clear() {
	if (this->Empty())
		return;
	delete[] m_str;
	m_str = new char[1];
	m_str[0] = '\0';

}

String::~String() {
	if (m_str)
		delete[] m_str;
}

