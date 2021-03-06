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

	// Recuperation de la liste des attributs de la balise XML en cours
	map<string,string> listeAttributes(xml->getAttributes());

	cout << "Nom Balise : " << xml->getName() << endl;

	if (!(docDTD->getDescriptionElement(xml->getName()).empty())) {

		// Validation de la balise XML avec la DTD
		regOK = validate(xml->getChildrenTypes(), docDTD->getDescriptionElement(xml->getName()));

		// Validation des attributs avec la DTD
		if (regOK == true) {
			if (!listeAttributes.empty()) {

				for(map<string, string>::iterator it_attribute = listeAttributes.begin();
							it_attribute != listeAttributes.end() && regOK == true;
							it_attribute++) {

					regOK = validateAtt(it_attribute->first, docDTD->getAttribut(xml->getName()));
				}
			}
		}

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

/*
 * On vérifie que l'attribut du XML (premier argument) est bien dans la DTD
 */
bool Validator::validateAtt (string attName, list<DTDattribut*> attributsDTD) {

	bool trouve = false;
	list<DTDattribut *>::iterator it;
	for(it = attributsDTD.begin(); it != attributsDTD.end() && !trouve ; it++){
		if ((*it)->getNomAtt() == attName) {
			trouve = true;
		}
	}
	return trouve;
}

bool Validator::validate(const string xmlTypes, string descriptionTypeBalise){
	string xmlTypesM = xmlTypes.substr(0, xmlTypes.length()-1);
	xmlTypesM = convertToRegex(xmlTypesM);

	//const string regexRecupere= convertToRegex(descriptionTypeBalise);
	const string regexRecupere = descriptionTypeBalise;


	cout << "ChildrenTypes : [" << xmlTypesM << "]    - DTD : [" << regexRecupere << "]" << endl;


	regex e (regexRecupere);
	cout << regex_match(xmlTypesM,e) << endl;
	return regex_match(xmlTypesM,e);
}

string Validator::convertToRegex(string description){
	unsigned int pos = description.find(" ");
	while (pos != string::npos) {
		description.replace(pos, 1, ",");
		pos = description.find(" ", pos+1);
	}
	return description;
}
