%{
#include "commun.h"
#include <string.h>

void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
   char *s;
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING
%type <s> content children mixed choice card_opt seq cp list_choice list_seq_opt ast_opt list_mixed att_type
 %type <s> enumerate enum_list enum_list_plus item_enum default_declaration
%%

main: dtd_component
    ;

dtd_component
: dtd_component elem {}
| dtd_component dtd_list_opt {}
| /* empty */ {}
;

elem
: ELEMENT IDENT content CLOSE {}
;

content
: children
| mixed
;

children
: choice card_opt
| seq card_opt
;

card_opt
: QMARK {/*$$ = "?";*/ }
| AST  {/*$$ = "*";*/ }
| PLUS {/*$$ = "+";*/ }
| /* empty */ {/*$$ = "";*/ }
;

cp
: children
| IDENT card_opt
;

choice
: OPENPAR cp list_choice CLOSEPAR {} 
;

list_choice
: list_choice PIPE cp {}
| PIPE cp {} 
;

seq
: OPENPAR cp list_seq_opt CLOSEPAR {}
;

list_seq_opt
: list_seq_opt COMMA cp  {/*$$ = strcat(strcat($1, ","), $3);*/}
| /* empty */ {printf("lol\n"); $$ = ""; }
;

mixed
: OPENPAR PCDATA list_mixed CLOSEPAR AST {}
| OPENPAR PCDATA CLOSEPAR ast_opt {}
;

ast_opt
: AST {} 
| /* empty */ {} 
;

list_mixed
: list_mixed PIPE IDENT {}
| PIPE IDENT {}
;

dtd_list_opt
: ATTLIST IDENT att_definition_opt CLOSE {}
;


att_definition_opt
: att_definition_opt attribute {}
| /* empty */ {}
;

attribute
: IDENT att_type default_declaration {}
;

att_type
: CDATA {}
| TOKENTYPE 
| enumerate {} 
;

enumerate
: OPENPAR enum_list_plus CLOSEPAR {}
;

enum_list_plus
: enum_list PIPE item_enum {}
;

enum_list
: item_enum {}
| enum_list PIPE item_enum {}
;

item_enum
: IDENT 
;

default_declaration
: DECLARATION 
| STRING 
| FIXED STRING {}
;
%%
int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


