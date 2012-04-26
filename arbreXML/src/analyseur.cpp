#include "stdio.h"
#include "analyseur.h"
char * outname;
XMLElement * document;
int modeliseDtd(char * input)
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

void dump(XMLElement * toDump)
{
  FILE * out;
  document=toDump;
  if (outname==NULL){
		out=fopen("output.xml","w");
  } else {
		out=fopen(outname,"w");
	}
	fprintf(out,"%s",toDump->toString(0).c_str());
	fclose(out);
}


