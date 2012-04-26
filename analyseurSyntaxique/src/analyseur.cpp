#include "commun.h"
#include "stdio.h"
#include "analyseur.h"
int analyseDtd(const char * input, int debug)
{
  int err;
  dtddebug = debug; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	dtdin=fopen(input,"r");
	if(dtdin==NULL){
		return -1;
	}

  printf("starting dtd parsing\n");
  err = dtdparse();
  if (err != 0){
    printf("Parse ended with %d error(s)\n", err);
    return 2;
  }
  else  printf("Parse ended with success\n");
  return 0;
}

int analyseXml(const char * file, int debug)
{
  int err;
  xmldebug = debug; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
  xmlin=fopen(file,"r");
  if(xmlin==NULL){
    return -1;
  }
  printf("starting xml parsing\n");
  err = xmlparse();
  if (err != 0) 
  {
    printf("Parse ended with %d error(s)\n", err);
    return 1;
  }
	else  printf("Parse ended with success\n");
  return 0;
}

