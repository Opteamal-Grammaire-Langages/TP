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

void Document::addElement(Element * elem){
	listeElements.push_front(elem);
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






