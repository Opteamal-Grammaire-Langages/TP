#include "stdio.h"
#include "modeliseurxml.h"

int main(int argc, char **argv)
{
  char * outfile;
  XMLElement * document;
	if (argc<1){
		return -1;
	} else if (argc<2) {
		outfile=NULL;
	} else {
		outfile=argv[2];
	}
  document = modelizeXml(argv[1],outfile,false); 
  printf("Document as parsed : \n%s\n",document->toString(0).c_str());
  return 0;
}

