
#pragma once

#include <iostream>
#include <algorithm>
#include <string>

template<typename T, long long n>
class Array {
private:
	T m_array[n];

public:
	Array() {
		for (long long i = 0; i < n; ++i)
			m_array[i] = 0;
	}

	Array(std::initializer_list<T> li) {		// size equality assertion needed
		long long count = 0;
		for (auto element : li)
			m_array[count++] = element;
	}

	const long long size() {
		return n;
	}

	bool empty() const {
		return !n;
	}

	void fill(T value) {
		for (long long i = 0; i < n; ++i)
			m_array[i] = value;
	}

	void swap(Array& arr) {		// size equality assertion needed
		for (long long i = 0; i < n; ++i)
			swap(arr.m_array[i], this->m_array[i]);
	}

	T& operator[](long long index) {	// index range assetion needed
		return m_array[index];
	}

	friend std::istream& operator>>(std::istream& in, Array& arr) {
		for (long long i = 0; i < n; ++i)
			in >> arr.m_array[i];
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Array& arr) {
		for (long long i = 0; i < n; ++i)
			out << arr.m_array[i] << ' ';
		out << '\n';
		return out;
	}

	friend bool operator==(const Array& arr1, const Array& arr2) { // size equality assertion needed
		for (long long i = 0; i < arr1.size(); ++i)
			if (arr1.m_array[i] != arr2.m_array[i])
				return false;
		return true;
	}

	friend bool operator!=(const Array& arr1, const Array& arr2) { // size equality assertion needed
		for (long long i = 0; i < arr1.size(); ++i)
			if (arr1.m_array[i] == arr2.m_array[i])
				return false;
		return true;
	}

	void reverse() {
		for (long long i = 0; i < n / 2; ++i) {
			if (m_array[i] != m_array[n - 1 - i])
				swap(m_array[i], m_array[n - 1 - i]);
		}
	}

	T max() const {
		if (n == 1)
			return m_array[0];

		T max = m_array[0];
		for (int i = 1; i < n; ++i) {
			if (m_array[i] > max)
				max = m_array[i];
		}
		return max;
	}

	T min() const {
		if (n == 1)
			return m_array[0];

		int min = m_array[0];
		for (int i = 1; i < n; ++i) {
			if (m_array[i] < min)
				min = m_array[i];
		}
		return min;
	}
};

