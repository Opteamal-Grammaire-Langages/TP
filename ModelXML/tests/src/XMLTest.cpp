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
	
	XMLBalise * xml2 = new XMLBalise("B");
	xml2->setAutoClosed(false);
	xml2->addAttribute("a", "1");
	XMLData * elAData2 = new XMLData("blum");
	xml2->addElement(elAData2);
	
	//cout<<"XML"<<endl<<xml->toString()<<endl;
	
	//XSL
	XMLBalise * xsl = new XMLBalise("xslDocument");
	XMLBalise * xsltemplate = new XMLBalise("xsl:template");
	xsl->setAutoClosed(false);
	xsltemplate->addAttribute("match", "A");
	xsl->addElement((XMLElement *)xsltemplate);
	
	//cout<<"XSL1"<<endl<<xsl->toString()<<endl;

	//cout<<"Result1"<<xml->match(xsl)<<" "<<true<<endl;	

	if(xml->match(xsl) != 0 && xml->match(xsl)->getName() == "xsl:template" && xml2->match(xsl) == 0){
		return "TEST 4 succed";
	}else{
		return "TEST 4 failed!!";
	}
	 
}
