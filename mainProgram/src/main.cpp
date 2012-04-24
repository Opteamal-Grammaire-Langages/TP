#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../ModelXML/src/XMLBalise.h"
#include "../analyseurSyntaxique/src/analyseur.h"

using namespace std;

int main(int argc, char **argv)
{

	switch(argc){
		case 1:
				cout<<"At least 2 arguments expected"<<endl;
				cout<<"See 'analizer -h' for more information"<<endl;
			break;
		case 2:
			if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		  {

		  }
		  else
		  {

		  }
			break;

	}

  return 1;
}
