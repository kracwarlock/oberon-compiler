%error-verbose
%token SEMIC COMMA COLON RIGHTBRAC LEFTBRAC DOTSYM LSQBR RSQBR LCBR RCBR CARR
%token EQ_COMP UNEQ
%token TILDA ASSIGN DOTDOT
%token REPEAT UNTIL FOR TO BY DOCASE END
%token WHILE IF_COND THEN ELSEIF ELSE CASE_COND OF
%token STRLEN STRCAT STRCMP STRREV STRCPY NEW
%token ARRAY RECORD SET BEG CONST EXIT
%token IMPORT LOOP MODULE NIL
%token POINTER PROCEDURE RETURN TYPE
%token VAR WITH ABS ODD LEN LSL ASR ROR FLOOR FLT ORD CHR LONG SHORT 
%token INC DEC INCL EXCL COPY ASSERT PACK UNPK
%token BOOLEAN_TYPE CHAR_TYPE INTEGER_TYPE LONGREAL_TYPE REAL_TYPE
%token BOOLEAN_VAL CHAR_VAL INTEGER_VAL REAL_VAL STRING_VAL IDENT

%token NUM OPR

%nonassoc EQ_COMP  UNEQ  LT  LE  GT  GE  IN  IS
%left PLUS_SYM  MINUS_SYM  OR
%left MULTIPLY_SYM  DIVIDE_SYM  DIV  MOD  AND_SYM OR_SYM

%{

#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "symbol_table.h"

AstNode *ast_head;

SymbolTable symbolTable;

owner_list *own;

tableEntry *owner_func;

type_EntryTable *p;

int currentScope = 0;
int scopeCount = 5;
int order = 0;

int passType = VAL;

#define NULL 0

void yyerror(const char *);
int yylex(void);

extern char * yytext; 

%}

%union
{
  int         int_value;
  char*       str_value;
  type_tableEntry* type_value;
  AstNode*    node;
}

%type <node> cast_away
%type <node> ident
%type <node> Factor
%type <node> Designator
%type <node> Element_List
%type <node> Expr_List
%type <node> Set
%type <node> optSuffix
%type <node> Expr
%type <node> Element
%type <node> Stat_Block
%type <node> Statement
%type <node> Statement_Sequence
%type <node> Statement_Aux
%type <node> Else
%type <node> Else_If_Block
%type <node> Case_Parameters
%type <node> Case_Single
%type <node> Case_Expression
%type <node> Case_Expression_List

%type <type_value> Type;
%type <str_value> Const_Expr;
%type <type_value> Qualident;

%%

// Defining Module and all other blocks in a Oberon File

Module:
    cast_away Main_Block END ident DOTSYM     
    {
      if (strcmp($1->node_value,$4->node_value) != 0) {
        printf("Different Names Used in ident in begin and end",$1->node_value);
      }
    }
    ;

cast_away:
    MODULE ident SEMIC  
    {
      $$ = $2;
    }
    ;

Main_Block:
       Import_Modules Decl_Seq Stat_Block   {printf("Import_Modules Decl_Seq Stat_Block\n");}
    ;

Import_Modules: 
    IMPORT Import_Modules_List SEMIC    {changeVariableType(&symbolTable,NULL,MODULE_VALUE); }
    |                                   {printf("IMPORT Import_Modules_List SEMIC_nothing\n");}
    ;

Import_Modules_List: 
    Import_Modules_List COMMA Import    {printf("Import_Modules_List COMMA Import\n");}
    | Import   {printf("Import\n");}
    ;

Import:
    ident ASSIGN ident { addSymbolTableEntry(&symbolTable, createTableEntry($1->node_value, NULL, NULL, IDENTIFIER, 0, NULL, 0,0,NULL,NULL)); }
    | ident
    ;

Stat_Block:
    BEG Statement_Sequence     { ast_head = makeNode(OPR, "BEG", NOTSET, VAL, NULL, $2);}
    |                          { ast_head = NULL;}
    ;

Statement_Sequence:
    Statement SEMIC Statement_Sequence  { $$ = makeNode(OPR, ";", NOTSET, VAL, $1, $3);}
    | Statement SEMIC                   { $$ = makeNode(OPR, ";", NOTSET, VAL, NULL, $1);}
    ;

Statement    : 
  Designator ASSIGN Expr  { $$ = makeNode(OPR, ":=", NOTSET, VAL, $1 , $3);}
