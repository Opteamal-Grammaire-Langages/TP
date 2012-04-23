/*
 * testValidator.h
 *
 *  Created on: 5 avr. 2012
 *      Author: mfagno
 */

#ifndef TESTVALIDATOR_H_
#define TESTVALIDATOR_H_

#include <iostream>

#include  "../../../ModelXML/src/XMLElement.h"
#include  "../../../ModelXML/src/XMLBalise.h"
#include  "../../../ModelXML/src/XMLData.h"
#include  "../../../ModelDTD/src/Document.h"
#include  "../../../ModelDTD/src/Element.h"

#include "../../../AnalyseurSemantiqueXML/src/Validator.h"

using namespace std;

class testValidator {

public:
	static bool testValidator1();
	static bool testValidator2();
	static bool testValidator3();
	static bool testValidator4();

protected:
	static XMLBalise * creationArbreXML();
	static Document * creationDTD();
	static Document * creationDTDPasAttribut();

	static XMLBalise * creationArbreXMLNonValide();

};


#endif /* TESTVALIDATOR_H_ */
