#include "testXSLTProcessor.h"
#include <iostream>
using namespace std;

int main() {
	if (testXSLTProcessor::testXSLT1() == true) {
		cout << "Test 1 correct" << endl;
	} else { cout << "Test 1 incorrect" << endl; }

	if (testXSLTProcessor::testXSLT2() == true) {
		cout << "Test 2 correct" << endl;
	} else { cout << "Test 2 incorrect" << endl; }



	return 0;
}
