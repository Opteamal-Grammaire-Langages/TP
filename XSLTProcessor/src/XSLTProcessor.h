/*
 * XLSTProcessor.h
 *
 *  Created on: 25 avr. 2012
 *      Author: tommi
 */

#ifndef XLSTPROCESSOR_H_
#define XLSTPROCESSOR_H_

#include <string>
#include <list>
#include <iostream>

#include "../../ModelXML/src/XMLBalise.h"
#include "../../ModelXML/src/XMLElement.h"
#include "../../ModelXML/src/XMLData.h"
using namespace std;

class XSLTProcessor {

public:

	static list<XMLElement *> generateXSLXML(XMLBalise * docXML, XMLBalise * xls);
protected:
	static list<XMLElement *> generateTemplate(XMLBalise * templateMatched, XMLBalise * xls, XMLBalise * noeudXMLMatched);
	static list<XMLElement *> lookOverXSLToBuildTemplate(XMLBalise * elementXSL, XMLBalise * xls, XMLBalise * xmlMatching);

};

#endif /* XLSTPROCESSOR_H_ */
