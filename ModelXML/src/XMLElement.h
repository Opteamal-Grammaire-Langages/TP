/*
 * XMLElement.h
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#ifndef XMLELEMENT_H_
#define XMLELEMENT_H_

#include <string>

#define TAB "  " //I don't like big tabs
using namespace std;


class XMLElement {
public:
	XMLElement();
	virtual ~XMLElement();

	virtual string toString() = 0;
	virtual string toString(int lvl) = 0;
	virtual string getType() = 0;
	void setParent(XMLElement * elem);
	XMLElement * getParent(XMLElement * elem);
protected:
	XMLElement * parent;
};

#endif /* XMLELEMENT_H_ */

