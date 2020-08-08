#pragma once
#include <iostream>
#include <initializer_list>

template<typename T>
class Vector {
private:
	T* m_vector;
	size_t m_size;

public:
	Vector() : m_vector(nullptr), m_size(0){}

	Vector(std::initializer_list<T> list) {

	}

	friend std::ostream& operator<<(std::ostream& out, const Vector& vec) {
		for (size_t i = 0; i < vec.m_size; ++i)
			out << vec.m_vector[i];
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Vector& vec) {
		for (size_t i = 0; i < m_size; ++i)
			in >> vec.m_vector[i];
		return in;
	}
	
	void push_back(const T& value) {
		T* tempVec = m_vector;
		m_vector = new T[m_size + 1];
		for (size_t i = 0; i < m_size; ++i)
			m_vector[i] = tempVec[i];
		delete[] tempVec;
		m_vector[m_size] = value;

		++m_size;
	}

	void pop_back() {
		T* tempVec = m_vector;
		m_vector = new T[m_size - 1];
		for (size_t i = 0; i < m_size - 1; ++i)
			m_vector[i] = tempVec[i];
		delete[] tempVec;

		--m_size;
	}

	~Vector() {
		if(m_vector)
			delete[] m_vector;
	}

};