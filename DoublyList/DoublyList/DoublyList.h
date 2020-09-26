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

	DoublyList(const T& value) : m_head(nullptr), m_tail(nullptr), length(0) {
		PushBack(value);
	}

	DoublyList(const std::initializer_list<T>& list) : m_head(nullptr), m_tail(nullptr), length(0) {
		for (auto value : list)
			PushBack(value);
	}
	
	DoublyList(const DoublyList& list) : m_head(nullptr), m_tail(nullptr), length(0) {
		DoublyNode<T>* trav = list.m_head;
		while (trav) {
			PushBack(trav->GetValue());
			trav = trav->GetNextNode();
		}
	}
	
	DoublyList(DoublyList&& list) {
		m_head = list.m_head;
		m_tail = list.m_tail;
		length = list.length;

		list.m_head = list.m_tail = nullptr;
		list.length = 0;
	}

	DoublyList& operator=(DoublyList list) {
		list.Swap(*this);
		return *this;
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
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		newNode->SetNextNode(m_head);

		if (m_head)
			m_head->SetPrevNode(newNode);

		m_head = newNode;

		if (!m_tail)
			m_tail = newNode;
		++length;
	}

	void PopBack() {
		if (!m_tail)
			return;

		if (!m_tail->GetPrevNode()) {
			delete m_tail;
			m_tail = m_head = nullptr;
		}

		else {
			m_tail = m_tail->GetPrevNode();
			delete m_tail->GetNextNode();
			m_tail->SetNextNode(nullptr);
		}
		--length;
	}

	void PopFront() {
		if (!m_head)
			return;

		if (!m_head->GetNextNode()) {
			delete m_head;
			m_tail = m_head = nullptr;
		}

		else {
			m_head = m_head->GetNextNode();
			delete m_head->GetPrevNode();
			m_head->SetPrevNode(nullptr);
		}
		--length;
	}

	/* One useful method using size_t instead of int is the ability to 
	 throw even if the user of this function passes a negative number */

	T operator[](size_t index) {
		DoublyNode<T>* trav = m_head;
		while (index--) {
			trav = trav->GetNextNode();
			if (!trav)
				throw "Index is invalid\n";
		}
		return trav->GetValue();
	}

	void Insert(const T& value, size_t index) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		DoublyNode<T>* trav = m_head;
		if (!m_head || !index) {
			PushFront(value);
			return;
		}
		while (--index) {
			trav = trav->GetNextNode();
			if (!trav)
				throw "Index is invalid\n";
		}
		newNode->SetPrevNode(trav);
		newNode->SetNextNode(trav->GetNextNode());
		trav->SetNextNode(newNode);
		if(newNode->GetNextNode())
			newNode->GetNextNode()->SetPrevNode(newNode);
		++length;

	}

	void Delete(size_t index) {
		DoublyNode<T>* trav = m_head;

		if (!index) {
			PopFront();
			return;
		}

		while (--index) {
			trav = trav->GetNextNode();
			if (!trav)
				throw "Index is invalid\n";
		}

		if (!trav->GetNextNode())
			throw "Index is invalid\n";

		if (!trav->GetNextNode()->GetNextNode()) {
			PopBack();
			return;
		}

		trav->SetNextNode(trav->GetNextNode()->GetNextNode());
		delete trav->GetNextNode()->GetPrevNode();
		trav->GetNextNode()->SetPrevNode(trav);
		--length;
	}

	bool IsEmpty() const {
		return m_head == nullptr;
	}

	void Swap(DoublyList& list) {
		DoublyNode<T>* temp = list.m_head;
		list.m_head = m_head;
		m_head = temp;

		temp = list.m_tail;
		list.m_tail = m_tail;
		m_tail = temp;

		size_t tempLength = list.length;
		list.length = length;
		length = tempLength;
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
		if (!m_head)
			return;

		DoublyNode<T>* trav = m_head;
		while (trav->GetNextNode()) {
			trav = trav->GetNextNode();
			delete trav->GetPrevNode();
		}
		delete trav;
		m_head = m_tail = nullptr;
		length = 0;
	}

};