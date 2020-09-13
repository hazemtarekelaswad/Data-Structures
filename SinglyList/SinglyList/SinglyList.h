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
		/*typename std::initializer_list<T>::iterator element;
		for (element = initList.begin(); element != initList.end(); ++element)
			PushBack(*element);*/

		for (auto element : initList)
			PushBack(element);
	}

	SinglyList(const SinglyList& sList) {
		Node<T>* trav = sList.m_head;
		while (trav) {
			this->PushBack(trav->GetValue());
			trav = trav->GetNextNode();
		}
	}

	SinglyList(SinglyList&& sList) {
		m_head = sList.m_head;
		length = sList.length;
		sList.m_head = nullptr;
		sList.length = 0;
	}

	SinglyList& operator=(const SinglyList& sList) {
		if (m_head) {
			~SinglyList();
			length = 0;
		}
		Node<T>* trav = sList.m_head;
		while (trav) {
			this->PushBack(trav->GetValue());
			trav = trav->GetNextNode();
		}
		return *this;
	}

	SinglyList& operator=(SinglyList&& sList) {
		if(m_head)
			~SinglyList();
		m_head = sList.m_head;
		length = sList.length;
		sList.m_head = nullptr;
		sList.length = 0;
		return *this;
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

	// Returns a boolean value depending on the success of poping operation, if the list is empty it would return false, yet true otherwise.

	bool PopBack() {
		Node<T>* trav = m_head;

		if (!m_head)
			return false;

		if (!m_head->GetNextNode()) {
			delete m_head;
			m_head = nullptr;
			--length;
			return true;
		}

		while (trav->GetNextNode()->GetNextNode())
			trav = trav->GetNextNode();
		delete trav->GetNextNode();
		trav->SetNextNode(nullptr);
		--length;
		return true;
	}

	// Returns a boolean value depending on the success of poping operation, if the list is empty it would return false, yet true otherwise.

	bool PopFront() {
		if (!m_head)
			return false;
		Node<T>* trav = m_head;
		m_head = m_head->GetNextNode();
		delete trav;
		--length;
		return true;
	}

	bool IsEmpty() const {
		return m_head == nullptr;
	}

	T operator[](size_t index) {
		if (!m_head)
			throw "invalide index passed\n";
		Node<T>* trav = m_head;
		while (index--) {
			trav = trav->GetNextNode();
			if(!trav)
				throw "invalide index passed\n";
		}
		return trav->GetValue();
	}

	void Swap(SinglyList& sList) {
		Node<T>* tempHead = m_head;
		size_t tempLength = length;
		m_head = sList.m_head;
		length = sList.length;
		sList.m_head = tempHead;
		sList.length = tempLength;
	}

	~SinglyList() {
		if (!m_head)
			return;
		if (!m_head->GetNextNode()) {
			delete m_head;
			m_head = nullptr;
			return;
		}
		Node<T>* trav = m_head;
		while (trav) {
			Node<T>* tempHead = trav;
			trav = trav->GetNextNode();
			delete tempHead;
		}
		m_head = nullptr;
	}
};