#ifndef XMLBALISE_H_
#define XMLBALISE_H_

#include <iostream>
#include <list>
#include <string>
#include <map>
#include "XMLElement.h"
#include "../../ModelDTD/src/Document.h"

using namespace std;

class XMLDocument: public XMLElement {
public:
	XMLDocument();
	virtual ~XMLDocument();

	void setChild(XMLElement * child);
	void setSpecialsList(list<XMLElement*> * specList);
  void addSpecials(list<XMLElement*> spec);
  void setDoctype(Document * dtd);
  Document * getDoctype();

	XMLElement * getElement();

	string toString();
  string getType();
	string toString(int lvl);
	list<XMLElement *> getSpecials();
	string getChildType();
  XMLElement * getChild();
	
protected:
	Document * doctype;
  list<XMLElement*> specials;
	XMLElement * child;
};

#endif /* XMLBALISE_H_ */
