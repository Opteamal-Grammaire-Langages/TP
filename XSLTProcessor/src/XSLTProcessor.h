/*
 * XLSTProcessor.h
 *
 */

#ifndef XLSTPROCESSOR_H_
#define XLSTPROCESSOR_H_

#include <string>
#include <list>
#include <iostream>

#include "../../ModelXML/src/XMLBalise.h"
#include "../../ModelXML/src/XMLElement.h"
#include "../../ModelXML/src/XMLData.h"
using namespace std;

class XSLTProcessor {

public:

	/*
	Methode qui transforme un document XML a partir d'un document xsl.
	Parametres:
		-docXML: document XML que l'on souhaite transformer
		-xsl: document XSL devant etre applique sur le document xml
		-racine: precise si le pointeur docXML pointe sur la racine du document XML ou non (pour le match "/").
	Retour:
		Une liste contenant le document genere. (la plupart du temps un seul element sera dans cette liste: le noeud racine)
	*/
	static list<XMLElement *> generateXSLXML(XMLBalise * docXML, XMLBalise * xls, bool racine = false);
protected:
	/*
	Methode qui genere le contenu d'un template.
	Parametres:
		-templateMatched: template a generer
		-xsl: document XSL devant etre applique sur le document xml
		-noeudXMLMatched: noeud du document xml qui a matche.
	Retour:
		Le template genere.
	*/
	static list<XMLElement *> generateTemplate(XMLBalise * templateMatched, XMLBalise * xls, XMLBalise * noeudXMLMatched);
	
	/*
	Methode qui genere un element d'un template.
	Parametres:
		-elementXSL: noeud XSL a generer
		-xsl: document XSL devant etre applique sur le document xml
		-xmlMatching: noeud du document xml qui a matche.
	Retour:
		Le template genere.
	*/
	static list<XMLElement *> lookOverXSLToBuildTemplate(XMLBalise * elementXSL, XMLBalise * xls, XMLBalise * xmlMatching);

};

#endif /* XLSTPROCESSOR_H_ */
