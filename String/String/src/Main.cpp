#include "String.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	String str1("Shit ");
	String str2(str1);
	String str3("Ya hazem");
	cout << str1 + str3 << endl;
	//cout << String("Saif ") + String("Elaswad") << endl;

	
	

	return 0;
}