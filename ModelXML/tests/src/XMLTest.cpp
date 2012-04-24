/*
 * XMLTest.cpp
 *
 *  Created on: 3 avr. 2012
 *      Author: mfagno
 */

#include "XMLTest.h"

string XMLTest::testStructure1() {
	XMLBalise elA("A");
	elA.setAutoClosed(false);

	return elA.toString();
}

string XMLTest::testStructure2() {
	XMLBalise * elA = new XMLBalise("A");
	elA->setAutoClosed(false);
	elA->addAttribute("a", "1");
	XMLBalise * elB = new XMLBalise("B");
	XMLData * elBData = new  XMLData("bla");
	elB->addElement((XMLElement *)elBData);

	XMLData * elAData = new XMLData("blum");
	XMLBalise * elC = new XMLBalise("C");
	XMLBalise * elD = new XMLBalise ("D");
	elD->setAutoClosed(true);
	
	elA->addElement(elB);
	elA->addElement(elAData);
	elA->addElement(elC);
	elA->addElement(elD);

	return elA->toString();
}

string XMLTest::testStructure3() {
	XMLBalise * elA = new XMLBalise("A");
	elA->setAutoClosed(false);
	elA->addAttribute("a", "1");
	XMLBalise * elB = new XMLBalise("B");
	XMLData * elBData = new  XMLData("bla");
	elB->addElement((XMLElement *)elBData);

	XMLData * elAData = new XMLData("blum");
	XMLBalise * elC = new XMLBalise("C");
	XMLBalise * elD = new XMLBalise ("D");
	elD->setAutoClosed(true);
	elA->addElement(elB);
	elA->addElement(elAData);
	elA->addElement(elC);
	elA->addElement(elD);

	 return elA->getChildrenTypes();
	 
}

string XMLTest::testStructure4() {
	XMLBalise * xml = new XMLBalise("A");
	xml->setAutoClosed(false);
	xml->addAttribute("a", "1");
	XMLData * elAData = new XMLData("blum");
	xml->addElement(elAData);
	
	cout<<"XML"<<xml->toString()<<endl;
	
	//XSL
	XMLBalise * xsl = new XMLBalise("xsl:template");
	xsl->setAutoClosed(false);
	xsl->addAttribute("match", "A");
	
	cout<<"XSL1"<<xsl->toString()<<endl;
	xsl->getElements().begin();
	cout<<"taille"<<xsl->getElements().size();
	cout<<"Result1"<<xml->match(xsl)<<endl;	
	

	 return "coucou";
}
