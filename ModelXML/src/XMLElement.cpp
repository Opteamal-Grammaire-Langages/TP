/*
 * XMLElement.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#include "XMLElement.h"

XMLElement::XMLElement() {
	// TODO Auto-generated constructor stub
	parent = 0;
}

XMLElement::~XMLElement() {
	// TODO Auto-generated destructor stub
}

XMLBalise * XMLElement::getParent(){
	return parent; 
}

void XMLElement::setParent(XMLBalise * bal){
	parent = bal;
}