| Designator              { $$ = $1;}
| IF_COND Expr THEN Statement_Sequence Else_If_Block Else END
  { 
    $$ = makeNode(OPR, "IF", NOTSET, VAL, $2 , makeNode(OPR, "THEN", NOTSET, VAL, $4 , makeNode(OPR, "REM_ELSE", NOTSET, VAL, $5 , $6) ));
  }
| CASE_COND Expr OF Case_Parameters Else END 
{
  $$ = makeNode(OPR, "CASE", NOTSET, VAL, $2 , makeNode(OPR, "CASE_PARAMS", NOTSET, VAL, $4, makeNode(OPR, "ELSE", NOTSET, VAL, NULL, $5))); 
}
| WHILE Expr DOCASE Statement_Sequence END      
{
  $$ = makeNode(OPR, "WHILE", NOTSET, VAL, $2 , makeNode(OPR, "DOCASE_WHILE", NOTSET, VAL, NULL, $4));
}
| REPEAT Statement_Sequence UNTIL Expr 
{
  $$ = makeNode(OPR, "REPEAT", NOTSET, VAL, $2 , makeNode(OPR, "UNTIL_REPEAT", NOTSET, VAL, NULL, $4)); 
}
| FOR ident Statement_Aux             
{ 
  $$ = makeNode(OPR, "FOR", NOTSET, VAL, $2 , $3);
}
| LOOP Statement_Sequence END         
{
 $$ = makeNode(OPR, "LOOP", NOTSET, VAL, NULL, $2);
}
| EXIT                                
{
 $$ = makeNode(OPR, "EXIT", NOTSET, VAL, NULL, NULL); 
}
| RETURN Expr                         
{ 
  $$ = makeNode(OPR, "RETURN", NOTSET, VAL, NULL, $2);
}
| RETURN                              
{ 
  $$ = makeNode(OPR, "RETURN", NOTSET, VAL, NULL, NULL);
}
|                                     
{ 
  $$ = NULL; 
}
;

Statement_Aux :
ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END  
{
 $$ = makeNode(OPR, "ASSIGN_FOR", NOTSET, VAL, $2 , makeNode(OPR, "TO_FOR", NOTSET, VAL, $4, makeNode(OPR, "BY_FOR", NOTSET, VAL, $6, makeNode(OPR, "DO_FOR", NOTSET, VAL, $8, NULL ) ) )); 
} 
| ASSIGN Expr TO Expr DOCASE Statement_Sequence END     
{
$$ = makeNode(OPR, "ASSIGN_FOR", NOTSET, VAL, $2 , makeNode(OPR, "TO_FOR", NOTSET, VAL, $4, makeNode(OPR, "DO_FOR", NOTSET, VAL, $6 , NULL ))); 
}
;

Expr         : 
/* Relations */
  Expr EQ_COMP Expr       { $$ = makeNode(OPR, "=", NOTSET, VAL, $1, $3); }
| Expr UNEQ Expr          { $$ = makeNode(OPR, "#", NOTSET, VAL, $1, $3); }
| Expr LT Expr            { $$ = makeNode(OPR, "<", NOTSET, VAL, $1, $3); }
| Expr LE Expr            { $$ = makeNode(OPR, "<=", NOTSET, VAL, $1, $3); }
| Expr GT Expr            { $$ = makeNode(OPR, ">", NOTSET, VAL, $1, $3); }
| Expr GE Expr            { $$ = makeNode(OPR, ">=", NOTSET, VAL, $1, $3); }
| Expr IN Expr            { $$ = makeNode(OPR, "IN", NOTSET, VAL, $1, $3); }
| Expr IS Expr            { $$ = makeNode(OPR, "IS", NOTSET, VAL, $1, $3); }
// | PLUS_SYM Expr %prec UPLUS             // have to take a look at this...
// | MINUS_SYM Expr %prec UMINUS
| Expr PLUS_SYM Expr           { $$ = makeNode(OPR, "+", NOTSET, VAL, $1, $3); }
| Expr MINUS_SYM Expr          { $$ = makeNode(OPR, "-", NOTSET, VAL, $1, $3); }
| Expr OR Expr                 { $$ = makeNode(OPR, "OR", NOTSET, VAL, $1, $3); }
| Expr MULTIPLY_SYM Expr       { $$ = makeNode(OPR, "*", NOTSET, VAL, $1, $3); }
| Expr DIVIDE_SYM Expr         { $$ = makeNode(OPR, "/", NOTSET, VAL, $1, $3); }
| Expr DIV Expr                { $$ = makeNode(OPR, "DIV", NOTSET, VAL, $1, $3); }
| Expr MOD Expr                { $$ = makeNode(OPR, "MOD", NOTSET, VAL, $1, $3); }
| Expr AND_SYM Expr            { $$ = makeNode(OPR, "&", NOTSET, VAL, $1, $3); }
| Factor                       { $$ = $1;}
;

