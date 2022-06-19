#pragma once

template<typename T>
class Node {
	T m_value;
	Node* m_next;

public:
	Node() : m_next(nullptr) {}

	Node(const T& value) : m_value(value), m_next(nullptr) {}

	void set_value(const T& value) { 
		m_value = value; 
	}

	void set_next_node(Node* next) { 
		m_next = next; 
	}

	T get_value() const { 
		return m_value; 
	}

	Node* get_next_node() const { 
		return m_next; 
	}
};
