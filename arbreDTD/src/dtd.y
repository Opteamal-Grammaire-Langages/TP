%{
#include "commun.h"
#include <string.h>
#include <iostream>

void dtderror(Document ** doc, char *msg);
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
   char *s;
   string *st;
   Element* e; /* element defini dans la DTD */
   DTDattribut *a; /* attribut d'un element */
   Document *d; /* l'objet contenat la structure DTD */
   pair<string, list<DTDattribut*> > *p; /* association nom element - liste attributs */
   list<DTDattribut*> *l;
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING
%type <st> content children mixed choice card_opt seq cp list_choice list_seq_opt ast_opt list_mixed att_type
%type <st> enumerate enum_list enum_list_plus item_enum default_declaration
%type <e> elem
%type <a> attribute
%type <d> dtd_component main
%type <p> dtd_list_opt
%type <l> att_definition_opt

%parse-param {Document ** doc} /* recuperation de la structure DTD */
%%

main: dtd_component {*doc = $1;}
;

dtd_component
: dtd_component elem {$$->addElement($2) /* ajout d'un element a la DTD */;}
| dtd_component dtd_list_opt {$$->addAttributsElement(*($2));} /* ajout d'une paire (nom element, listeAtt)*/
| /* empty */ {$$ = new Document(); /* initialisation de la structure */}
;

elem
: ELEMENT IDENT content CLOSE {$$ = new Element(string($2), *($3)); free($2);}
;

content
: children {$$ = new string(*$1);}
| mixed {$$ = new string(*$1)}
;

children
: choice card_opt {$$ = new string(*$1 + *$2); /* concatenation de la liste des choix et cardinalites */}
| seq card_opt {$$ = new string(*$1 + *$2);}   /* concatenation des sequences et leurs cardinalites */
;

card_opt
: QMARK {$$ = new string("?"); }
| AST  {$$ = new string("*"); }
| PLUS {$$ = new string("+"); }
| /* empty */ {$$ = new string(""); }
;

cp
: children {$$ = new string(*$1);}
| IDENT card_opt {$$ = new string(string($1) + *$2); free($1);}
;

choice
: OPENPAR cp list_choice CLOSEPAR {$$ = new string("(" + *$2 + *$3 + ")");}
;

list_choice
: list_choice PIPE cp {$$ = new string(*$1 + "|" + *$3);}
| PIPE cp {$$ = new string("|"+ *$2); free($2);}
;

seq
: OPENPAR cp list_seq_opt CLOSEPAR {$$ = new string("("+ *$2 + *$3 + ")"); free($2); free($3);}
;

list_seq_opt
: list_seq_opt COMMA cp  {$$ = new string(*$1 + "," + *$3); free($1); free($3);}
| /* empty */ {$$ = new string(""); }
;

mixed
: OPENPAR PCDATA list_mixed CLOSEPAR AST {$$ = new string(string("(") + string("#PCDATA") + *$3 + string(")") + string("*")); free($3);}
| OPENPAR PCDATA CLOSEPAR ast_opt  {$$ = new string(string("(") + string("#PCDATA") + string(")") + *$4); free($4);}
;

ast_opt
: AST  {$$ = new string("*"); }
| /* empty */  {$$ = new string(""); }
;

list_mixed
: list_mixed PIPE IDENT {$$ = new string(*$1 + "|" + string($3)); free($1); free($3);}
| PIPE IDENT {$$ = new string("|" + string($2)); free($2);}
;

dtd_list_opt
: ATTLIST IDENT att_definition_opt CLOSE {$$ = new pair<string, list<DTDattribut*> >(string($2), *($3)); free($2);}
/*creation d'une paire (nom element, liste de ses attributs)*/
;


att_definition_opt
: att_definition_opt attribute {$$ = $1; $$->push_front($2);}
| /* empty */ {$$ = new list<DTDattribut*>();}
;

attribute
: IDENT att_type default_declaration {$$ = new DTDattribut(string($1), *$2, *$3); free($1);}
;

att_type
: CDATA    {$$ = new string("CDATA");}
| TOKENTYPE {$$ = new string($1);}
| enumerate     {$$ = new string(*$1);}
;

enumerate
: OPENPAR enum_list_plus CLOSEPAR  {$$ = new string("(" + *$2 + ")"); free($2);}
;

enum_list_plus
: enum_list PIPE item_enum {$$ = new string(*$1 + "|" + *$3); free($1); free($3);}
;

enum_list
: item_enum               {$$ = new string(*$1); free($1);}
| enum_list PIPE item_enum {$$ = new string(*$1 + "|" + *$3); free($1); free($3);}
;

item_enum 
: IDENT {$$ = new string(string($1)); free($1);}
;

default_declaration
: DECLARATION     {$$ = new string($1);}
| STRING         {$$ = new string($1);}
| FIXED STRING     {$$ = new string("#FIXED" + string($2)); free($2);}
;
%%
int dtdwrap(void)
{
  return 1;
}

void dtderror(Document ** doc, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


