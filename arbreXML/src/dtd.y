%{

void mdtderror(char *msg);
int mdtdwrap(void);
int mdtdlex(void);
%}

%union { 
   char *s; 
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING
%%

main: dtd_component
    ;

dtd_component
: element
| dtd_list_opt
| /* empty */
;

element
: dtd_component ELEMENT IDENT content CLOSE
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
: QMARK
| AST
| PLUS
| /* empty */
;

cp
: children
| IDENT card_opt
;

choice
: OPENPAR cp list_choice CLOSEPAR
;

list_choice
: list_choice PIPE cp
| PIPE cp
;

seq
: OPENPAR cp list_seq_opt CLOSEPAR
;

list_seq_opt
: list_seq_opt COMMA cp
| /* empty */
;

mixed
: OPENPAR PCDATA list_mixed CLOSEPAR AST
| OPENPAR PCDATA CLOSEPAR ast_opt
;

ast_opt
: AST
| /* empty */
;

list_mixed
: list_mixed PIPE IDENT
| PIPE IDENT
;

dtd_list_opt
: dtd_component ATTLIST IDENT att_definition_opt CLOSE            
;


att_definition_opt
: att_definition_opt attribute
| /* empty */
;

attribute
: IDENT att_type default_declaration
;

att_type
: CDATA    
| TOKENTYPE
| enumerate
;

enumerate
: OPENPAR enum_list_plus CLOSEPAR
;

enum_list_plus
: enum_list PIPE item_enum
;

enum_list
: item_enum               
| enum_list PIPE item_enum
;

item_enum
: IDENT
;

default_declaration
: DECLARATION 
| STRING     
| FIXED STRING 
;
%%
int mdtdwrap(void)
{
  return 1;
}

void mdtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


