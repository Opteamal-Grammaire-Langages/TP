#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <list>
#include <utility>
#include <string>
// Includes des fichiers pour la structure DTD
typedef pair<string,string> Attribut;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;
int analyseDtd(char * input);
int analyseXml(int argc, char **argv);

// Includes des fichiers pour la construction de la structure XML
//#include "../../ModelXML/src/XMLElement.h"
//#include "../../ModelXML/src/XMLBalise.h"
//#include "../../ModelXML/src/XMLData.h"
//On ne devrait pas en avoir besoin ici, seulement dans la partie arbreXML

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
