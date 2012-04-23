/*
 * Document.h
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_
#include "Element.h"
#include "DTDattribut.h"
#include <list>
#include <map>

using namespace std;

class Document {
public:

	Document();
	virtual ~Document();
	list<Element*> getListeElements();
	map<string, list<DTDattribut*> > getMapAttributs();
	string getDescriptionElement(string elem);
	void addElement(Element * elem);
	void addAttributsElement(pair<string, list<DTDattribut*> >);
	string toString();

private:
	list<Element*> listeElements;
	map<string, list<DTDattribut*> > mapAttributs;
};

#endif /* DOCUMENT_H_ */
