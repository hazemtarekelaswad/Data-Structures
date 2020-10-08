#pragma once

#include <iostream>
template<typename T1, typename T2>
class Pair {
private:
	T1 m_first;
	T2 m_second;

public:
	Pair(const T1& firstElement, const T2& secElement)
		: m_first(firstElement), m_second(secElement) {}

	void SetFirst(const T1& first) { m_first = first; }

	void SetSecond(const T2& second) { m_second = second; }

	T1 GetFirst() const { return m_first; }

	T2 GetSecond() const { return m_second; }

	friend std::ostream& operator<<(std::ostream& out, const Pair& pair) {
		out << m_first << ' ' << m_second << '\n';
		return out;
	}

};

template<typename T1, typename T2>
Pair<T1, T2> MakePair(const T1& first, const T2& second) {
	return Pair<T1, T2>(first, second);
}

