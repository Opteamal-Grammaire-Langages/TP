#ifndef COMMUN_H_ANALYSE_SYN
#define COMMUN_H_ANALYSE_SYN

using namespace std;
#include <list>
#include <utility>
#include <string>
// Includes des fichiers pour la structure DTD
typedef pair<string,string> Attribut;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;
int analyseDtd(const char * input,int debug);
int analyseXml(const char * argv, int debug);

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
