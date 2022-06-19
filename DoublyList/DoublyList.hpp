#pragma once
#include "../DoublyNode/DoublyNode.hpp"
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
		push_back(value);
	}

	DoublyList(const std::initializer_list<T>& list) : m_head(nullptr), m_tail(nullptr), length(0) {
		for (auto value : list)
			push_back(value);
	}
	
	DoublyList(const DoublyList& list) : m_head(nullptr), m_tail(nullptr), length(0) {
		DoublyNode<T>* trav = list.m_head;
		while (trav) {
			push_back(trav->get_value());
			trav = trav->get_next_node();
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
		list.swap(*this);
		return *this;
	}

	size_t get_length() const {
		return length;
	}

	void push_back(const T& value) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		newNode->set_previous_node(m_tail);

		if(m_tail)
			m_tail->set_next_node(newNode);

		m_tail = newNode;

		if (!m_head)
			m_head = newNode;
		++length;
	}

	void push_front(const T& value) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		newNode->set_next_node(m_head);

		if (m_head)
			m_head->set_previous_node(newNode);

		m_head = newNode;

		if (!m_tail)
			m_tail = newNode;
		++length;
	}

	void pop_back() {
		if (!m_tail)
			return;

		if (!m_tail->get_previous_node()) {
			delete m_tail;
			m_tail = m_head = nullptr;
		}

		else {
			m_tail = m_tail->get_previous_node();
			delete m_tail->get_next_node();
			m_tail->set_next_node(nullptr);
		}
		--length;
	}

	void pop_front() {
		if (!m_head)
			return;

		if (!m_head->get_next_node()) {
			delete m_head;
			m_tail = m_head = nullptr;
		}

		else {
			m_head = m_head->get_next_node();
			delete m_head->get_previous_node();
			m_head->set_previous_node(nullptr);
		}
		--length;
	}

	/* One useful method using size_t instead of int is the ability to 
	 throw even if the user of this function passes a negative number */

	T operator[](size_t index) {
		DoublyNode<T>* trav = m_head;
		while (index--) {
			trav = trav->get_next_node();
			if (!trav)
				throw "Index is invalid\n";
		}
		return trav->get_value();
	}

	void insert(const T& value, size_t index) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		DoublyNode<T>* trav = m_head;
		if (!m_head || !index) {
			delete newNode;
			push_front(value);
			return;
		}
		while (--index) {
			trav = trav->get_next_node();
			if (!trav) {
				delete newNode;
				throw "Index is invalid\n";
			}
		}
		newNode->set_previous_node(trav);
		newNode->set_next_node(trav->get_next_node());
		trav->set_next_node(newNode);
		if(newNode->get_next_node())
			newNode->get_next_node()->set_previous_node(newNode);
		++length;
	}

	void delete_at(size_t index) {
		DoublyNode<T>* trav = m_head;

		if (!index) {
			pop_front();
			return;
		}

		while (--index) {
			trav = trav->get_next_node();
			if (!trav)
				throw "Index is invalid\n";
		}

		if (!trav->get_next_node())
			throw "Index is invalid\n";

		if (!trav->get_next_node()->get_next_node()) {
			pop_back();
			return;
		}

		trav->set_next_node(trav->get_next_node()->get_next_node());
		delete trav->get_next_node()->get_previous_node();
		trav->get_next_node()->set_previous_node(trav);
		--length;
	}

	bool is_empty() const {
		return m_head == nullptr;
	}

	void swap(DoublyList& list) {
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
			out << trav->get_value() << ' ';
			trav = trav->get_next_node();
		}
		return out;
	}

	void print_reversed() const {
		DoublyNode<T>* trav = m_tail;
		while (trav) {
			std::cout << trav->get_value() << ' ';
			trav = trav->get_previous_node();
		}
	}

	~DoublyList() {
		if (!m_head)
			return;

		DoublyNode<T>* trav = m_head;
		while (trav->get_next_node()) {
			trav = trav->get_next_node();
			delete trav->get_previous_node();
		}
		delete trav;
		m_head = m_tail = nullptr;
		length = 0;
	}

};