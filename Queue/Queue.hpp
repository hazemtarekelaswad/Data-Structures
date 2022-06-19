#pragma once

#include <iostream>
#include <initializer_list>
#include "../DoublyList/DoublyList.hpp"

template<typename T>
class Queue {

private:
	DoublyList<T> m_list;

public:
	Queue() {}

	Queue(const T& value) : m_list(value) {}

	Queue(const std::initializer_list<T>& list) : m_list(list) {}

	Queue(const Queue& queue) : m_list(queue.m_list) {}

	Queue(Queue&& queue) : m_list(std::move(queue.m_list)) {}

	Queue& operator=(Queue queue) {
		m_list = queue.m_list;
		return *this;
	}

	void swap(Queue& queue) {
		m_list.swap(queue.m_list);
	}

	friend std::ostream& operator<<(std::ostream& out, const Queue& queue) {
		out << queue.m_list;
		return out;
	}

	void push(const T& value) {
		m_list.push_back(value);
	}

	void pop() {
		m_list.pop_front();
	}

	T front() {
		return m_list[0];
	}
	
	T back() {
		return m_list[m_list.get_length() - 1];
	}

	size_t size() const {
		return m_list.get_length();
	}

	bool is_empty() const {
		return m_list.is_empty();
	}
};