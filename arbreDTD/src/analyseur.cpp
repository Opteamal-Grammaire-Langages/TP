#include "commun.h"
#include "stdio.h"
#include "analyseur.h"
#include <iostream>

int analyseDtd(char * input, Document ** doc)
{
  int err;

  ddtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	ddtdin=fopen(input,"r");
	if(ddtdin==NULL){
		return -1;
	}

  err = ddtdparse(doc);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n");
  return 0;
}

int main(int argc, char **argv)
{
	Document * doc = new Document();
  analyseDtd(argv[1], &doc);
  cout<<doc->toString();
  delete(doc);
}

