#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;
using SL = SinglyList<int>;

int main() {
	
	SL list = { 1, 2 };
	try {
		list.Delete(1);
		cout << list << endl;
	}
	catch (...) {
		cout << "SHIT\n";
	}
	return 0;
}