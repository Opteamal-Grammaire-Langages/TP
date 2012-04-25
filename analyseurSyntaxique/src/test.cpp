#include "commun.h"
int main(int argc, char *argv[])
{
  if (argc<1){
    return -1;
  }
  return analyseXml(argv[1]);
}

