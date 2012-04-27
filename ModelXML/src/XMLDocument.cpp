/*
 * XMLDocument.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: obi wan kenobi
 */

#include <iterator>
#include <cstdlib> //free
#include "XMLDocument.h"

#define OPEN_TAG "<"
#define CLOSE_TAG ">"
#define SLASH "/"
#define EX "!"


XMLDocument::XMLDocument(){
  doctype=NULL;
  child=NULL;
}

XMLDocument::~XMLDocument() {
	list<XMLBalise *>::iterator it;

	for(it = specials.begin(); it != specials.end() ; it++){
		delete (XMLElement*)(*it);
	}
  delete doctype;
}

void XMLDocument::setDoctype(Document * dtd){
  doctype=dtd;
}

Document * XMLDocument::getDoctype(){
  return doctype;
}
void XMLDocument::addSpecials(list<XMLBalise *> spec){

	list<XMLBalise *>::iterator it;
	for(it = spec.begin(); it != spec.end() ; it++){
		specials.push_back(*it);
	}
}

void XMLDocument::setSpecialsList(list<XMLBalise*> * list){
  
  addSpecials(*list);
  
  delete list;
}

string XMLDocument::toString(){

	string ret;

  // Ecriture du contenu des speciaux
  for(list<XMLBalise *>::iterator it_element = specials.begin();
      it_element != specials.end();
      it_element++) {
    ret += (*it_element)->toString() + "\n";
  }

  //ecriture enfant
  ret+=child->toString();
	return ret;
}

string XMLDocument::toString(int lvl){
	// Ouverture de la balise
	string ret;
  for (int i=0; i<lvl; i++){
    ret += TAB;
  }

  // Ecriture du contenu des speciaux
  for(list<XMLBalise *>::iterator it_element = specials.begin();
      it_element != specials.end();
      it_element++) {
    ret += (*it_element)->toString(0) + "\n";
  }

  //ecriture enfant
  ret+=child->toString(0);
	return ret;
}

string XMLDocument::getXSLfile(){
  list<XMLBalise*>::iterator it;
  for (it=specials.begin(); it!=specials.end(); it++){
    if ((*it)->getName=="xml-stylesheet"){
      return (*it)->getAttributes()["href"];
    }
  }
}
string XMLDocument::getType(){
	return "document";
}

XMLElement * XMLDocument::getChild(){
  return child;
}

void XMLDocument::setChild(XMLElement *ch){
  child=ch;
}

string XMLDocument::getChildType(){
	return child->getType();
}

list<XMLElement *> XMLDocument::getSpecials(){
	return this->specials;
}

