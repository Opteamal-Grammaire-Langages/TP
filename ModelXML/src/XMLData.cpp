/*
 * XMLData.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#include "XMLData.h"

XMLData::XMLData(string dataValue) {
	data = dataValue;
}

XMLData::~XMLData() {
	// TODO Auto-generated destructor stub
}

string XMLData::getData() {
	return data;
}

string XMLData::toString() {
	return data;
}
string XMLData::toString(int lvl) {
  string dump;
  for (int i=0; i<lvl; i++){
    dump += TAB;
  }
  dump += data;
  return dump; 
}

string XMLData::getType(){
	return "CDATA";
}
