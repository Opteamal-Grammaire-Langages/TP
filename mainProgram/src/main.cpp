#include <iostream>
#include <string>

using namespace std;
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
  string  * args = new string[argc];
  for(int i=0; i<argc; i++) {
    args[i].append(argv[i]);
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
        displayHelp();
      break;

  }
  delete[] args;
  return 1;
}
