#pragma once

template<typename T>
class DoublyNode {

	T m_value;
	DoublyNode* m_next;
	DoublyNode* m_prev;

public:
	DoublyNode() : m_next(nullptr), m_prev(nullptr) {}

	DoublyNode(const T& value) : m_value(value), m_next(nullptr), m_prev(nullptr) {}

	void set_value(const T& value) { m_value = value; }

	void set_next_node(DoublyNode* next) { m_next = next; }

	void set_previous_node(DoublyNode* prev) { m_prev = prev; }

	T get_value() const { return m_value; }

	DoublyNode* get_next_node() const { return m_next; }

	DoublyNode* get_previous_node() const { return m_prev; }
};
