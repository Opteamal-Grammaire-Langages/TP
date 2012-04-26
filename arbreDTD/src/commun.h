#ifndef COMMUN_H_MODEL_DTD
#define COMMUN_H_MODEL_DTD

using namespace std;
#include <list>
#include <utility>
#include <string>
// Includes des fichiers pour la structure DTD
#include "../../ModelDTD/src/Document.h"
#include "../../ModelDTD/src/Element.h"
#include "../../ModelDTD/src/DTDattribut.h"
typedef pair<string,string> Attribut;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;
int modelizeDtd(const char * input, Document ** doc, bool debug=false);

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
