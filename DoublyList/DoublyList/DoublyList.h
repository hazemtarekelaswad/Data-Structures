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
	DoublyList() {

	}

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

	~DoublyList() {

	}

};