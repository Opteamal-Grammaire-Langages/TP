#include "XSLTProcessor.h"

list<XMLElement *> XSLTProcessor::generateXSLXML(XMLBalise * docXML,
		XMLBalise * xls, bool racine) {
	list<XMLElement *> generatedXML;

		XMLBalise * templatedMatching = docXML->match(xls, racine); //On recupere si possible match du noeud courrant

		//Si le noeud courrant ne match pas
		if (templatedMatching == 0) {

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

				} else {
					XMLData * data = dynamic_cast<XMLData*>((*it_element));
					if (data != 0) {
						//On copie la data
						XMLData * newData = new XMLData(data->getData());

						generatedXML.push_back(newData);
					} else {
						cout << "ERROR UNEXPECTED: generateXSLXML" << endl;
					}

				}
			}
			// Si un template match
		} else {
			cout<<"match: " + docXML->getName() + "\n";
			generatedXML = generateTemplate(templatedMatching, xls, docXML);
		}


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
		returnBalise->setAttList(elementXSL->getAttributes());
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
		// Balise xsl
		if( elementXSL->getNameSpace().compare("xsl") == 0){

			//Apply templates
			if(elementXSL->getName().compare("apply-templates") == 0){
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
			}
			

			if(elementXSL->getName().compare("value-of") == 0 && elementXSL->getAttributes().find("select") != elementXSL->getAttributes().end() ){
				string baliseToMatch = elementXSL->getAttributes().find("select")->second;
				list<XMLElement *> elementsFils = xmlMatching->getElements();
				
				//Pour tous les fils du noeud xml matche
				for (list<XMLElement *>::iterator it_element = elementsFils.begin();it_element != elementsFils.end(); it_element++) {
					
					XMLElement * child = (*it_element);
					XMLBalise* baliseChild = dynamic_cast<XMLBalise*>(child);
					
					// Si on a une balise XML, on prend les elements data
					if(baliseChild != 0){	

						// Si le nom de la balise correspond
						if( baliseChild->getName().compare(baliseToMatch) == 0){

							list<XMLElement *> elementsFils2 = baliseChild->getElements();
							
							//On recupere tous les contenus des data fils
							for (list<XMLElement *>::iterator it_element2 = elementsFils2.begin();it_element2 != elementsFils2.end(); it_element2++) {
								
								XMLElement * childChild = (*it_element2);
								
								XMLData* dataChildChild = dynamic_cast<XMLData*>(childChild);
								
								//Si on a trouve
								if(dataChildChild != 0){

									XMLData * dataChildChildCpy = new XMLData(dataChildChild->getData());
									returnBalises.push_back(dataChildChildCpy);
								}
							}
						}
					}
				}
			}
			
		//Si on a une balise normale
		}else{
			XMLBalise * child = new XMLBalise(elementXSL->getName(),"",true);
			child->setAttList(elementXSL->getAttributes());
			returnBalises.push_back(child);
		}

	}
	return returnBalises;
}