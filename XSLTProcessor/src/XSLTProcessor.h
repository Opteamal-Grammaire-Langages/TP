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

	XMLElement * generateXSLXML(XMLElement * docXML, XMLBalise * xls){}
protected:
	XMLBalise * generateTemplate(XMLBalise * templateMatched, XMLBalise * xls, XMLBalise * noeudXMLMatched){}
	XMLBalise * lookOverXSLToBuildTemplate(XMLElement * elementXML, XMLBalise * xls){}

}

#endif /* XLSTPROCESSOR_H_ */
