#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;

int main() {
	
	SinglyList<int>* list = new SinglyList<int>;
	SinglyList<int>* list2 = new SinglyList<int>;
	list->PushBack(20);
	list->PushFront(42);
	list->PushBack(98);
	list2->PushBack(97);
	list2->PushBack(91);
	*list2 = move(*list);
	cout << *list << endl;
	cout << *list2 << endl;
	delete list;
	delete list2;
	return 0;
}