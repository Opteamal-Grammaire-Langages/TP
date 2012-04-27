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
	list<XMLElement *>::iterator it;

	for(it = specials.begin(); it != specials.end() ; it++){
		delete *it;
	}
  delete doctype;
}

void XMLDocument::setDoctype(Document * dtd){
  doctype=dtd;
}

Document * XMLDocument::getDoctype(){
  return doctype;
}
void XMLDocument::addSpecials(list<XMLElement *> spec){

	list<XMLElement *>::iterator it;
	for(it = spec.begin(); it != spec.end() ; it++){
		specials.push_back(*it);
	}
}

void XMLDocument::setSpecialsList(list<XMLElement*> * list){
  /*elements=*list;*/
  
  addSpecials(*list);
  
  /*list<XMLElement*>::iterator it;
	for(it = elements.begin(); it != elements.end() ; it++){
		(*it)->setParent(this);
	}*/
  delete list;
}

string XMLDocument::toString(){

	string ret;

  // Ecriture du contenu des speciaux
  for(list<XMLElement *>::iterator it_element = specials.begin();
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
  for(list<XMLElement *>::iterator it_element = specials.begin();
      it_element != specials.end();
      it_element++) {
    ret += (*it_element)->toString(lvl+1) + "\n";
  }

  //ecriture enfant
  ret+=child->toString();
	return ret;
}

string XMLDocument::getType(){
	return "document";
}

XMLElement * XMLDocument::getChild(){
  return child;
}
string XMLDocument::getChildType(){
	return child->getType();
}

list<XMLElement *> XMLDocument::getSpecials(){
	return this->specials;
}

