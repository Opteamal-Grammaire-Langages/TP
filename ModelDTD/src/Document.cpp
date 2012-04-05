/*
 * Document.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 */

#include "Document.h"
#include <iostream>


Document::Document() {
	// TODO Auto-generated constructor stub

}

Document::~Document() {
	// TODO Auto-generated destructor stub
}

list<Element*> Document::getListeElements()
{
	return listeElements;
}

map<string, list<Document::attribut*> > Document::getMapAttributs()
{
	return mapAttributs;
}

void Document::addElement(Element * elem){
	listeElements.push_front(elem);
}

void Document::addAttributsElement(pair<string, list<attribut*> > paire) {
	mapAttributs.insert(paire);
}

string Document::getDescriptionElement(string elem){
	list<Element*>::iterator it;

	for(it = listeElements.begin(); it != listeElements.end(); it++){
		if((*it)->getNom() == elem){
			return (*it)->getDescription();
		}
	}
	return 0;
}

string Document::toString(){
	string ret = "";
	list<Element*>::iterator it;

	for(it = listeElements.begin(); it != listeElements.end(); it++){
		ret += (*it)->toString();
		ret += "\n";
	}
	return ret;
}






