#include "testValidator.h"

/* Creation de la DTD valide */
Document * testValidator::creationDTD() {
	Document * document = new Document();
	Element * elA = new Element ("A", "B,CDATA,C");
	Element * elC = new Element ("C", "D");
	Element * elB = new Element ("B", "CDATA");
	Element * elD = new Element ("D", "");

	DTDattribut * attA = new DTDattribut ("a", "CDATA", "");
	list<DTDattribut *> listeAtt;
	listeAtt.push_back(attA);
	pair <string, list<DTDattribut *> > paireAttA ("A", listeAtt);

	document->addElement(elA);
	document->addElement(elB);
	document->addElement(elC);
	document->addElement(elD);

	document->addAttributsElement(paireAttA);

	return document;
}

/* Creation de la DTD valide avec balise multiple */
Document * testValidator::creationDTDBaliseMultiple() {
	Document * document = new Document();
	Element * elA = new Element ("A", "B*,CDATA,C");
	Element * elC = new Element ("C", "D");
	Element * elB = new Element ("B", "CDATA");
	Element * elD = new Element ("D", "");

	DTDattribut * attA = new DTDattribut ("a", "CDATA", "");
	list<DTDattribut *> listeAtt;
	listeAtt.push_back(attA);
	pair <string, list<DTDattribut *> > paireAttA ("A", listeAtt);

	document->addElement(elA);
	document->addElement(elB);
	document->addElement(elC);
	document->addElement(elD);

	document->addAttributsElement(paireAttA);

	return document;
}

/* Creation d'une DTD ne comprenant pas d'attribut */
Document * testValidator::creationDTDPasAttribut() {
	Document * document = new Document();
	Element * elA = new Element ("A", "B,CDATA,C");
	Element * elC = new Element ("C", "D");
	Element * elB = new Element ("B", "CDATA");
	Element * elD = new Element ("D", "");

	document->addElement(elA);
	document->addElement(elB);
	document->addElement(elC);
	document->addElement(elD);

	return document;
}

/* Creation d'un arbre XML valide */
XMLBalise * testValidator::creationArbreXML() {
	/* Creation de l'arbre XML */
	XMLBalise * elA = new XMLBalise("A");
		elA->addAttribute("a", "1");
		XMLBalise * elB = new XMLBalise ("B");
			XMLData * elBData = new XMLData ("bla");
			elB->addElement(elBData);

		XMLData * elAData = new XMLData ("blum");
		XMLBalise * elC = new XMLBalise  ("C");
		XMLBalise * elD = new XMLBalise  ("D");
		elD->setAutoClosed(true);
		elA->addElement(elB);
		elA->addElement(elAData);
		elC->addElement(elD);
		elA->addElement(elC);

		return elA;
}

/* Creation d'un arbre XML non valide */
XMLBalise * testValidator::creationArbreXMLNonValide() {
	XMLBalise * elA = new XMLBalise("A");
		elA->addAttribute("a", "1");
		XMLBalise * elB = new XMLBalise ("B");
			XMLData * elBData = new XMLData ("bla");
			elB->addElement(elBData);

		XMLBalise * elC = new XMLBalise  ("C");
		XMLBalise * elD = new XMLBalise  ("D");
		elD->setAutoClosed(true);
		elA->addElement(elB);
		elC->addElement(elD);
		elA->addElement(elC);

		return elA;
}

/* Creation d'un arbre XML valide */
XMLBalise * testValidator::creationArbreXMLBaliseMultiple() {
	/* Creation de l'arbre XML */
	XMLBalise * elA = new XMLBalise("A");
		elA->addAttribute("a", "1");
		XMLBalise * elB = new XMLBalise ("B");
			XMLData * elBData = new XMLData ("bla");
			elB->addElement(elBData);

		XMLData * elAData = new XMLData ("blum");
		XMLBalise * elC = new XMLBalise  ("C");
		XMLBalise * elD = new XMLBalise  ("D");
		elD->setAutoClosed(true);
		elA->addElement(elB);
		elA->addElement(elB);
		elA->addElement(elB);
		elA->addElement(elAData);
		elC->addElement(elD);
		elA->addElement(elC);

		return elA;
}

/**
 * Test Valide : DTD et XML correspondent
 */
bool testValidator::testValidator1() {

	XMLBalise * xmlBalise = creationArbreXML();
	cout << "=== Arbre XML ===" << endl;
	cout << xmlBalise->toString() << endl;

	Document * doc = creationDTD();
	Validator val (doc);
	return val.validateXML(xmlBalise);
}

/**
 * Test non valide : le XML ne respecte pas la DTD
 * Pas d'objet CDATA dans la balise A
 */
bool testValidator::testValidator2() {

	XMLBalise * xmlBalise = creationArbreXMLNonValide();
	cout << "=== Arbre XML ===" << endl;
	cout << xmlBalise->toString() << endl;

	Document * doc = creationDTD();
	Validator val (doc);
	return val.validateXML(xmlBalise);
}

/**
 *	La DTD est vide.
 *	Le test doit planter.
 */
bool testValidator::testValidator3() {

	XMLBalise * xmlBalise = creationArbreXML();
	cout << "=== Arbre XML ===" << endl;
	cout << xmlBalise->toString() << endl;

	Document doc;
	Validator val (&doc);
	return val.validateXML(xmlBalise);
}

/**
 * Le XML comprend un attribut sur la balise A.
 * La DTD ne comprend pas d'attribut sur la balise A.
 * Le test doit planter.
 */
bool testValidator::testValidator4() {

	XMLBalise * xmlBalise = creationArbreXML();
	cout << "=== Arbre XML ===" << endl;
	cout << xmlBalise->toString() << endl;

	Document * doc = creationDTDPasAttribut();
	Validator val (doc);
	return val.validateXML(xmlBalise);
}

/**
 * Le XML est valide et comprend 3 "B"
 * La DTD est valide mais comprend B*
 * Le test doit reussir.
 */
bool testValidator::testValidator5() {
	XMLBalise * xmlBalise = creationArbreXMLBaliseMultiple();
	cout << "=== Arbre XML ===" << endl;
	cout << xmlBalise->toString() << endl;

	Document * doc = creationDTDBaliseMultiple();
	Validator val (doc);
	return val.validateXML(xmlBalise);
}
