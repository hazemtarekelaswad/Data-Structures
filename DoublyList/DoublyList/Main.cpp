#include <iostream>
#include "DoublyList.h"
using namespace std;
using DL = DoublyList<int>;
int main() {
	
	DL lst{};
	DL lst2(896);
	lst = move(lst2);

	cout << "length: " << lst.GetLength() << endl << lst << endl;
	cout << "length: " << lst2.GetLength() << endl << lst2 << endl;

	return 0;
}