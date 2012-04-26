#ifndef _ANALYSEUR_H
#define _ANALYSEUR_H

#include <stdio.h>

extern FILE * dxmlin;
extern int dxmldebug;
extern int dxmlparse ();
extern FILE * ddtdin;
extern int ddtddebug;
extern int ddtdparse (Document ** doc);


#endif
