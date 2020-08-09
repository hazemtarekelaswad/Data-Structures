#include "Vector.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

	Vector<int> vec = { 9, 5, 4, 3, 2 };
	cout << vec << endl;
	vec.Insert(11111, 1);
	cout << vec << endl;
	
	return 0;

}