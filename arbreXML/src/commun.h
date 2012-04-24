#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <list>
#include <utility>
#include <string>
#include <map>
#include "../../ModelXML/src/XMLElement.h"
#include "../../ModelXML/src/XMLBalise.h"
#include "../../ModelXML/src/XMLData.h"
typedef map<string,string> AttributList;
typedef pair<string,string> Attribut;
typedef list<XMLElement*> ElementList;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;
int analyseDtd(char * input);
void dump(const char * toDump);

// Includes des fichiers pour la construction de la structure XML

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
