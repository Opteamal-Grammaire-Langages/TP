/*
 * XMLElement.h
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#ifndef XMLELEMENT_H_
#define XMLELEMENT_H_

#include <string>

using namespace std;

class XMLElement {
public:
	XMLElement();
	virtual ~XMLElement();

	virtual string toString() = 0;
	virtual string getType() = 0;
};

#endif /* XMLELEMENT_H_ */

