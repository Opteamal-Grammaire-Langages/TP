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
#include <map>

using namespace std;

class Document {
public:
	typedef struct
	{
		string nomAtt;
		string typeAtt;
		string optionAtt;
	}attribut;

	Document();
	virtual ~Document();
	list<Element*> getListeElements();
	map<string, list<Document::attribut*> > getMapAttributs();
	string getDescriptionElement(string elem);
	void addElement(Element * elem);
	void addAttributsElement(pair<string, list<attribut*> >);
	string toString();

private:
	list<Element*> listeElements;
	map<string, list<Document::attribut*> > mapAttributs;
};

#endif /* DOCUMENT_H_ */
