#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;
using SL = SinglyList<int>;

int main() {
	
	SL list = { 1, 2, 8, 4, 7, 13 };
	try {
		cout << list << endl;
		list.Reverse();
		cout << list << endl;
	}
	catch (...) {
		cout << "SHIT\n";
	}
	return 0;
}