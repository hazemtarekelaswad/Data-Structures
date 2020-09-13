#include <iostream>
#include <forward_list>
#include "SinglyList.h"
using namespace std;
using SL = SinglyList<int>;

int main() {
	
	SL list = { 5, 8, 6, 20 };
	cout << list[4];
	return 0;
}