Factor       : 
  Designator    {printf("Designator\n");}
| BOOLEAN_VAL   { $$ = makeNode(NUM, yytext, BOOLEAN, VAL, NULL, NULL); }
| REAL_VAL      { $$ = makeNode(NUM, yytext, REAL, VAL, NULL, NULL); }
| CHAR_VAL      { $$ = makeNode(NUM, yytext, CHAR, VAL, NULL, NULL); }
| INTEGER_VAL   { $$ = makeNode(NUM, yytext, INTEGER, VAL, NULL, NULL); }
| NIL           { $$ = makeNode(NUM, yytext, NO, VAL, NULL, NULL); }
| Set           { $$ = $1; }      
| LEFTBRAC Expr RIGHTBRAC   { $$ = makeNode(OPR, "()", NOTSET, VAL, NULL , $2); }
| TILDA Factor  { $$ = makeNode(OPR, "~", NOTSET, VAL, NULL , $2); }
;

Designator   : 
  ident optSuffix     { $$ = make_new_node($1,$2);}
;

optSuffix :
  DOTSYM ident optSuffix  { $$ = makeNode(OPR, ".", NOTSET, VAL, NULL, make_new_node($2,$3));}
| LSQBR Expr_List RSQBR  optSuffix  { $$ = makeNode(OPR, "[]", NOTSET, VAL, NULL, make_new_node($2,$4));}
| CARR  optSuffix    { $$ = makeNode(OPR, "^", NOTSET, VAL, NULL, $2);}
| LEFTBRAC Expr_List RIGHTBRAC optSuffix   { $$ = makeNode(OPR, "()", NOTSET, VAL, NULL, make_new_node($2,$4));}
|   { $$ = NULL;}
;

Expr_List     : 
  Expr                                          { $$ = $1; }
| Expr COMMA Expr_List                          { $$ = makeNode(OPR, ",", NOTSET, VAL, $1, $3); }
;              

Set          : 
  LCBR Element_List RCBR                        { $$ = $2; }
;

Element_List :
  Element COMMA Element_List                    { $$ = makeNode(OPR, ",", NOTSET, VAL, $1, $3); }
| Element                                       { $$ = $1; }
;

Element      : 
  Expr                                          { $$ = $1; }
| Expr DOTDOT Expr                              { $$ = makeNode(OPR, "..", NOTSET, VAL, $1, $3); }
;

Else_If_Block:
  ELSEIF Expr THEN Statement_Sequence Else_If_Block     { $$ = makeNode(OPR, "ELSEIF", NOTSET, VAL, $2 , makeNode(OPR, "ELSEIF_AUX", NOTSET, VAL, $4 , $5)); }
|                                                       { $$ = NULL; }
;

Else:
  ELSE Statement_Sequence                        { $$ = makeNode(OPR, "ELSE", NOTSET, VAL, NULL, $2);}
|                                                { $$ = NULL; }
;

Case_Parameters:
  Case_Single                                     { $$ = $1; }
| Case_Single OR_SYM Case_Parameters              { $$ = makeNode(OPR, "OR", NOTSET, VAL, $1 , $3);}
;

Case_Single: 
  Case_Expression_List COLON Statement_Sequence   { $$ = makeNode(OPR, ";", NOTSET, VAL, $1, $3); }
|                                                 { $$ = NULL;}
;

Case_Expression_List:                // Case label list beacuse of the expression matching could be to a integer but also to a list of integers or list of expressions
  Case_Expression                                 { $$ = $1; }
| Case_Expression COMMA Case_Expression_List      { $$ = makeNode(OPR, ",", NOTSET, VAL, $1 , $3);}
;

Case_Expression: 
  Expr                                            { $$ = $1; }
| Expr DOTDOT Expr                                { $$ = makeNode(OPR, "..", NOTSET, VAL, $1 , $3);}
;


// This section declares the various sections of the declaration Part...
// In this part there are two types of sections namely:  Data declation list and procedure declaration list.

Decl_Seq: 
  Data_List Proc_List  {printf("Data_List Proc_List\n");}
;

Data_List:
  CONST Const_List Data_List  {printf("CONST Const_List Data_List\n");}
