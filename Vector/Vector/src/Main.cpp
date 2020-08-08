#include "Vector.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	Vector<int> vec1;
	
	vec1.push_back(5);
	cout << vec1 << endl;
	vec1.push_back(8);
	cout << vec1 << endl;
	vec1.push_back(9);
	cout << vec1 << endl;
	vec1.push_back(20);
	cout << vec1 << endl;
	
	vec1.pop_back();
	cout << vec1 << endl;
	vec1.pop_back();
	cout << vec1 << endl;
	vec1.pop_back();
	cout << vec1 << endl;
	vec1.pop_back();
	cout << vec1 << endl;

	vec1.push_back(11111);
	cout << vec1 << endl;

}