#pragma once

#include <iostream>
#include <initializer_list>
#include "SinglyList.h"

template<typename T>
class Stack {
private:
	SinglyList<T> m_list;

public:
	Stack() {

	}

	Stack(const T& value) {

	}

	Stack(const std::initializer_list<T>& list) {

	}

	Stack(const Stack& stack) {

	}

	Stack(Stack&& stack) {

	}

	Stack& operator=(Stack stack) {

	}

	void Swap(Stack& stack) {

	}

	friend std::ostream& operator<<(std::ostream& out, const Stack& stack) {

	}

	void Push(const T& value) {

	}

	void Pop() {

	}

	T Top() {

	}

	size_t Size() const {

	}

	bool IsEmpty() const {

	}
};