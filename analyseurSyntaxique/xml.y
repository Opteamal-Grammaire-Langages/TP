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
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND

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
 : START attr_opt	
 | NSSTART	
 ;
attr_opt 
 : attr_opt attr 
 | /*vide*/
 ;	
attr
 : IDENT EQ STRING { printf("%s=%s\n",$1,$3); }
 | IDENT { printf("%s\n",$1) }
 ;

empty_or_content
 : SLASH CLOSE	
 | close_content_and_end CLOSE 
 ;
close_content_and_end
 : CLOSE	content_opt END 
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

