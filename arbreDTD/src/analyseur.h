#ifndef _ANALYSEUR_H
#define _ANALYSEUR_H

#include <stdio.h>

extern FILE * xmlin;
extern int xmldebug;
extern int xmlparse ();
extern FILE * dtdin;
extern int dtddebug;
extern int dtdparse (Document ** doc);


#endif
