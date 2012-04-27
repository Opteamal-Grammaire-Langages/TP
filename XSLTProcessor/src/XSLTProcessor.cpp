#include "XSLTProcessor.h"

list<XMLElement *> XSLTProcessor::generateXSLXML(XMLBalise * docXML,
		XMLBalise * xls, bool racine) {//TODO cpy attributes
	list<XMLElement *> generatedXML;

	//if (docXML->getAutoClosed() == false) {
		XMLBalise * templatedMatching = docXML->match(xls, racine); //On recupere si possible match du noeud courrant

		//Si le noeud courrant ne match pas
		if (templatedMatching == 0) {

			//On defini la balise a renvoyer
			//XMLBalise * balise = new XMLBalise(docXML->getName(), "", false);
			//generatedXML.push_back(balise);

			list<XMLElement *> elementsFils = docXML->getElements();

			//On parcourt tous les noeuds fils pour remplir cette balise
			for (list<XMLElement *>::iterator it_element = elementsFils.begin();
					it_element != elementsFils.end(); it_element++) {

				XMLBalise* baliseChild = dynamic_cast<XMLBalise*>((*it_element));

				//Si c'est une balise, on fait un appel recursif
				if (baliseChild != 0) {
					list<XMLElement *> childs = generateXSLXML(baliseChild,
							xls);
					generatedXML.insert(generatedXML.end(),childs.begin(),childs.end());
							//balise->addElements(childs);
				} else {
					XMLData * data = dynamic_cast<XMLData*>((*it_element));
					if (data != 0) {
						//On copie la data
						XMLData * newData = new XMLData(data->getData());
						//balise->addElement(newData);
						generatedXML.push_back(newData);
					} else {
						cout << "ERROR UNEXPECTED: generateXSLXML" << endl;
					}
					//balise->addElement(*it_element);
				}
			}
			// Si un template match
		} else {
			cout<<"match: " + docXML->getName() + "\n";
			generatedXML = generateTemplate(templatedMatching, xls, docXML);
		}
		//Balise autoClosed
	//} else {
	//	XMLBalise * baliseClosed = new XMLBalise(docXML->getName(), "", true);
	//	generatedXML.push_back(baliseClosed);
	//}

	return generatedXML;
}

list<XMLElement *> XSLTProcessor::generateTemplate(XMLBalise * templateMatched,
		XMLBalise * xls, XMLBalise * noeudXMLMatched) {
	list<XMLElement *> templateContent;

	//On parcours chaque noeud du template
	list<XMLElement *> elementsFils = templateMatched->getElements();
	for (list<XMLElement *>::iterator it_element = elementsFils.begin();
						it_element != elementsFils.end(); it_element++) {

		XMLBalise* baliseChild = dynamic_cast<XMLBalise*>((*it_element));

		// Si l element est un noeud
		if(baliseChild != 0){
			list<XMLElement *> childs = lookOverXSLToBuildTemplate(baliseChild, xls,noeudXMLMatched);
			templateContent.insert(templateContent.end(),childs.begin(),childs.end());
		}else{
			XMLData* dataChild = dynamic_cast<XMLData*>((*it_element));
			XMLData* data = new XMLData(dataChild->getData());
			if(baliseChild != 0){
				templateContent.push_back(data);
			}else{
				cout<<"ERROR UNEXPECTED : generateTemplate";
			}
		}
	}
	return templateContent;

}

list<XMLElement *> XSLTProcessor::lookOverXSLToBuildTemplate(XMLBalise * elementXSL,
		XMLBalise * xls, XMLBalise * xmlMatching) {
	list<XMLElement *> returnBalises;

	//Si balise non auto closed
	if (elementXSL->getAutoClosed() == false) {

		XMLBalise *returnBalise = new XMLBalise(elementXSL->getName());
		returnBalises.push_back(returnBalise);

		list<XMLElement *> elementsFils = elementXSL->getElements();
		for (list<XMLElement *>::iterator it_element = elementsFils.begin();it_element != elementsFils.end(); it_element++) {

			XMLBalise* baliseChild = dynamic_cast<XMLBalise*>((*it_element));

			//Si on a bien une balise on fait un appel recursif
			if(baliseChild != 0){

				list<XMLElement *> childs = lookOverXSLToBuildTemplate(baliseChild,xls,xmlMatching);
				returnBalise->addElements(childs);
			}else{
				XMLData* dataChild = dynamic_cast<XMLData*>((*it_element));

				if(dataChild != 0){
					XMLData * dat = new XMLData(dataChild->getData());
					returnBalise->addElement(dat);
				}else{
					cout<<"UNEXPECTED ERROR: lookOverXSLToBuildTemplate"<<endl;
				}
			}

		}

	// Si auto closed
	}else{
		// Balise apply templates
		if(elementXSL->getName().compare("apply-templates") == 0 && elementXSL->getNameSpace().compare("xsl") == 0){

			list<XMLElement *> elementsFils = xmlMatching->getElements();
			for (list<XMLElement *>::iterator it_element = elementsFils.begin();it_element != elementsFils.end(); it_element++) {

				XMLElement * child = (*it_element);

				XMLBalise* baliseChild = dynamic_cast<XMLBalise*>(child);

				// Si on a une balise XML, on appelle generateXSLXML
				if(baliseChild != 0){
					list<XMLElement *> bal = generateXSLXML(baliseChild,xls);
					returnBalises.insert(returnBalises.end(),bal.begin(),bal.end());

				//Si on a une data
				}else{
					XMLData* dataChild = dynamic_cast<XMLData*>(child);

					if(dataChild != 0){
						XMLData * dat = new XMLData(dataChild->getData());
						returnBalises.push_back(dat);
					}
				}

			}
			//Si on a une balise
		}else{
			XMLBalise * child = new XMLBalise(elementXSL->getName(),"",true);
			child->setAttList(elementXSL->getAttributes());
			returnBalises.push_back(child);
		}

	}
	return returnBalises;
}

/**
 * Retourne l'arbre de transformation du XML avec le stylesheet XSL
 */
/*
 list<XMLElement *> XSLTProcessor::xlstProcessor(XMLBalise * xml, XMLBalise * xsl) {

 list<XMLElement*> listeFinale;

 // Pour tous les noeuds de la balise xml
 for (list<XMLElement *>::iterator it_element = xml->getElements().begin(); it_element != xml->getElements().end(); it_element++) {

 // On vient verifier s'il existe une balise XSL qui matche avec le fils en cours de la balise XML
 XMLBalise * xmlBaliseFils = dynamic_cast<XMLBalise*>(*it_element);
 XMLBalise * xslBaliseMatch = xmlBaliseFils->match(xsl);//TODO pour les chemeins absolus

 if (xslBaliseMatch != 0) {

 // S'il y a un match, donc une balise du fichier XSLT qui correspond

 // On cree le fichier XML de transformation
 ///XMLBalise * xmlLocalTransforme = new XMLBalise(xslBaliseMatch->getName(), "", false);

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

 XMLBalise * returnValue;
 list<XMLElement *> listeXSL = xsl->getElements();

 for (list<XMLElement *>::iterator it_element = listeXSL.begin(); it_element != listeXSL.end(); it_element++) {
 XMLBalise * xslBalise = dynamic_cast<XMLBalise*>(*it_element);

 //Si il y a un apply template sur la racine
 if (xslBalise != 0 && xslBalise->getName().compare("xsl:apply-templates") == 0 && xslBalise->getAttributes().find("match")->second.compare("/")) {

 xslBalise->get
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
 */

