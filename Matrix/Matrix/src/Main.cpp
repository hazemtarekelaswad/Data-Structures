#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

	try {
		Matrix mat1(2, 2);
		cin >> mat1;
		Matrix mat2(move(mat1));
	
		cout << mat1 << endl << mat2 << endl;
		
	}
	catch (const char *msg) {
		cout << "ERROR! \n" << msg << endl;
	}
	return 0;
}