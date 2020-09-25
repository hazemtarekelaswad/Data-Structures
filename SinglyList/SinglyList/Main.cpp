#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;
using SL = SinglyList<int>;

int main() {
	
	SL list;
	SL list2 = { 5, 8, 7 };
	list = SL{12, 78, 9};
	cout << list << endl << list2 << endl;
	return 0;
}