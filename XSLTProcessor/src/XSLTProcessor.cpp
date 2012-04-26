#include "XSLTProcessor.h"


/**
 * Retourne l'arbre de transformation du XML avec le stylesheet XSL
 */
list<XMLElement *> XSLTProcessor::xlstProcessor(XMLBalise * xml, XMLBalise * xsl) {

	list<XMLElement*> listeFinale;

	// Pour tous les noeuds de la balise xml
	for (list<XMLElement *>::iterator it_element = xml->getElements().begin(); it_element != xml->getElements().end(); it_element++) {

		// On vient verifier s'il existe une balise XSL qui matche avec le fils en cours de la balise XML
		XMLBalise * xmlBaliseFils = dynamic_cast<XMLBalise*>(*it_element);
		XMLBalise * xslBaliseMatch = xmlBaliseFils->match(xsl);
		if (xslBaliseMatch != 0) {

			// S'il y a un match, donc une balise du fichier XSLT qui correspond

			// On cree le fichier XML de transformation
			XMLBalise * xmlLocalTransforme = new XMLBalise(xslBaliseMatch->getName(), "", false);

			// On vient ajouter toutes les balises du fichier XSLT, du match, dans le nouveau fichier XML+XLST
			for (list<XMLElement *>::iterator it_element2 = xslBaliseMatch->getElements().begin(); it_element2 != xslBaliseMatch->getElements().end(); it_element2++) {

				XMLBalise * xslBaliseFils = dynamic_cast<XMLBalise*>(*it_element2);
				// On a affaire a une balise xsl:apply-templates : on doit descendre dans l'arbre XML
				if (xslBaliseFils->getName().compare("xsl:apply-templates") == 0) {

					XMLBalise * sortieProcessor = new XMLBalise(xslBaliseFils->getName(), "", false);
					sortieProcessor->addElements(xlstProcessor(xmlBaliseFils, xsl));
					// Si le retour n'est pas vide, alors on ajoute la XMLBalise au xmlTransforme
					if (!sortieProcessor->getElements().empty()) {
						xmlLocalTransforme->addElement(sortieProcessor);
					}
				}
				else {
					xmlLocalTransforme->addElement(xslBaliseFils);
				}
			}

			// Retourne le XMLTransforme
			listeFinale.push_back(xmlLocalTransforme);
		}
	}

	return listeFinale;
}


XMLBalise * XSLTProcessor::generateXSLXML (XMLBalise * xml, XMLBalise * xsl) {

	list<XMLElement *> listeXSL = xsl->getElements();

	for (list<XMLElement *>::iterator it_element = listeXSL.begin(); it_element != listeXSL.end(); it_element++) {
		XMLBalise * xslBalise = dynamic_cast<XMLBalise*>(*it_element);

		if (xslBalise != 0 && xslBalise->getName().compare("xsl:apply-templates") == 0 && xslBalise->getAttributes().find("match")->second.compare("/")) {

			XMLBalise * xmlLocalTransforme = new XMLBalise(xslBaliseMatch->getName(), "", false);

			// On vient ajouter toutes les balises du fichier XSLT, du match, dans le nouveau fichier XML+XLST
					for (list<XMLElement *>::iterator it_element2 = xslBalise->getElements().begin(); it_element2 != xslBalise->getElements().end(); it_element2++) {

						XMLBalise * xslBaliseFils = dynamic_cast<XMLBalise*>(*it_element2);
						// On a affaire a une balise xsl:apply-templates : on doit descendre dans l'arbre XML
						if (xslBaliseFils->getName().compare("xsl:apply-templates") == 0) {

							XMLBalise * sortieProcessor = new XMLBalise(xslBaliseFils->getName(), "", false);
							sortieProcessor->addElements(xlstProcessor(xslBaliseFils, xsl));
							// Si le retour n'est pas vide, alors on ajoute la XMLBalise au xmlTransforme
							if (!sortieProcessor->getElements().empty()) {
								xmlLocalTransforme->addElements(sortieProcessor);
							}
						}
						else {
							xmlLocalTransforme->addElement(xslBaliseFils);
						}
					}









		}
		else {
			XMLBalise * xmlBalise = new XMLBalise(xml->getName(), "", false);
			xmlBalise->addElements(xlstProcessor(xml, xsl));
		}
	}

}
