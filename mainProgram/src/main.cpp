#include <iostream>
#include <string>
#include <vector>
#include "../../analyseurSyntaxique/src/commun.h"
using namespace std;
enum command {NONE,ANALYSE,HELP};
int result = 0;

int analyze(string file, string type="", bool debug=false)
{
  if (file.empty())
  {
    return -1;
  }
  if (type == "dtd")
  {
    result = analyseDtd(file.c_str(),debug);
    result != 0 ? cout << "DTD analyze failed" << endl : cout << "DTD analyze succeded" << endl;  
  }
  else if (type == "xml")
  {
    result = analyseXml(file.c_str(),debug);
    result != 0 ? cout << "XML analyze failed" << endl : cout << "XML analyze succeded" << endl;  
  }
  else if (type == "xsl")
  {
    // a remplir
  }
  else if (type=="") //analyse complete xml et dtd associee
  {
    result = analyseXml(file.c_str(),debug);
    result != 0 ? cout << "XML/DTD analyze failed" << endl : cout << "XML/DTD analyze succeded" << endl;  
  }
  else 
  {
    return -1;
  }
  return 0;
}
void displayError(int error)
{
  switch (error){
    case -1 :
      cout << "Error 1, bad arguments" << endl;
    case -2 :
      cout << "Error 2, bad command" << endl;
    default :
      cout << "Error " << error << ", unknown error" << endl;
      break;
  }
}
void displayHelp()
{
  cout << "Synopsis :" << endl;
  cout << "\tanalyzer [-h]" << endl;
  cout << "\tanalyzer [-a] [-v] [-t type] FILENAME" << endl;
  cout << "Commands :" << endl;
  cout << "\t-h / --help : display this help." << endl;
  cout << "\t-a / --analyse : If no type is specified, parse FILENAME as an xml file and check its syntax.\n\
                         If a DOCTYPE declaration is found, the corresponding DTD is parsed as well\n\
                         If -t type is specified, check FILENAME syntax against \"type\" syntax.\n\
                         In this case, if the file is an xml file, don't check the corresponding DTD" << endl;
  cout << "Options :" << endl;
  cout << "\t-t / --type {xml,dtd,xsl} : specify the type of FILENAME" << endl;
  cout << "\t-v / --verbose" << endl;
}

int parseLine(vector<string> args){
  //The idea is that in this function we only set the command to be executed, its arguments 
  //and check wether the command is syntaxically correct. This function however remains 
  //command agnostic, it is then up to the functions dedicated to each command to check whether
  //the arguments make any sense.
  bool debug=false;
  string type;
  command todo=NONE;
  string file;
  //Set arguments :
  for (unsigned int i=1; i<args.size(); i++){
    if (args[i]=="-v" || args[i]== "--verbose"){
      debug=true;
    } else if (args[i]=="-t" || args[i]=="--type") {
      if (args[i+1][0]!='-'){
        type=args[i+1];
        i++; //Don't check the next arg, it must be a type
      } else return -1;
    } else if (args[i]=="-a" || args[i]=="--analyze") {
      if (todo==NONE) {
        todo=ANALYSE;
      } else return -2;
    } else if (args[i]=="-h" || args[i]=="--help") {
      if (todo==NONE) {
        todo=HELP;
      } else return -2;
    } else if (i==args.size()-1 && args[i][0]!='-') {
      file=args[i];
    }
  }
  
  //Execute the command :
  switch (todo){
    case HELP :
      displayHelp();
      break;
    case ANALYSE :
      return analyze(file,type,debug);
      break;
    default :
      displayHelp();
      break;
  }
  return 0;
}

int main(int argc, char **argv)
{
  vector<string> args;
  for(int i=0; i<argc; i++) {
    args.push_back(argv[i]);
  }
  int ret = parseLine(args);
  if (ret!=0){
    displayError(ret);
    return -1;
  }
  /*
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
  */
  return 1;
}

