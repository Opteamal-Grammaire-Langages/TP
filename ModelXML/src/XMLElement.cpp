/*
 * XMLElement.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#include "XMLElement.h"

XMLElement::XMLElement() {
	parent = 0;
	// TODO Auto-generated constructor stub

}

XMLElement::~XMLElement() {
	// TODO Auto-generated destructor stub
}
void XMLElement::setParent(XMLElement * elem){
	parent = 0;
}

XMLElement * XMLElement::getParent(XMLElement * elem){
	return parent;
}
