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
	//listeElements = new List<Element*>();
}

Document::~Document() {
	// TODO Auto-generated destructor stub
}

list<Element*> Document::getListeElements()
{
	return listeElements;
}

map<string, list<DTDattribut*> > Document::getMapAttributs()
{
	return mapAttributs;
}

void Document::addElement(Element * elem){
	listeElements.push_front(elem);
}

void Document::addAttributsElement(pair<string, list<DTDattribut*> > paire) {
	mapAttributs.insert(paire);
}

string Document::getDescriptionElement(string elem){
	list<Element*>::iterator it;

	for(it = listeElements.begin(); it != listeElements.end(); it++){
		if((*it)->getNom() == elem){
			return (*it)->getDescription();
		}
	}
	return "";
}

string Document::toString(){
	string ret = "";
	list<Element*>::iterator it;

	for(it = listeElements.begin(); it != listeElements.end(); it++){
		ret += "<!ELEMENT ";
		ret += (*it)->toString();
		ret += ">\n";
	}
	
	for(map<string, list<DTDattribut*> >::iterator it=mapAttributs.begin() ; it!=mapAttributs.end() ; ++it)
	{
		ret += "<!ATTLIST ";
	  ret += it->first; // accede à la clé
	  ret += "\n";
	  list<DTDattribut*> listeAttributs = it->second; // accede à la valeur
	  
	  for(list<DTDattribut*>::iterator ita = listeAttributs.begin(); ita != listeAttributs.end(); ita++){
	  	ret += "\t";
			ret += (*ita)->toString();
			ret += "\n";
		}
		ret += ">\n";
	}
	

	return ret;
}
