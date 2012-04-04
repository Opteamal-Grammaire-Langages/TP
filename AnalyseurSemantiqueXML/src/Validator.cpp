/*
 * Validator.cpp
 *
 *  Created on: 4 avr. 2012
 *      Author: mica
 */

#include "Validator.h"
#include <boost/regex.hpp>

using namespace boost;

Validator::Validator(Document * docDTD) {
	// TODO Auto-generated constructor stub
	this->docDTD = docDTD;
}

Validator::~Validator() {
	// TODO Auto-generated destructor stub
}

bool Validator::validateXML(XMLBalise * xml){

	bool regOK = true;
	list<XMLElement *>::iterator it;
	list<XMLElement *> listeElements(xml->getElements());

	regOK = validate(xml->getChildrenTypes(), docDTD->getDescriptionElement(xml->getName()));

	for(it = listeElements.begin(); it != listeElements.end() && regOK ; it++){
		if((*it)->getType() != "#PCDATA"){//Element non terminal
			regOK = validateXML((XMLBalise *)(*it));
		}
	}

	return regOK;

}

bool Validator::validate(const string xmlTypes, string descriptionTypeBalise){
	regex e = convertToRegex(descriptionTypeBalise);
	return regex_match(xmlTypes,e);

}

string convertToRegex(string description){
	return description.replace(description.begin(),description.end(), ',', ' ');
}
