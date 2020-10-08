#pragma once

#include <iostream>

template<typename T1, typename T2>
class Pair {
private:
	T1 m_firstElement;
	T2 m_secElement;

public:
	Pair(const T1& firstElement, const T2& secElement) 
		: m_firstElement(firstElement), m_secElement(secElement) {}
};