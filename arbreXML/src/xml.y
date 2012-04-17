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
   XMLElement* xe;
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND
%type <s> name_attr
//%type <xe> element

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
 : start empty_or_content 
 ;
start
 : START attr_opt	{ printf("%s et %s\n",$1->first.c_str(),$1->second.c_str()); $$=$2; $$=new XMLBalise($1->second.c_str(), "", true); }
 | NSSTART attr_opt	{ printf("%s et %s\n",$1->first.c_str(),$1->second.c_str()); $$=$2; $$=new XMLBalise($1->second.c_str(), $1->first.c_str(), true); }
 ;
attr_opt 
 : attr_opt name_attr EQ STRING { printf("%s=%s\n",$1,$3);  }  //{ /*rien pour l'instant*/ }
 | /*vide*/
 ;	

name_attr
 : IDENT	{ printf("%s\n",$1); $$-> }
 | NSIDENT	{ printf("%s\n",$1); }
 ;

empty_or_content
 : SLASH CLOSE	
 | close_content_and_end CLOSE 
 ;
close_content_and_end
 : CLOSE	content_opt end_or_ns_end 
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

