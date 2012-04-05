/*
 * XMLBalise.h
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#ifndef XMLBALISE_H_
#define XMLBALISE_H_

#include <list>
#include <string>
#include <map>
#include "XMLElement.h"

using namespace std;

class XMLBalise: public XMLElement {
public:
	XMLBalise(string name, string ns="", bool autoClosed = false);
	virtual ~XMLBalise();

	void addElement(XMLElement * elem);
	void addAttribute(string name, string value="");
	void setValueAttribute(string name, string value);
	void setAutoClosed(bool autoClosed);

	list<XMLElement *> getElements();

	string toString();
	string getChildrenTypes();
	string getType();
	string getName();

protected:
	list<XMLElement *> elements;
	map<string,string> attributs;
	string name;
	string ns;
	bool autoClosed;
};

#endif /* XMLBALISE_H_ */
