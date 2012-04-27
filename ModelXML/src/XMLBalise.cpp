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
  parent = 0;
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

void XMLBalise::addElements(list<XMLElement *> elem){

	list<XMLElement *>::iterator it;
	for(it = elem.begin(); it != elem.end() ; it++){
		elements.push_back(*it);
	}
}

void XMLBalise::setElementList(list<XMLElement*> * list){
  /*elements=*list;*/
  
  addElements(*list);
  
  /*list<XMLElement*>::iterator it;
	for(it = elements.begin(); it != elements.end() ; it++){
		(*it)->setParent(this);
	}*/
  delete list;
}

void XMLBalise::setAttList(map<string,string> * list){
  attributs=*list;
  delete list;
}

void XMLBalise::addAttribute(string attribute, string value){
	attributs[attribute] = value;
}

void XMLBalise::setAttList(map<string,string> list){
  attributs=list;
}

string XMLBalise::toString(){

	// Ouverture de la balise
	string ret (OPEN_TAG);

  ret+= this->ns;
  if (!ns.empty()) ret += ":";
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
  ret += this->ns;
  if (!ns.empty())) ret += ":";
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

map<string,string> XMLBalise::getAttributes() {
	return this->attributs;
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

bool XMLBalise::getAutoClosed(){
	return autoClosed;
}

/**
 * Vérifie l'existence d'un noeud XLST qui matche avec le nom de la balise XML
 * Si la balise est trouvee, renvoie la balise XLST
 * Si la balise n'est pas trouvee, renvoie 0
 */
XMLBalise * XMLBalise::match( XMLBalise * xsl, bool racine){

	list<XMLElement *> listeElements = xsl->getElements();
	//Parcours de tous les elements XML
	for(list<XMLElement *>::iterator it_element = listeElements.begin();
			it_element != listeElements.end() ;
			it_element++) {

			XMLBalise* balise = dynamic_cast<XMLBalise*>(*it_element);
		 
		 if( (balise != 0) // Si balise est une instance de XMLBalise
		 && (balise->getName() == "template") && balise->getNameSpace().compare("xsl") == 0
		 && (balise->getAttributes().find("match") != balise->getAttributes().end()) ) // Si l'attribut match est present
		 {
		 	map<string,string> mapAttributs = balise->getAttributes();
		 	string matchingName = mapAttributs.find("match")->second;

			//Si on est pas la racine
			if(racine == false){
				if (name.compare(matchingName) == 0 ){ //Si la valeur de l'attribut match est celle recherchee
		 			return balise;
		 		}
			//Si on se trouve a la racine
			}else{
				if (matchingName.compare("/") == 0 || name.compare(matchingName) == 0 ){ //Si la valeur de l'attribut match est celle recherchee
		 			return balise;
		 		}
			}
		 	
		 }
	}
	return 0;
}








