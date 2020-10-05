#pragma once

#include <iostream>
#include <initializer_list>
#include "DoublyList.h"

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

	void Swap(Queue& queue) {
		m_list.Swap(queue.m_list);
	}

	friend std::ostream& operator<<(std::ostream& out, const Queue& queue) {
		out << queue.m_list;
		return out;
	}

	void Push(const T& value) {
		m_list.PushBack(value);
	}

	void Pop() {
		m_list.PopFront();
	}

	T Front() {
		return m_list[0];
	}
	
	T Back() {
		return m_list[m_list.GetLength() - 1];
	}

	size_t Size() const {
		return m_list.GetLength();
	}

	bool IsEmpty() const {
		return m_list.IsEmpty();
	}
};