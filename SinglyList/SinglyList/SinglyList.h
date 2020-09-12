#pragma once
#include "Node.h"
#include <iostream>

template<typename T>
class SinglyList {
private:
	Node* m_head;
	size_t length;

public:
	SinglyList() : m_head(nullptr), length(0) {}

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

	}

	void PushBack(const T& value) {

	}

	void PushFront(const T& value) {

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