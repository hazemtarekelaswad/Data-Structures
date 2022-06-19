#pragma once

template<typename T>
class Node {
	T m_value;
	Node* m_next;

public:
	Node() : m_next(nullptr) {}

	Node(const T& value) : m_value(value), m_next(nullptr) {}

	void SetValue(const T& value) { 
		m_value = value; 
	}

	void SetNextNode(Node* next) { 
		m_next = next; 
	}

	T GetValue() const { 
		return m_value; 
	}

	Node* GetNextNode() const { 
		return m_next; 
	}
};
