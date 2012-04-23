//============================================================================
// Name        : Validate.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "testValidator.h"
#include <iostream>
using namespace std;

int main() {
	if (testValidator::testValidator1() == true) {
		cout << "Test 1 correct" << endl;
	} else { cout << "Test 1 incorrect" << endl; }

	if (testValidator::testValidator2() == false) {
		cout << "Test 2 correct" << endl;
	} else { cout << "Test 2 incorrect" << endl; }

	if (testValidator::testValidator3() == false) {
		cout << "Test 3 correct" << endl;
	} else { cout << "Test 3 incorrect" << endl; }


	return 0;
}
