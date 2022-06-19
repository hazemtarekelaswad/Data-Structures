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
		m_size = list.size();
		m_vector = new T[m_size];

		size_t i = 0;
		for (const auto& element : list)
			m_vector[i++] = std::move(element);
	}

	Vector(const Vector& vec) {
		m_size = vec.m_size;
		m_vector = new T[m_size];
		for (size_t i = 0; i < m_size; ++i)
			m_vector[i] = vec.m_vector[i];
	}

	Vector(Vector&& vec) {
		m_vector = vec.m_vector;
		m_size = vec.m_size;
		vec.m_vector = nullptr;
		vec.m_size = 0;
	}

	Vector& operator=(const Vector& vec) {
		m_size = vec.m_size;
		m_vector = new T[m_size];
		for (size_t i = 0; i < m_size; ++i)
			m_vector[i] = vec.m_vector[i];
		return *this;
	}

	Vector& operator=(Vector&& vec) {

		delete[] m_vector;

		m_vector = vec.m_vector;
		m_size = vec.m_size;
		vec.m_vector = nullptr;
		vec.m_size = 0;

		return *this;
	}

	Vector& operator[](size_t index) {
		return m_vector[index];
	}

	size_t Size() const {
		return m_size;
	}

	Vector& At(size_t index) const {
		return m_vector[index];
	}

	T& Front() const {
		return m_vector[0];
	}

	T& Back() const {
		return m_vector[m_size - 1];
	}
	
	void PushBack(const T& value) {
		T* tempVec = m_vector;
		m_vector = new T[m_size + 1];
		for (size_t i = 0; i < m_size; ++i)
			m_vector[i] = std::move(tempVec[i]);
		delete[] tempVec;
		m_vector[m_size] = value;

		++m_size;
	}

	void PushBack(T&& value) {
		T* tempVec = m_vector;
		m_vector = new T[m_size + 1];
		for (size_t i = 0; i < m_size; ++i)
			m_vector[i] = std::move(tempVec[i]);
		delete[] tempVec;
		m_vector[m_size] = std::move(value);

		++m_size;
	}

	void PopBack() {
		T* tempVec = m_vector;
		m_vector = new T[m_size - 1];
		for (size_t i = 0; i < m_size - 1; ++i)
			m_vector[i] = std::move(tempVec[i]);
		delete[] tempVec;

		--m_size;
	}

	void Insert(const T& element, size_t index) {
		T* tempVec = m_vector;
		m_vector = new T[m_size + 1];

		for (size_t i = 0; i < index; ++i)
			m_vector[i] = tempVec[i];
		m_vector[index] = element;

		size_t count = index;
		for (size_t i = index + 1; i <= m_size; ++i)
			m_vector[i] = tempVec[count++];
		delete[] tempVec;

		++m_size;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector& vec) {
		for (size_t i = 0; i < vec.m_size; ++i)
			out << vec.m_vector[i] << ' ';
		return out;
	}

	~Vector() {
		if(m_vector)
			delete[] m_vector;
	}

};
