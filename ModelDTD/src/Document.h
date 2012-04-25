/*
 * Document.h
 *
 *  Created on: 3 avr. 2012
 *      Author: caucagne1
 *
 *  Cette classe correspond a la structure DTD.
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_
#include "Element.h"
#include "DTDattribut.h"
#include <list>
#include <map>

using namespace std;

class Document {
public:

	Document();
	virtual ~Document();

	/*
	 * Getters
	 */
	list<Element*> getListeElements();
	map<string, list<DTDattribut*> > getMapAttributs();
	list<DTDattribut*> getAttribut(string nomBalise);
	string getDescriptionElement(string elem);

	//methode qui ajoute un element dans la liste des elements de la structure DTD
	void addElement(Element * elem);

	//methode qui ajoute une paire (nom element, liste attributs) dans la map
	void addAttributsElement(pair<string, list<DTDattribut*> >);

	string toString();

private:
	//liste des elements definis dans la DTD
	list<Element*> listeElements;
	// structure qui associe au nom de l'element la liste de ses attributs
	map<string, list<DTDattribut*> > mapAttributs;
};

#endif /* DOCUMENT_H_ */
