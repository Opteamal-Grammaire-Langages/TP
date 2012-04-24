#include <iostream>
#include <string>
#include <vector>
#include "../../analyseurSyntaxique/src/commun.h"
using namespace std;
int result = 0;
void analyse(vector<string> args)
{
  if (args[2] == "-t") // analyse precise d'un fichier
  {
    if (args[3] == "dtd")
    {
      result = analyseDtd(args[4].c_str());
    }
    else if (args[3] == "xml")
    {
      result = analyseXml(args[4].c_str());
    }
    else if (args[3] == "xsl")
    {
      // a remplir
    }
  }
  else //analyse complete xml et dtd associee
  {
    result = analyseXml(args[2].c_str());
  }
}
void displayHelp()
{
  cout << "Synopsis :" << endl;
  cout << "\tanalyzer [-a] [-t type] FILENAME\n" << endl;
  cout << "Commands :" << endl;;
  cout << "\t-h / --help : display this help.\n" << endl;
  cout << "\t-a / --analyse : If no type is specified, parse FILENAME as an xml file and check its syntax.\n\
                         If a DOCTYPE declaration is found, the corresponding DTD is parsed as well\n\
                         If -t type is specified, check FILENAME syntax against \"type\" syntax.\n\
                         In this case, if the file is an xml file, don't check the corresponding DTD" << endl;
}
int main(int argc, char **argv)
{
  vector<string> args;
  for(int i=0; i<argc; i++) {
    args.push_back(argv[i]);
  }
  switch(argc){
    case 1:
        cout<<"At least 2 arguments expected"<<endl;
        cout<<"See 'analyzer -h' for more information"<<endl;
      break;
    case 2:
      if(args[1]=="-h" || args[1]=="--help")
      {
        displayHelp();
      }
      else
      {
        displayHelp();
      }
      break;
    default :
      if(args[1]=="-a" || args[1]=="--analyze")
      {
        analyse(args);
      } else {
        displayHelp();
      }
      break;
  }
  return 1;
}
