#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;
using SL = SinglyList<int>;

int main() {
	
	SL list = {  };
	try {
		list.Insert(23, 4);
		cout << list << endl;
	}
	catch (...) {
		cout << "SHIT\n";
	}
	return 0;
}