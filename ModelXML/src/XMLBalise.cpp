/*
 * XMLBalise.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#include <iterator>
#include <cstdlib> //free
#include "XMLBalise.h"

#define OPEN_TAG "<"
#define CLOSE_TAG ">"
#define SLASH "/"


XMLBalise::XMLBalise(string name, string ns, bool autoClosed){
	this->name = name;
	this->autoClosed = autoClosed;
	this->ns = ns;
}

XMLBalise::~XMLBalise() {
	list<XMLElement *>::iterator it;

	for(it = elements.begin(); it != elements.end() ; it++){
		free(*it);
	}
}

void XMLBalise::addElement(XMLElement * elem){
	elements.push_back(elem);
}
void XMLBalise::setElementList(list<XMLElement*> * list){
  elements=*list;
  delete list;
}
void XMLBalise::setAttList(map<string,string> * list){
  attributs=*list;
  delete list;
}
void XMLBalise::addAttribute(string attribute, string value){
	attributs[attribute] = value;
}

string XMLBalise::toString(){

	// Ouverture de la balise
	string ret (OPEN_TAG);

	ret += this->name;


	// Ecriture des attributs de la balise
	for(map<string, string>::iterator it_attribute = attributs.begin();
			it_attribute != attributs.end();
			it_attribute++) {
		ret += " " + it_attribute->first + "=\"" + it_attribute->second + "\"";
	}

	if (autoClosed) {
		// Fermeture de la balise
		ret += SLASH;
		ret += CLOSE_TAG;
	}
	else {
		ret += CLOSE_TAG;
		ret += "\n";
		// Ecriture du contenu de la balise
		for(list<XMLElement *>::iterator it_element = elements.begin();
				it_element != elements.end();
				it_element++) {
			ret += (*it_element)->toString() + "\n";
		}
		// Fermeture de la balise fermante
		ret += OPEN_TAG;
		ret += SLASH;
		ret += name;
		ret += CLOSE_TAG;
	}

	return ret;
}

string XMLBalise::toString(int lvl){
	// Ouverture de la balise
	string ret;
  for (int i=0; i<lvl; i++){
    ret += TAB;
  }
  ret += OPEN_TAG; 
	ret += this->name;

	// Ecriture des attributs de la balise
	for(map<string, string>::iterator it_attribute = attributs.begin();
			it_attribute != attributs.end();
			it_attribute++) {
		ret += " " + it_attribute->first + "=\"" + it_attribute->second + "\"";
	}
	if (autoClosed) {
		// Fermeture de la balise
		ret += SLASH;
		ret += CLOSE_TAG;
	}
	else {
		ret += CLOSE_TAG;
		ret += "\n";
		// Ecriture du contenu de la balise
		for(list<XMLElement *>::iterator it_element = elements.begin();
				it_element != elements.end();
				it_element++) {
			ret += (*it_element)->toString(lvl+1) + "\n";
		}

    for (int i=0; i<lvl; i++){
      ret += TAB;
    }
		// Fermeture de la balise fermante
		ret += OPEN_TAG;
		ret += SLASH;
		ret += name;
		ret += CLOSE_TAG;
	}
	return ret;
}

string XMLBalise::getChildrenTypes(){
	string ret;
	// Ecriture du contenu de la balise
	for(list<XMLElement *>::iterator it_element = elements.begin();
			it_element != elements.end();
			it_element++) {
		ret += (*it_element)->getType() + " ";
	}
	return ret;

}
string XMLBalise::getType(){
	return name;
}

list<XMLElement *> XMLBalise::getElements(){
	return this->elements;
}
string XMLBalise::getName(){
	return name;
}

void XMLBalise::setAutoClosed(bool autoClosed){
	this->autoClosed = autoClosed;
}

string XMLBalise::getNameSpace(){
	return ns;
}
