#include "stdio.h"
#include "analyseur.h"

int main(int argc, char **argv)
{
  int err;
  //xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne
	if (argc<1){
		return -1;
	} else if (argc<2) {
		outname=NULL;
	} else {
		outname=argv[2];
	}
	xmlin=fopen(argv[1],"r");
	if(xmlin==NULL){
		return -1;
	}
  err = xmlparse();
  if (err != 0){
    printf("Parse ended with %d error(s)\n", err);
    return -1;
  }
	else  printf("Parse ended with success\n");
  printf("Document as parsed : \n%s\n",document->toString(0).c_str());
  return 0;
}

