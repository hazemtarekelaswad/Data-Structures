#pragma once
#include "DoublyNode.h"
#include <iostream>
#include <initializer_list>

template<typename T>
class DoublyList {
private:
	DoublyNode<T>* m_head;
	DoublyNode<T>* m_tail;
	size_t length;

public:
	DoublyList() : m_head(nullptr), m_tail(nullptr), length(0) {}

	DoublyList(const T& value) {

	}

	DoublyList(const std::initializer_list<T>& list) {

	}
	
	DoublyList(const DoublyList& list) {

	}
	
	DoublyList(DoublyList&& list) {

	}

	DoublyList& operator=(DoublyList& list) {

	}

	size_t GetLength() const {
		return length;
	}

	void PushBack(const T& value) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		newNode->SetPrevNode(m_tail);

		if(m_tail)
			m_tail->SetNextNode(newNode);

		m_tail = newNode;

		if (!m_head)
			m_head = newNode;
		++length;
	}

	void PushFront(const T& value) {

	}

	void PopBack() {

	}

	void PopFront() {

	}

	T operator[](int index) {

	}

	bool IsEmpty() const {

	}

	void Swap(DoublyList& list) {

	}

	friend std::ostream& operator<<(std::ostream& out, const DoublyList& list) {
		DoublyNode<T>* trav = list.m_head;
		while (trav) {
			out << trav->GetValue() << ' ';
			trav = trav->GetNextNode();
		}
		return out;
	}

	void PrintReversed() const {
		DoublyNode<T>* trav = m_tail;
		while (trav) {
			std::cout << trav->GetValue() << ' ';
			trav = trav->GetPrevNode();
		}
	}

	~DoublyList() {

	}

};