#pragma once

#include <iostream>
#include <cstring>

class String {
private:
	char* m_str;
public:

	String() {
		m_str = new char[1];
		m_str[0] = '\0';
	}

	String(const char* str) {
		int length = strlen(str) + 1;
		m_str = new char[length];
		strcpy_s(m_str, length, str);
	}

	String(const String& str) {
		int length = strlen(str.m_str) + 1;
		m_str = new char[length];
		strcpy_s(m_str, length, str.m_str);
	}

	String& operator=(const String& str) {
		if(m_str)
			delete[] m_str;

		int length = strlen(str.m_str) + 1;
		m_str = new char[length];
		strcpy_s(m_str, length, str.m_str);

		return *this;
	}

	char& operator[](int index) {
		return m_str[index];
	}


	friend String operator+(const String& str1, const String& str2) {
		int length = strlen(str1.m_str) + strlen(str2.m_str) + 1;
		char* tempStr = new char[length];
		strcpy_s(tempStr, length, str1.m_str);
		strcat_s(tempStr, length, str2.m_str);

		String resStr(tempStr);
		delete[] tempStr;
		return resStr;
	}

	String& operator+=(const String& str) {
		int length = strlen(m_str) + strlen(str.m_str) + 1;
		char* tempStr = new char[length];
		strcpy_s(tempStr, length, m_str);
		strcat_s(tempStr, length, str.m_str);

		*this = String(tempStr);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const String& str) {
		out << str.m_str;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, String& str) {
		if (str.m_str)
			delete[] str.m_str;
		char tempStr[300];
		in.getline(tempStr, std::size(tempStr));
		int length = strlen(tempStr) + 1;
		str.m_str = new char[length];
		strcpy_s(str.m_str, length, tempStr);
		return in;
	}

	int size() const{
		return strlen(m_str);
	}

	void upper() {
		for (int i = 0; i < strlen(m_str); ++i) {
			if (m_str[i] >= 'a' && m_str[i] <= 'z')
				m_str[i] -= 32;
		}
	}

	void lower() {
		for (int i = 0; i < strlen(m_str); ++i) {
			if (m_str[i] >= 'A' && m_str[i] <= 'Z')
				m_str[i] += 32;
		}
	}

	void capitalize() {
		if (m_str[0] >= 'a' && m_str[0] <= 'z')
			m_str[0] -= 32;

		if (strlen(m_str) == 1)
			return;

		for (int i = 1; i < strlen(m_str); ++i) {
			if (m_str[i] >= 'A' && m_str[i] <= 'Z')
				m_str[i] += 32;
		}

	}

	void swap(String& str) {
		String tempStr(*this);
		*this = str;
		str = tempStr;
	}

	bool empty() const {
		return this->size() == 1;	// if it contains nothing but '\0', returns true
	}

	void clear() {
		if (this->empty())
			return;
		delete[] m_str;
		m_str = new char[1];
		m_str[0] = '\0';

	}

	~String() {
		if (m_str)
			delete[] m_str;
	}
};