| TYPE  Type_List  Data_List      {printf("TYPE  Type_List  Data_List\n");}
| VAR   Var_List Data_List        {printf("VAR   Var_List Data_List\n");}
| {printf("Data_List_Nothing\n");}
;


// In this region we are declaring various types of declaration namely "const declaration,var decaration and type declaration"

Const_List :
  Identifier_List EQ_COMP Const_Expr SEMIC Const_List {printf("Identifier_List EQ_COMP Const_Expr SEMIC Const_List\n");}
|                                                      {printf("Const_List_Nothing\n");}
;

Type_List : 
  Identifier_List EQ_COMP Type {changeVariableType(&symbolTable, $3,TYPE_VALUE); } SEMIC Type_List      
|
;

Var_List  : 
  Identifier_List COLON Type                        {changeVariableType(&symbolTable, $3,VAR_VALUE); } SEMIC Var_List
|                                                   {printf("Var_List_Nothing\n");}
;


Type: 
Qualident                           
{ 
 insert_last(p,create_typeEntry(QUALIDENT_TYPE,NULL,NULL));
 $$ = p->last;
 remove_last(p);
}
| INTEGER_TYPE                      
{ 
  insert_last(p,create_typeEntry(INTEGER,NULL,NULL));
  $$ = p->last; 
  remove_last(p);
}
| CHAR_TYPE                         
{ 
  insert_last(p,create_typeEntry(CHAR,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| BOOLEAN_TYPE                      
{ 
  insert_last(p,create_typeEntry(BOOLEAN,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| REAL_TYPE                         
{ 
  insert_last(p,create_typeEntry(REAL,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| LONGREAL_TYPE
{
  insert_last(p,create_typeEntry(LONGREAL,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| ARRAY 
  {
    insert_last(p,create_typeEntry(ARRAY_TYPE,NULL,NULL));
  } 
  OF Type 
  {
    $$ = p->last;
    remove_last(p);
  }
| ARRAY
   {
      insert_last(p,create_typeEntry(ARRAY_TYPE,NULL,NULL));
   } 
   Const_Expr_List OF Type    
   { 
      $$ = p->last;
      remove_last(p);
   }
| RECORD 
  {
    insert_last(p,create_typeEntry(RECORD_TYPE,NULL,NULL));
  }
  Field_List END             
  {
    $$ = p->last;
    remove_last(p);
  }
| POINTER 
  {
    insert_last(p,create_typeEntry(POINTER_TYPE,NULL,NULL));
  }
  TO Type                   
  { 
    $$ = p->last;
    remove_last(p);
  }
| PROCEDURE
{
  insert_last(p,create_typeEntry(PROC_TYPE,NULL,NULL));
}
Formal_Pars_Dec             
{ 
  $$ = p->last;
  remove_last(p);
}
| SET                               
{
 insert_last(p,create_typeEntry(SET_TYPE,NULL,NULL));
 $$ = p->last;
 remove_last(p);
}
;

Qualident    :             
  ident DOTDOT ident 
{
  if (module_lookup_bool(&symbolTable,$1->node_value)){
    $$ = type_lookup(&symbolTable,$3->node_value,currentScope);
  }
  else{
    printf("module lookup failed");
  }
}
| ident 
{
  $$ = type_lookup(&symbolTable,$1->node_value,currentScope);
}                 
;

Const_Expr    :                                   
  Expr                                            {printf("Expr\n");}
;

Const_Expr_List :
  Const_Expr COMMA Const_Expr_List    
  { 
    {add_type_FormalParameter(p->last , createTableEntry($1, NULL, passType, NUMBER, order,NULL,NULL,NULL,NULL,NULL));}    
  }
| Const_Expr 
  { 
    {add_type_FormalParameter(p->last, createTableEntry($1, NULL, passType, NUMBER, order,NULL,NULL,NULL,NULL,NULL));}    
  }
;


Field_List    : 
  fi_Identifier_List COLON Type { change_type_FormalParamType(p, $3); } SEMIC Field_List
| fi_Identifier_List COLON Type { change_type_FormalParamType(p, $3); }
|                                                 {printf("Field_List_Nothing\n");}
;

fi_Identifier_List:
  ident { add_type_FormalParameter(p->last, createTableEntry($1->node_value, NULL, passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,NULL));}  fi_Identifier_List_Aux  
;

fi_Identifier_List_Aux:
COMMA fi_Identifier_List
|
;


// Now it is th part where we would be declaring the procedures...

Proc_List     :
  Proc_Decl SEMIC Proc_List     {printf("Proc_Decl SEMIC Proc_List\n");}
|                               {printf("Proc_Decl_Nothing\n");}
;

Proc_Decl     : 
  PROCEDURE ident
  {
      insert_last(p,create_typeEntry(PROC_TYPE,NULL,NULL));
      tableEntry *cr = createTableEntry($2->node_value, p->last , VAL, PROC_NAME, 0, NULL, 0, ++scopeCount, NULL,own->last);
      addSymbolTableEntry(&symbolTable, cr);
      currentScope = scopeCount;
      tableEntry *n = own->first;
      if (own->first == NULL){
        own->first = cr;
        own->last = cr;
      }
      else{
        while (n->next_owner != NULL){
          n=n->next_owner;
        }
        n->next_owner = cr;
        own->last = cr;
      }
  } 
  Formal_Pars SEMIC Decl_Seq Stat_Block END ident 
  {
      tableEntry *i = own->first;
      if (i->next_owner == NULL){
        own->first = NULL;
        own->last = NULL;
      }
      else{
        tableEntry *prev = own->first;
        while (i->next_owner != NULL){
          prev = i;
          i=i->next_owner;
        }
        prev->next_owner = NULL;
        own->last = prev;
        free(i);
      }
      scopeCount--;
      remove_last(p);
  }
;

// In this part we are writing the grammar for the FORMAL PARMAMETERS of the procedure dclarartion in data_list

Formal_Pars: 
  LEFTBRAC FP_section_List RIGHTBRAC COLON Type
| LEFTBRAC FP_section_List RIGHTBRAC {printf("LEFTBRAC FP_section_List RIGHTBRAC\n");}
|  LEFTBRAC RIGHTBRAC  {printf("LEFTBRAC RIGHTBRAC\n");}
|  {printf("Formal_Pars_nothing\n");}
;

FP_section_List:
  FP_section SEMIC FP_section_List    {printf("FP_section SEMIC FP_section_List");}
| FP_section   {printf("FP_section");}
;

FP_section:
  fp_Identifier_List COLON Type                 { change_type_FormalParamType(p, $3); }
| VAR fp_Identifier_List COLON Type             { change_type_FormalParamType(p, $4); }
;

fp_Identifier_List:
  ident fp_Identifier_List_Aux                  { add_type_FormalParameter(p->last, createTableEntry($1->node_value, NULL , passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,NULL));}
;

fp_Identifier_List_Aux:
COMMA fp_Identifier_List              
|
;

Formal_Pars_Dec: 
  LEFTBRAC FP_section_List_Dec RIGHTBRAC COLON Type    {printf("LEFTBRAC FP_section_List RIGHTBRAC COLON Type\n");}
| LEFTBRAC FP_section_List_Dec RIGHTBRAC {printf("LEFTBRAC FP_section_List RIGHTBRAC\n");}
|  LEFTBRAC RIGHTBRAC  {printf("LEFTBRAC RIGHTBRAC\n");}
|  {printf("Formal_Pars_nothing\n");}
;

FP_section_List_Dec:
  FP_section_Dec SEMIC FP_section_List_Dec    {printf("FP_section SEMIC FP_section_List");}
| FP_section_Dec   {printf("FP_section");}
;

FP_section_Dec:
  fp_Identifier_List_Dec COLON Type      { change_type_FormalParamType(p, $3); }
| VAR fp_Identifier_List_Dec COLON Type  { change_type_FormalParamType(p, $4); }
;

fp_Identifier_List_Dec:
  ident fp_Identifier_List_Aux_Dec      { add_type_FormalParameter(p->last, createTableEntry($1->node_value, NULL , passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,NULL));}
;

fp_Identifier_List_Aux_Dec:
COMMA fp_Identifier_List_Dec              
|
;

Identifier_List:
  ident { addSymbolTableEntry(&symbolTable, createTableEntry($1->node_value, NULL, VAL, IDENTIFIER, 0, NULL, currentScope, currentScope, NULL,NULL)); } Identifier_List_Aux
;

Identifier_List_Aux:
COMMA Identifier_List               {printf("IDENT COMMA Identifier_List\n");}
|
;

ident:
  IDENT {$$ = makeNode(IDENT, yytext, NOTSET, REF, NULL, NULL); }
;

%%

void yyerror(const char *s){
    fprintf(stderr, "************************** %s **************************\n", s);
}

int main()
{
  own = (owner_list*)malloc(sizeof(owner_list));
  own->first = NULL;
  own->last = NULL;
  createSymbolTable(&symbolTable);
  p = createtypeEntry();
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
  //print_Symbol(&symbolTable);
  return 0;
}