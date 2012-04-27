#ifndef XMLDOCUMENT_H_
#define XMLDOCUMENT_H_

#include <iostream>
#include <list>
#include <string>
#include <map>
#include "XMLBalise.h"
#include "XMLElement.h"
#include "../../ModelDTD/src/Document.h"

using namespace std;

class XMLDocument: public XMLElement {
public:
	XMLDocument();
	virtual ~XMLDocument();

	void setChild(XMLElement * child);
	void setSpecialsList(list<XMLBalise*> * specList);
  void addSpecials(list<XMLBalise*> spec);
  void setDoctype(Document * dtd);
  Document * getDoctype();

	XMLElement * getElement();

	string toString();
  string getType();
  string getXSLfile();
	string toString(int lvl);
	list<XMLBalise *> getSpecials();
	string getChildType();
  XMLElement * getChild();
	
protected:
	Document * doctype;
  list<XMLBalise*> specials;
	XMLElement * child;
};

#endif /* XMLBALISE_H_ */
