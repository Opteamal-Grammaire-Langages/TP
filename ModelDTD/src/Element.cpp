/*
 * Element.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 */

#include "Element.h"

Element::Element() {

}

Element::~Element() {
	// TODO Auto-generated destructor stub
}

Element::Element(string nom, string description){
	this->nom = nom;
	this->description = description;
}

string Element::toString(){
	string ret = "";
	ret += this->nom;
	ret += " ";
	ret += this->description;
	return ret;
}
