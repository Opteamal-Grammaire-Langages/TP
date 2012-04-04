/*
 * Document.h
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_
#include "Element.h"
#include <list>
using namespace std;


class Document {
public:


	Document();
	virtual ~Document();
	list<Element> getListeElements();

private:
	list<Element> listeElements;
};

#endif /* DOCUMENT_H_ */
