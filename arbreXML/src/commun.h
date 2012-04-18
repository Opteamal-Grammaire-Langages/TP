#ifndef COMMUN_H
#define COMMUN_H

using namespace std;
#include <list>
#include <utility>
#include <string>
#include <map>
typedef map<string,string> AttributList;
typedef pair<string,string> Attribut;
typedef list<Attribut> AttList;
typedef pair<string,string> ElementName;
int analyseDtd(char * input);

// Includes des fichiers pour la construction de la structure XML
#include "../../ModelXML/src/XMLElement.h"
#include "../../ModelXML/src/XMLBalise.h"
#include "../../ModelXML/src/XMLData.h"

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif


#endif
