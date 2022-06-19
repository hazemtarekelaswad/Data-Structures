#pragma once

#include <iostream>
#include <initializer_list>
#include "SinglyList.h"

template<typename T>
class Stack {
private:
	SinglyList<T> m_list;

public:
	Stack() {}

	Stack(const T& value) : m_list(value) {}

	Stack(const std::initializer_list<T>& list) : m_list(list) {}

	Stack(const Stack& stack) : m_list(stack.m_list) {}

	Stack(Stack&& stack) : m_list(std::move(stack.m_list)) {}

	Stack& operator=(Stack stack) {
		m_list = stack.m_list;
		return *this;
	}

	void Swap(Stack& stack) {
		m_list.Swap(stack.m_list);
	}

	friend std::ostream& operator<<(std::ostream& out, const Stack& stack) {
		out << stack.m_list;
		return out;
	}

	void Push(const T& value) {
		m_list.PushBack(value);
	}

	void Pop() {
		m_list.PopBack();
	}

	T Top() {
		return m_list[m_list.GetLength() - 1];
	}

	size_t Size() const {
		return m_list.GetLength();
	}

	bool IsEmpty() const {
		return m_list.IsEmpty();
	}
};