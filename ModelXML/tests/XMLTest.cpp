/*
 * XMLTest.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#include "XMLTest.h"

string XMLTest::testStructure1() {
	XMLBalise elA("A",false);

	return elA.toString();
}

string XMLTest::testStructure2() {
	XMLBalise * elA = new XMLBalise("A", false);
	elA->addAttribute("a", "1");
	XMLBalise * elB = new XMLBalise("B");
	XMLData * elBData = new  XMLData("bla");
	elB->addElement((XMLElement *)elBData);

	XMLData * elAData = new XMLData("blum");
	XMLBalise * elC = new XMLBalise("C");
	XMLBalise * elD = new XMLBalise ("D", true);
	elA->addElement(elB);
	elA->addElement(elAData);
	elA->addElement(elC);
	elA->addElement(elD);

	return elA->toString();
}

string XMLTest::testStructure3() {
	XMLBalise * elA = new XMLBalise("A", false);
	elA->addAttribute("a", "1");
	XMLBalise * elB = new XMLBalise("B");
	XMLData * elBData = new  XMLData("bla");
	elB->addElement((XMLElement *)elBData);

	XMLData * elAData = new XMLData("blum");
	XMLBalise * elC = new XMLBalise("C");
	XMLBalise * elD = new XMLBalise ("D", true);
	elA->addElement(elB);
	elA->addElement(elAData);
	elA->addElement(elC);
	elA->addElement(elD);

	 return elA->getChildrenTypes();
}
