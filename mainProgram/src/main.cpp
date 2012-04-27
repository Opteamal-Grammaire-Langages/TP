#include <iostream>
#include <string>
#include <vector>
#include "../../arbreXML/src/commun.h"
#include "../../analyseurSyntaxique/src/commun.h"
#include "../../arbreDTD/src/commun.h"
#include "../../AnalyseurSemantiqueXML/src/Validator.h"
#include "../../XSLTProcessor/src/XSLTProcessor.h"


using namespace std;
enum command {NONE,ANALYSE,MODELIZE,VALIDATE,PROCESS,HELP};
int result = 0;

int process(string infile, string xslfile){
  return 0;
}

int validate(string file, string dtd, bool debug){
  Document * docdef =new Document;
  int ret = modelizeDtd(dtd.c_str(),&docdef,debug);
  if (ret==-1) return -1;
  XMLElement * document = modelizeXml(file.c_str(),NULL,debug);
  Validator val(docdef);
  XMLBalise * balise = dynamic_cast<XMLBalise*> (document);
  if (balise==NULL){
    cout << "Invalid XML document" << endl;
    return -1;
  }
  bool valid=val.validateXML(balise);
  if (valid){
    cout << "valid document" << endl;
  } else {
    cout << "invalid document" << endl;
  }
  delete docdef;
  delete document;
  return 0;
} 
int model(string file, string type, string outputfile, bool debug) {
  const char * out=NULL;
  if (!outputfile.empty()) out=outputfile.c_str();
  if (file.empty()) {
    return -1;
  }
  if (type=="xml" || type=="xsl") {
    XMLElement * document = modelizeXml(file.c_str(),out,debug);
    cout << "XML Model as parsed :\n" << document->toString(0).c_str() <<endl; 
    delete document;
  } else if (type=="dtd"){
    Document * doc =new Document;
    int ret = modelizeDtd(file.c_str(),&doc,debug);
    if (ret==-1) return -1;
    cout << "DTD Model as parsed :\n" << doc->toString().c_str() <<endl;
    delete doc;
  }
  return 0;
}

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
      break;
    case -2 :
      cout << "Error 2, bad command" << endl;
      break;
    default :
      cout << "Error " << error << ", unknown error" << endl;
      break;
  }
}
void displayHelp()
{
  cout << "Synopsis :" << endl;
  cout << "\ttpgl -h" << endl;
  cout << "\ttpgl -A [-v] [-t type] FILENAME" << endl;
  cout << "\ttpgl -M -t type [-v] [-o output] FILENAME" << endl;
  cout << "\ttpgl -V [-v] -d DTD FILENAME" << endl;
  cout << "\ttpgl -P -x XSL FILENAME" <<endl;
  cout << "Commands :" << endl;
  cout << "\t-h / --help : display this help." << endl;
  cout << "\t-A / --analyse : If no type is specified, parse FILENAME as an xml file and check its syntax.\n\
                         If a DOCTYPE declaration is found, the corresponding DTD is parsed as well\n\
                         If -t type is specified, check FILENAME syntax against \"type\" syntax.\n\
                         In this case, if the file is an xml file, don't check the corresponding DTD" << endl;
  cout << "\t-M / --model : Fill and display an memory structure with the input file, type specifies\n\
                          what kind of memory model must be filled" << endl;
  cout << "\t-V / --validate : validate an xml file against the dtd provided" << endl;
  cout << "\t-P / --process\n" << endl;
  cout << "Arguments :" << endl;
  cout << "\t-d / --dtd DTD : specify the dtd to be checked against in case of a validation" << endl;
  cout << "\t-x / --xsl XSL : specify the xsl to be process against in case of a xsl process" << endl;
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
  string output;
  string dtd;
  string xsl;
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
    } else if (args[i]=="-o" || args[i]=="--output") {
      if (args[i+1][0]!='-'){
        output=args[i+1];
        i++; //Don't check the next arg, it must be a file
      } else return -1;
    } else if (args[i]=="-d" || args[i]=="--dtd") {
      if (args[i+1][0]!='-'){
        dtd=args[i+1];
        i++; //Don't check the next arg, it must be a file
      } else return -1;
    } else if (args[i]=="-x" || args[i]=="--xsl") {
      if (args[i+1][0]!='-'){
        xsl=args[i+1];
        i++; //Don't check the next arg, it must be a file
      } else return -1;
    } else if (args[i]=="-A" || args[i]=="--analyze") {
      if (todo==NONE) {
        todo=ANALYSE;
      } else return -2;
    } else if (args[i]=="-H" || args[i]=="-h" || args[i]=="--help") {
      if (todo==NONE) {
        todo=HELP;
      } else return -2;
    } else if (args[i]=="-V" || args[i]=="--validate") {
      if (todo==NONE) {
        todo=VALIDATE;
      } else return -2;

    } else if (args[i]=="-M" || args[i]=="--model") {
      if (todo==NONE) {
        todo=MODELIZE;
      } else return -2;
    } else if (args[i]=="-P" || args[i]=="--process") {
      if (todo==NONE) {
        todo=PROCESS;
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
    case MODELIZE :
      return model(file,type,output,debug);
      break;
    case VALIDATE :
      return validate(file,dtd,debug);
      break;
    case PROCESS :
      return process(file,xsl);
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

