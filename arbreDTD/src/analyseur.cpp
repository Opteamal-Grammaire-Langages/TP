#include "commun.h"
#include "stdio.h"
#include "analyseur.h"

int modelizeDtd(const char * input, Document ** doc, bool debug)
{
  int err;
  if (debug){
    ddtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
  } else {
    ddtddebug = 0;
  }
  if (input==NULL){
    return -1;
  }
	ddtdin=fopen(input,"r");
	if(ddtdin==NULL){
		return -1;
	}
  err = ddtdparse(doc);
  if (err != 0){
    printf("Parse ended with %d error(s)\n", err);
    return -1;
  }
  else  printf("Parse ended with success\n");
  return 0;
}

