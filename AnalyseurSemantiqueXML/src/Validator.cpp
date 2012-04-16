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
	if (docDTD == NULL) {
		this->docDTD = new Document();
	} else {
		this->docDTD = docDTD;
	}
}

Validator::~Validator() {
	// TODO Auto-generated destructor stub
}

bool Validator::validateXML(XMLBalise * xml){

	bool regOK = false;
	list<XMLElement *>::iterator it;
	list<XMLElement *> listeElements(xml->getElements());

	cout << "Nom Balise : " << xml->getName() << endl;

	if (!(docDTD->getDescriptionElement(xml->getName()).empty())) {
		regOK = validate(xml->getChildrenTypes(), docDTD->getDescriptionElement(xml->getName()));
	} else {
		if (xml->getChildrenTypes().empty()) {
			return true;
		} else {
			cout << "DTD vide" << endl;
			return false;
		}
	}

	for(it = listeElements.begin(); it != listeElements.end() && regOK ; it++){
		if((*it)->getType() != "CDATA"){//Element non terminal
			regOK = validateXML((XMLBalise *)(*it));
		}
	}

	return regOK;
}

bool Validator::validate(const string xmlTypes, string descriptionTypeBalise){
	string xmlTypesM = xmlTypes.substr(0, xmlTypes.length()-1);

	const string regexRecupere= convertToRegex(descriptionTypeBalise);
	cout << "ChildrenTypes : [" << xmlTypesM << "]    - DTD : [" << regexRecupere << "]" << endl;

	regex e (regexRecupere);
	return regex_match(xmlTypesM,e);
}

string Validator::convertToRegex(string description){
	int pos = 0;
	pos = description.find(',');
	while (pos != (int) string::npos) {
		description.replace(pos, 1, " ");
		pos = description.find(',');
	}
	return description;
}
