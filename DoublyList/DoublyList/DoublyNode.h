#pragma once

template<typename T>
class DoublyNode {

	T m_value;
	DoublyNode* m_next;
	DoublyNode* m_prev;

public:
	DoublyNode() : m_next(nullptr), m_prev(nullptr) {}

	DoublyNode(const T& value) : m_value(value), m_next(nullptr), m_prev(nullptr) {}

	void SetValue(const T& value) {
		m_value = value;
	}

	void SetNextNode(DoublyNode* next) {
		m_next = next;
	}

	void SetPrevNode(DoublyNode* prev) {
		m_prev = prev;
	}

	T GetValue() const {
		return m_value;
	}

	DoublyNode* GetNextNode() const {
		return m_next;
	}

	DoublyNode* GetPrevNode() const {
		return m_prev;
	}
};
