%{
using namespace std;
#include "commun.h"

int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
   AttributList * atList;
   Attribut* at; 
   XMLElement* xe;
   XMLBalise* xb;
   XMLData* xd;
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND
%type <s> name_attr
%type <xb> start
%type <at> attr
%type <atList> attr_list

%%

document
 : declarations_opt xml_element misc_seq_opt 
 ;
misc_seq_opt
 : misc_seq_opt comment
 | /*empty*/
 ;
comment
 : COMMENT
 ;

declarations_opt
 : declaration
 | /*empty*/
 ;
 
declaration
 : DOCTYPE IDENT IDENT STRING CLOSE { printf("%s\n",$4);analyseDtd($4); }
 ;

xml_element
 : start empty_or_content { printf("Fermeture du noeud \n%s\n",$1->toString().c_str()); }
 ;

start
 : START attr_list	{ printf("Nouveau noeud :\n%s\n",$1->second.c_str()); $$=new XMLBalise($1->second.c_str(), "", false); }
 | NSSTART attr_list	{ printf("Nouveau noeud :\n%s:%s\n",$1->first.c_str(), $1->second.c_str()); $$=new XMLBalise($1->second.c_str(), $1->first.c_str(), false); }
 ;

attr_list
 : { printf("Liste d'attributs \n");$$=new AttributList; }
 | attr_list attr {$$->insert(*$2); delete $2;}
 ;

attr
 : name_attr EQ STRING { printf("%s=%s\n",$1,$3); $$=new pair<string,string>($1,$1); } 
 ;	

name_attr
 : IDENT	{ printf("IDENT : %s\n",$1); $$=$1; }
 | NSIDENT	{ printf("NSIDENT : %s\n",$1); $$=$1; }
 ;

empty_or_content
 : SLASH CLOSE	{ printf("Balise autofermante!\n") }
 | close_content_and_end CLOSE 
 ;
close_content_and_end
 : CLOSE content_opt end_or_ns_end 
 ;

end_or_ns_end
 : END	
 | NSEND	{ printf("FIN : %s et %s\n",$1->first.c_str(),$1->second.c_str()); }
 ;

content_opt 
 : content_opt DATA		
 | content_opt comment        
 | content_opt xml_element      
 | /*empty*/         
 ;
%%

int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

