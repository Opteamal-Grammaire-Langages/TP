#include "stdio.h"
#include "modeliseurxml.h"
const char * outname;
XMLElement * document;
/*
int modelizeDtd(char * input)
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
*/
XMLElement* modelizeXml(const char * infile, const char * outfile, bool debug)
{
  int err;
  if (debug){
    mxmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
  } else {
    mxmldebug = 0;
  }
	if (infile==NULL){
		return new XMLData("");
	}
  outname=outfile;
  mxmlin=fopen(infile,"r");
	if(mxmlin==NULL){
		return new XMLData("");
	}
  err = mxmlparse();
  if (err != 0){
    printf("Parse ended with %d error(s)\n", err);
    return new XMLData("");
  }
	else  printf("Parse ended with success\n");
  return document;
}

void dump(XMLElement * toDump)
{
  FILE * out;
  printf("dumping document\n");
  document=toDump;
  if (outname==NULL){
		out=fopen("output.xml","w");
  } else {
		out=fopen(outname,"w");
	}
	fprintf(out,"%s",toDump->toString(0).c_str());
	fclose(out);
}


