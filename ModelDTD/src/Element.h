/*
 * Element.h
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_
#include <string>
using namespace std;

class Element {

public:
	Element();
	Element(string nom, string description);
	virtual ~Element();

	string getDescription() const {return description;}
	string getNom() const {return nom;}
	string toString();

private:
	string nom;
	string description;

};

#endif /* ELEMENT_H_ */
