#include "testXSLTProcessor.h"


/**
 *  Creation d'un arbre XML valide
 */
XMLBalise * testXSLTProcessor::creationArbreXML() {
	/* Creation de l'arbre XML */
	/*string cheminXML = "../../res/xml.xml";
	XMLElement * document = modelizeXml(cheminXML.c_str(), NULL, false);

	XMLBalise * retourBalise = dynamic_cast<XMLBalise *> (document);

	return retourBalise;*/
	return 0;
}

/**
 * Cree un arbre XML valide directement a partir des objets
 */
XMLBalise * testXSLTProcessor::creationArbreXMLConstruit() {
	// Creation d'un arbre XMLBalise

	XMLBalise * elRapport = new XMLBalise("rapport");

	XMLBalise * elTitre = new XMLBalise("titre");
	XMLData * dataTitre = new XMLData("Realiser un compilateur");
	elTitre->addElement(dataTitre);

	XMLBalise * elAuteur = new XMLBalise("auteur");

	XMLBalise * elNom = new XMLBalise("nom");
	XMLData * dataNom = new XMLData("Nino");
	elNom->addElement(dataNom);

	XMLBalise * elPrenom = new XMLBalise("prenom");
	XMLData * dataPrenom = new XMLData("Silverio");
	elPrenom->addElement(dataPrenom);

	elAuteur->addElement(elNom);
	elAuteur->addElement(elPrenom);
	elRapport->addElement(elTitre);
	elRapport->addElement(elAuteur);

	return elRapport;
}

/**
 *  Creation d'un arbre XSL valide
 */
XMLBalise * testXSLTProcessor::creationArbreXSL() {
	/* Creation de l'arbre XML */
	/*string cheminXML = "../../res/xslt.xml";
	XMLElement * document = modelizeXml(cheminXML.c_str(), NULL, false);

	XMLBalise * retourBalise = dynamic_cast<XMLBalise *> (document);

	return retourBalise;*/
	return 0;
}


/**
 * Cree un arbre XML valide directement a partir des objets
 */
XMLBalise * testXSLTProcessor::creationArbreXSLConstruit() {

	// Match Racine
	XMLBalise * elMatchRacine = new XMLBalise("template","xsl");
	elMatchRacine->addAttribute("match", "/");

	XMLBalise * elBody = new XMLBalise("body");
	elBody->addAttribute("id","baliseBody");
	XMLBalise * elHTML = new XMLBalise("html");
	XMLBalise * apply1 = new XMLBalise("apply-templates", "xsl", true);

	elBody->addElement(apply1);
	elHTML->addElement(elBody);
	elMatchRacine->addElement(elHTML);


	// Match Titre
	XMLBalise * elMatchTitre = new XMLBalise("template", "xsl");
	elMatchTitre->addAttribute("match","titre");

	XMLBalise * elTitreH2 = new XMLBalise("h2");
	XMLData * elTitreH2Data = new XMLData("Titre !");
	elTitreH2->addElement(elTitreH2Data);

	elMatchTitre->addElement(elTitreH2);


	// Match Auteur
	XMLBalise * elMatchAuteur = new XMLBalise("template", "xsl");
	elMatchAuteur->addAttribute("match","titre/auteur");

	XMLBalise * elAuteurP = new XMLBalise("p");
	XMLBalise * elAuteurApply = new XMLBalise("apply-templates", "xsl", true);

	elAuteurP->addElement(elAuteurApply);
	elMatchAuteur->addElement(elAuteurP);


	// Racine du XSL
	XMLBalise * xslStyleSheet = new XMLBalise("stylesheet", "xsl");
	xslStyleSheet->addElement(elMatchRacine);
	xslStyleSheet->addElement(elMatchTitre);
	xslStyleSheet->addElement(elMatchAuteur);

	return xslStyleSheet;
}


XMLBalise * testXSLTProcessor::creationHTMLFinalVerification() {


	XMLBalise * h2Balise = new XMLBalise("h2");
	XMLData * h2BaliseData = new XMLData("Titre !");
	h2Balise->addElement(h2BaliseData);

	XMLBalise * pBalise = new XMLBalise ("p");
	XMLData * pBaliseData = new XMLData("Nino");
	XMLData * pBalise2Data = new XMLData("Silverio");
	pBalise->addElement(pBaliseData);
	pBalise->addElement(pBalise2Data);

	XMLBalise * baliseBody = new XMLBalise("body");
	baliseBody->addAttribute("id","baliseBody");
	baliseBody->addElement(h2Balise);
	baliseBody->addElement(pBalise);

	XMLBalise * baliseFinale = new XMLBalise("html");
	baliseFinale->addElement(baliseBody);


	return baliseFinale;
}



/**
 * Teste le bon fonctionnement de la transformation XSLT
 */
bool testXSLTProcessor::testXSLT1() {
/*
// Chargement d'un fichier XSLT
XMLBalise * xsl = creationArbreXSL();

// Chargement d'un fichier XML
XMLBalise * xml = creationArbreXML();

cout << xml->toString() << endl;

// Transformation
list<XMLElement *> listeTransfo;
//listeTransfo = generateXSLXML(xml, xsl);


// Verification si le resultat est bien celui attendu
*/
return true;

}


/**
 * Teste le bon fonctionnement de la transformation XSLT avec un XML et un XSL deja construits
 */
bool testXSLTProcessor::testXSLT2() {

	// Chargement d'un fichier XSLT
	XMLBalise * xsl = creationArbreXSLConstruit();
	cout << "====== XSL ======" << endl;
	cout << xsl->toString() << endl;

	cout << endl;
	// Chargement d'un fichier XML
	XMLBalise * xml = creationArbreXMLConstruit();
	cout << "====== XML ======" << endl;
	cout << xml->toString() << endl;

	// Transformation
	list<XMLElement *> listeTransfo;
	listeTransfo = XSLTProcessor::generateXSLXML(xml, xsl, true);

	cout << "===== HTML TRANSFORME =====" << endl;
	list<XMLElement*>::iterator it;
	for(it = listeTransfo.begin(); it != listeTransfo.end(); it++){
		cout << (*it)->toString() << endl;
	}


	// Verification si le resultat est bien celui attendu
	XMLBalise * htmlCorrige = creationHTMLFinalVerification();

	cout << "====== HTML CORRIGE ===== (ne pas prendre en compte la balise html)" << endl;
	cout << htmlCorrige->toString() << endl;


	return true;

}
