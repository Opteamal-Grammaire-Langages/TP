/*
 * Element.h
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_
#include <map>
#include <string>
using namespace std;

class Element {

public:
	Element();
	Element(string nom, string description);
	virtual ~Element();

	struct attribut
	{
		string nomAtt;
		string typeAtt;
		string optionAtt;
	};

	map<string,attribut> getAtt() const {return att;}

	string getDescription() const {return description;}

	string getNom() const {return nom;}

private:
	string nom;
	string description;
	map<string,attribut> att;

};

#endif /* ELEMENT_H_ */
