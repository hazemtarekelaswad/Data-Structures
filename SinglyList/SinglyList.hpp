#pragma once
#include "../Node/Node.hpp"
#include <initializer_list>
#include <iostream>

template<typename T>
class SinglyList {
private:
	Node<T>* m_head;
	size_t length;

public:
	SinglyList() : m_head(nullptr), length(0) {}

	SinglyList(const std::initializer_list<T>& initList) : m_head(nullptr), length(0) {
		/*typename std::initializer_list<T>::iterator element;
		for (element = initList.begin(); element != initList.end(); ++element)
			push_back(*element);*/

		for (auto element : initList)
			push_back(element);
	}

	SinglyList(const SinglyList& sList) : m_head(nullptr), length(0) {
		Node<T>* trav = sList.m_head;
		while (trav) {
			this->push_back(trav->get_value());
			trav = trav->get_next_node();
		}
	}

	SinglyList(SinglyList&& sList) : m_head(nullptr), length(0) {
		m_head = sList.m_head;
		length = sList.length;
		sList.m_head = nullptr;
		sList.length = 0;
	}

	SinglyList& operator=(SinglyList sList) {
		sList.swap(*this);
		return *this;
	}

	size_t get_length() const { 
		return length; 
	}

	friend std::ostream& operator<<(std::ostream& out, const SinglyList& sList) {
		Node<T>* trav = sList.m_head;
		while (trav) {
			out << trav->get_value() << ' ';
			trav = trav->get_next_node();
		}
		return out;
	}

	void push_back(const T& value) {
		Node<T>* newNode = new Node<T>(value);

		if (!m_head) {
			m_head = newNode;
			++length;
			return;
		}

		Node<T>* trav = m_head;
		while (trav->get_next_node())
			trav = trav->get_next_node();

		trav->set_next_node(newNode);
		++length;
	}

	void push_front(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->set_next_node(m_head);
		m_head = newNode;
		++length;
	}

	// Returns a boolean value depending on the success of poping operation, if the list is empty it would return false, yet true otherwise.

	bool pop_back() {
		Node<T>* trav = m_head;

		if (!m_head)
			return false;

		if (!m_head->get_next_node()) {
			delete m_head;
			m_head = nullptr;
			--length;
			return true;
		}

		while (trav->get_next_node()->get_next_node())
			trav = trav->get_next_node();
		delete trav->get_next_node();
		trav->set_next_node(nullptr);
		--length;
		return true;
	}

	// Returns a boolean value depending on the success of poping operation, if the list is empty it would return false, yet true otherwise.

	bool pop_front() {
		if (!m_head)
			return false;
		Node<T>* trav = m_head;
		m_head = m_head->get_next_node();
		delete trav;
		--length;
		return true;
	}

	void insert(const T& value, size_t index) {
		Node<T>* newNode = new Node<T>(value);
		Node<T>* trav = m_head;

		if (!index || !m_head) {
			delete newNode;
			push_front(value);
			return;
		}
		while (--index) {
			trav = trav->get_next_node();
			if (!trav) {
				delete newNode;
				throw "Invalid index passed\n";
			}
		}
		newNode->set_next_node(trav->get_next_node());
		trav->set_next_node(newNode);
		++length;
	}

	void delete_at(size_t index){
		Node<T>* travPrev = m_head;
		if (!index) {
			pop_front();
			return;
		}
		while (--index) {
			travPrev = travPrev->get_next_node();
			if (!travPrev)
				throw "Invalid index passed\n";
		}
		if(!travPrev->get_next_node())
			throw "Invalid index passed\n";

		Node<T>* nodeToDelete = travPrev->get_next_node();
		travPrev->set_next_node(nodeToDelete->get_next_node());
		delete nodeToDelete;
		--length;
	}

	T operator[](size_t index) {
		if (!m_head)
			throw "invalide index passed\n";
		Node<T>* trav = m_head;
		while (index--) {
			trav = trav->get_next_node();
			if(!trav)
				throw "invalide index passed\n";
		}
		return trav->get_value();
	}

	bool is_empty() const {
		return m_head == nullptr;
	}

	void reverse() {
		if (!m_head->get_next_node())
			return;

		Node<T>* prevTrav = nullptr;
		Node<T>* currTrav = m_head;
		Node<T>* nextTrav = m_head;

		while (nextTrav) {
			nextTrav = nextTrav->get_next_node();
			currTrav->set_next_node(prevTrav);
			
			prevTrav = currTrav;
			currTrav = nextTrav;
		}
		m_head = prevTrav;
	}

	void swap(SinglyList& sList) {
		Node<T>* tempHead = m_head;
		m_head = sList.m_head;
		sList.m_head = tempHead;

		size_t tempLength = length;
		length = sList.length;
		sList.length = tempLength;
	}

	~SinglyList() {
		if (!m_head)
			return;
		if (!m_head->get_next_node()) {
			delete m_head;
			m_head = nullptr;
			return;
		}
		Node<T>* trav = m_head;
		while (trav) {
			Node<T>* tempHead = trav;
			trav = trav->get_next_node();
			delete tempHead;
		}
		m_head = nullptr;
	}
};