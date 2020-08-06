#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

	try {
		Matrix mat(2, 3);
		Matrix mat2(3, 1);
		cin >> mat >> mat2;
	
		cout << mat.Transpose() << endl;
	}
	catch (const char *msg) {
		cout << "ERROR! \n" << msg << endl;
	}
	return 0;
}