/*
 * Validator.h
 *
 *  Created on: 4 avr. 2012
 *      Author: mica
 */

#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include  "../ModelXML/src/XMLElement.h"
#include  "../ModelXML/src/XMLBalise.h"
#include  "../ModelXML/src/XMLData.h"
#include  "../ModelDTD/src/Document.h"
#include  "../ModelDTD/src/Element.h"

class Validator {
public:
	Validator(Document * docDTD);
	virtual ~Validator();
	bool validateXML(XMLBalise * xml);
	string convertToRegex(string description);

protected:
	Document * docDTD;
	bool validate(const string xmlTypes, string regex);

};

#endif /* VALIDATOR_H_ */