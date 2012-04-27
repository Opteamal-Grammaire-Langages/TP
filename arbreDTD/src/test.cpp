#include <stdio.h>
#include "commun.h"

int main(int argc, char **argv)
{
	Document * doc = new Document();
  modelizeDtd(argv[1], &doc);
  printf("%s\n",doc->toString().c_str());
  delete(doc);
}

