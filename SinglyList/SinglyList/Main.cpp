#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;

int main() {
	
	SinglyList<int> list1 = {10, 55, 98, 123, 1, 47}, list2;
	list1.PushBack(8);
	list1.PushFront(7);
	cout << list1 << endl << list1.GetLength();
	/*list2 = list1;
	cout << list1 << endl;
	cout << list2 << endl;
	list2.PopBack();
	cout << list2 << endl;
	SinglyList<int> list3(list2);
	cout << list3 << endl;*/

	return 0;
}