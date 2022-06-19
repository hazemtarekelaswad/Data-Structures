#pragma once

#include <iostream>
#include <initializer_list>
#include "../SinglyList/SinglyList.hpp"

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

	void swap(Stack& stack) {
		m_list.swap(stack.m_list);
	}

	friend std::ostream& operator<<(std::ostream& out, const Stack& stack) {
		out << stack.m_list;
		return out;
	}

	void push(const T& value) {
		m_list.push_back(value);
	}

	void pop() {
		m_list.pop_back();
	}

	T top() {
		return m_list[m_list.get_length() - 1];
	}

	size_t size() const {
		return m_list.get_length();
	}

	bool is_empty() const {
		return m_list.is_empty();
	}
};