#ifndef _ANALYSEUR_H
#define _ANALYSEUR_H

#include "commun.h"
#include <stdio.h>

extern char * outname;
extern XMLElement * document;
extern FILE * xmlin;
extern int xmldebug;
extern int xmlparse ();
extern FILE * dtdin;
extern int dtddebug;
extern int dtdparse ();


#endif
