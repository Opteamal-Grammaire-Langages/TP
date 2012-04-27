#ifndef COMMUN_H_MODEL_XML
#define COMMUN_H_MODEL_XML

using namespace std;
#include <list>
#include <utility>
#include <string>
#include <map>
#include "../../ModelXML/src/XMLDocument.h"
#include "../../ModelXML/src/XMLElement.h"
#include "../../ModelXML/src/XMLBalise.h"
#include "../../ModelXML/src/XMLData.h"
#include "../../arbreDTD/src/commun.h"
typedef map<string,string> AttributList;
typedef pair<string,string> Attribut;
typedef list<XMLElement*> ElementList;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;

void dump(XMLDocument * toDump);
XMLDocument* modelizeXml(const char * infile, const char * outfile=NULL, bool debug=false);

// Includes des fichiers pour la construction de la structure XML

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
