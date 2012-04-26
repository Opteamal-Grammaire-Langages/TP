#include "commun.h"
#include "stdio.h"
#include "analyseur.h"
int analyseDtd(char * input)
{
  int err;

  //dtddebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne
	dtdin=fopen(input,"r");
	if(dtdin==NULL){
		return -1;
	}

  err = dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n");
  return 0;
}

void dump(const char * toDump)
{
  FILE * out;
  printf("passage dans dump\n");
  if (outname==NULL){
		out=fopen("output.xml","w");
  } else {
		out=fopen(outname,"w");
	}
	fprintf(out,"%s",toDump);
	fclose(out);
}


