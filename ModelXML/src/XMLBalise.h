#ifndef XMLBALISE_H_
#define XMLBALISE_H_

#include <iostream>
#include <list>
#include <string>
#include <map>
#include "XMLElement.h"

using namespace std;

class XMLBalise: public XMLElement {
public:
	XMLBalise(string name, string ns="", bool autoClosed = false, bool special=false);
	virtual ~XMLBalise();

	void addElement(XMLElement * elem);
	void addElements(list<XMLElement *> elem);
	void setElementList(list<XMLElement*> * elemList);
	void addAttribute(string name, string value="");
	void setAttList(map<string,string> * list);
	void setValueAttribute(string name, string value);
	void setAutoClosed(bool autoClosed);
	void setAttList(map<string,string> list);

	list<XMLElement *> getElements();
	map<string,string> getAttributes();

	string toString();
	string toString(int lvl);
	string getChildrenTypes();
	string getType();
	string getName();
	string getNameSpace();
	bool getAutoClosed();
	
	XMLBalise * match(XMLBalise * xsl, bool racine = false);

protected:
	list<XMLElement *> elements;
	map<string,string> attributs;
	string name;
	string ns;
	bool autoClosed;
  bool special;

};

#endif /* XMLBALISE_H_ */
