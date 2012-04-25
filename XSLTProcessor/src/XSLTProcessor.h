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

#include "../../ModelXML/src/XMLBalise.h"
#include "../../ModelXML/src/XMLElement.h"
using namespace std;

class XSLTProcessor {

public:
	list<XMLElement *> xlstProcessor(XMLBalise *, XMLBalise *);
	XMLBalise * generateXSLXML (XMLBalise * xml, XMLBalise * xsl);



};

#endif /* XLSTPROCESSOR_H_ */
