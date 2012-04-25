#include "commun.h"
#include "stdio.h"
#include "analyseur.h"
int analyseDtd(char * input)
{
  int err;

  dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	dtdin=fopen(input,"r");
	if(dtdin==NULL){
		return -1;
	}

  err = dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n");
  return 0;
}

int analyseXml(int argc, char **argv)
{
  int err;
  xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
	if (argc<1){
		return -1;
	}
	xmlin=fopen(argv[1],"r");
	if(xmlin==NULL){
		return -1;
	}
  err = xmlparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
	else  printf("Parse ended with success\n");
  return 0;
}

