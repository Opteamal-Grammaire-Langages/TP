/*
 * XMLData.h
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#ifndef XMLDATA_H_
#define XMLDATA_H_

#include <string>
#include "XMLElement.h"

using namespace std;

class XMLData : public XMLElement {
public:
	XMLData(string data);
	virtual ~XMLData();

	string getData();
	string toString();
	string getType();

private:
	string data;
};

#endif /* XMLDATA_H_ */
