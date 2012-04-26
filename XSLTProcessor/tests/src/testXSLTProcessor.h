/*
 * testXSLTProcessor.h
 *
 *  Created on: 26 avr. 2012
 *      Author: tommi
 */

#ifndef TESTXSLTPROCESSOR_H_
#define TESTXSLTPROCESSOR_H_

#include  "../../../ModelXML/src/XMLElement.h"
#include  "../../../ModelXML/src/XMLBalise.h"
#include  "../../../ModelXML/src/XMLData.h"
#include  "../../../ModelDTD/src/Document.h"
#include  "../../../ModelDTD/src/Element.h"

#include "../../src/XSLTProcessor.h"

#include "../../../arbreXML/src/modeliseurxml.h"

#include <iostream>

using namespace std;

class testXSLTProcessor {

public:
static bool testXSLT1();
static bool testXSLT2();

protected:
static XMLBalise * creationArbreXML();
static XMLBalise * creationArbreXMLConstruit();

static XMLBalise * creationArbreXSL();
static XMLBalise * creationArbreXSLConstruit();

static XMLBalise * creationHTMLFinalVerification();

};


#endif /* TESTXSLTPROCESSOR_H_ */
