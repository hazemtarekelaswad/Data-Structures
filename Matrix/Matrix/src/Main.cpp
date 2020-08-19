#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

	try {
		Matrix<int, 2, 2> mat1;
		cin >> mat1;

		Matrix<int, 2, 3> mat2;
		cin >> mat2;


		//cout << mat1 + mat2 << endl;
		//cout << mat1 - mat2 << endl;
		cout << mat1 * mat2 << endl;
		cout << mat1 * 10 << endl << 10 * mat2 << endl;
		cout << mat1.Transpose() << endl;

		
	}
	catch (const char *msg) {
		cout << "ERROR! \n" << msg << endl;
	}
	return 0;
}