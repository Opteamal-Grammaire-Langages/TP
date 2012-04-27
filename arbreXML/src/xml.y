%{
using namespace std;
#include "commun.h"

int mxmlwrap(void);
void mxmlerror(char *msg);
int mxmllex(void);

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
   AttributList * atList;
   Attribut* at; 
   ElementList * xeList;
   XMLElement* xe;
   XMLBalise* xb;
   XMLData* xd;
   XMLDocument * xdoc;
   Document* decl;
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND
%type <s> name_attr
%type <xb> start xml_element special
%type <at> attr
%type <atList> attr_list
%type <xeList> empty_or_content close_content_and_end content_opt specials_opt
%type <decl> declaration declarations_opt
%type <xdoc> document

%%

document
 : specials_opt declarations_opt xml_element misc_seq_opt { $$=new XMLDocument(); 
  $$->setSpecialsList($1); $$->setDoctype($2); $$->setChild($3); dump($$);} 
 ;
 
misc_seq_opt
 : misc_seq_opt comment
 | /*empty*/
 ;
 
comment
 : COMMENT
 ;
 
specials_opt
 : {$$=new list<XMLElement *>; }
 | specials_opt special {$1->push_back($2); $$=$1;}
 ;
 
special
 : STARTSPECIAL attr_list CLOSESPECIAL { $$=new XMLBalise($1->second.c_str(), "", true,true); $$->setAttList($2); }
 ;
 
declarations_opt
 : declaration {$$=$1;}
 | /*empty*/ {$$=NULL;}
 ;
 
declaration
 : DOCTYPE IDENT IDENT STRING CLOSE { Document* doc = new Document; modelizeDtd($4, &doc); $$=doc; }
 ;

xml_element
 : start empty_or_content { $2==0 ? $1->setAutoClosed(true) : $1->setElementList($2);  $$=$1; }
 ;

start
 : START attr_list	{ /*printf("Nouveau noeud :\n%s\n",$1->second.c_str());*/ $$=new XMLBalise($1->second.c_str(), "", false); $$->setAttList($2); }
 | NSSTART attr_list	{ /*printf("Nouveau noeud :\n%s:%s\n",$1->first.c_str(), $1->second.c_str());*/ $$=new XMLBalise($1->second.c_str(), $1->first.c_str(), false); $$->setAttList($2); }
 ;

attr_list
 : { /*printf("Liste d'attributs \n");*/$$=new AttributList; }
 | attr_list attr {$$->insert(*$2); delete $2;}
 ;

attr
 : name_attr EQ STRING { /*printf("%s=%s\n",$1,$3);*/ $$=new pair<string,string>($1,$3); } 
 ;	

name_attr
 : IDENT	{ /*printf("IDENT : %s\n",$1);*/ $$=$1; }
 | NSIDENT	{ /*printf("NSIDENT : %s\n",$1);*/ $$=$1; }
 ;

empty_or_content
 : SLASH CLOSE	{ /*printf("Balise autofermante!\n");*/ $$=0;}
 | close_content_and_end CLOSE { $$=$1; }
 ;
close_content_and_end
 : CLOSE content_opt end_or_ns_end { $$=$2; }
 ;

end_or_ns_end
 : END	
 | NSEND	{ /*printf("FIN : %s et %s\n",$1->first.c_str(),$1->second.c_str());*/ }
 ;

content_opt 
 : { $$=new ElementList }/*empty*/         
 | content_opt DATA	{ $$->push_back(new XMLData($2)); }	
 | content_opt COMMENT { /*printf("Ignoring comment : %s\n",$2);*/ }
 | content_opt xml_element { $$->push_back($2); }     
 ;
%%

int mxmlwrap(void)
{
  return 1;
}

void mxmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

