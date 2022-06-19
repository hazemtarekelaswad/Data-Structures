#pragma once

#include <iostream>
template<typename T1, typename T2>
class Pair {
private:
	T1 m_first;
	T2 m_second;

public:
	Pair() {}

	Pair(const T1& firstElement, const T2& secElement)
		: m_first(firstElement), m_second(secElement) {}

	Pair(const Pair& pair) = default;

	void set_first(const T1& first) { m_first = first; }

	void set_second(const T2& second) { m_second = second; }

	T1 get_first() const { return m_first; }

	T2 get_second() const { return m_second; }

	friend std::ostream& operator<<(std::ostream& out, const Pair& pair) {
		out << m_first << ' ' << m_second << '\n';
		return out;
	}

};

template<typename T1, typename T2>
Pair<T1, T2> make_pair(const T1& first, const T2& second) {
	return Pair<T1, T2>(first, second);
}

