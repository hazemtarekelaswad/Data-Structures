#pragma once
#include "Node.h"
#include <initializer_list>
#include <iostream>

template<typename T>
class SinglyList {
private:
	Node<T>* m_head;
	size_t length;

public:
	SinglyList() : m_head(nullptr), length(0) {}

	SinglyList(std::initializer_list<T> initList) {
		for (auto element = initList.begin(); element != initList.end(); ++element)
			PushBack(*element);
	}

	SinglyList(const SinglyList& sList) {
		
	}

	SinglyList(SinglyList&& sList) {
		
	}

	SinglyList& operator=(const SinglyList& sList) {

	}

	SinglyList& operator=(SinglyList&& sList) {

	}

	size_t GetLength() const { 
		return length; 
	}

	friend std::ostream& operator<<(std::ostream& out, const SinglyList& sList) {
		Node<T>* trav = sList.m_head;
		while (trav) {
			out << trav->GetValue() << ' ';
			trav = trav->GetNextNode();
		}
		return out;
	}

	void PushBack(const T& value) {
		Node<T>* newNode = new Node<T>(value);

		if (!m_head) {
			m_head = newNode;
			++length;
			return;
		}

		Node<T>* trav = m_head;
		while (trav->GetNextNode())
			trav = trav->GetNextNode();

		trav->SetNextNode(newNode);
		++length;
	}

	void PushFront(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->SetNextNode(m_head);
		m_head = newNode;
		++length;
	}

	void PopBack() {

	}

	void PopFront() {

	}

	bool IsEmpty() const {

	}

	void Clear() {

	}

	void Swap(const SinglyList& sList) {

	}

	~SinglyList() {

	}
};