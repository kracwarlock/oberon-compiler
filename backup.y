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

%nonassoc EQ_COMP  UNEQ  LT  LE  GT  GE  IN  IS
%left PLUS_SYM  MINUS_SYM  OR
%left MULTIPLY_SYM  DIVIDE_SYM  DIV  MOD  AND_SYM OR_SYM

%{

#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "symbol_table.h"
#include "ast.c"

SymbolTable *symbolTable;

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
%type <node> Designator
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
    BEG Statement_Sequence     {printf("BEG Statement_Sequence\n");}
    |                          {printf("BEG Statement_Sequence_Nothing\n");}
    ;

Statement_Sequence:
    Statement SEMIC Statement_Sequence  {printf("Statement SEMIC Statement_Sequence\n");}
    | Statement SEMIC                   {printf("Statement SEMIC\n");}
    ;

Statement    : 
  Designator ASSIGN Expr {printf(" Designator ASSIGN Expr \n");}
| Designator              {printf(" Designator\n");}
| IF_COND Expr THEN Statement_Sequence Else_If_Block Else END  {printf(" IF_COND Expr THEN Statement_Sequence Else_If_Block Else END\n");}
| CASE_COND Expr OF Case_Parameters Else END {printf(" CASE_COND Expr OF Case_Parameters Else END \n");}
| WHILE Expr DOCASE Statement_Sequence END      {printf("WHILE Expr DOCASE Statement_Sequence END\n");}
| REPEAT Statement_Sequence UNTIL Expr          {printf("REPEAT Statement_Sequence UNTIL Expr\n");}
| FOR ident Statement_Aux
| LOOP Statement_Sequence END         {printf("LOOP Statement_Sequence END\n");}
| EXIT                                {printf(" EXIT\n");}
| RETURN Expr                         {printf(" RETURN Expr\n");}
| RETURN                              {printf(" RETURN\n");}
|                                     {printf(" stat_nothing\n");}
;

Statement_Aux :
ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END  {printf(" FOR IDENT ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END\n");} 
| ASSIGN Expr TO Expr DOCASE Statement_Sequence END     {printf("FOR IDENT ASSIGN Expr TO Expr DOCASE Statement_Sequence END\n");}
;

Expr         : 
/* Relations */
  Expr EQ_COMP Expr       {printf("Expr EQ_COMP Expr\n");}
| Expr UNEQ Expr          {printf(" Expr UNEQ Expr\n");}
| Expr LT Expr            {printf(" Expr LT Expr\n");}
| Expr LE Expr            {printf(" Expr LE Expr\n");}
| Expr GT Expr            {printf(" Expr GT Expr\n");}
| Expr GE Expr            {printf(" Expr GE Expr\n");}
| Expr IN Expr            {printf(" Expr IN Expr\n");}
| Expr IS Expr            {printf(" Expr IS Expr\n");}
// | PLUS_SYM Expr %prec UPLUS             // have to take a look at this...
// | MINUS_SYM Expr %prec UMINUS
| Expr PLUS_SYM Expr           {printf("Expr PLUS_SYM Expr\n");}
| Expr MINUS_SYM Expr          {printf("Expr MINUS_SYM Expr\n");}
| Expr OR Expr                 {printf("Expr OR Expr\n");}
| Expr MULTIPLY_SYM Expr       {printf("Expr MULTIPLY_SYM Expr\n");}
| Expr DIVIDE_SYM Expr         {printf("Expr DIVIDE_SYM Expr\n");}
| Expr DIV Expr                {printf("Expr DIV Expr\n");}
| Expr MOD Expr                {printf("Expr MOD Expr\n");}
| Expr AND_SYM Expr            {printf("Expr AND_SYM Expr\n");}
| Factor                       {printf("Factor\n");}
;

Factor       : 
  Designator    {printf("Designator\n");}
| INTEGER_VAL   {printf("integer val is ");}
| CHAR_VAL      {printf("CHAR_VAL\n");}
| NIL           {printf("NIL\n");}
| Set           {printf("Set\n");}      
| LEFTBRAC Expr RIGHTBRAC   {printf("LEFTBRAC Expr RIGHTBRAC\n");}
| TILDA Factor  {printf("TILDA Factor\n");} 
;

Designator   : 
  ident optSuffix     {printf("IDENT optSuffix\n");}
;

optSuffix :
  DOTSYM ident optSuffix {printf("DOTSYM IDENT  optSuffix\n");}
| LSQBR Expr_List RSQBR  optSuffix              {printf("LSQBR Expr_List RSQBR  optSuffix\n");}
| CARR  optSuffix                               {printf("CARR  optSuffix\n");}
| LEFTBRAC Expr_List RIGHTBRAC optSuffix   /* Changes from original grammar */  {printf("LEFTBRAC Expr_List RIGHTBRAC optSuffix\n");}
| LEFTBRAC RIGHTBRAC                      /* Changes from original grammar */   {printf("LEFTBRAC RIGHTBRAC\n");}
|                                               {printf("optSuffix_Nothing\n");}
;

Expr_List     : 
  Expr                                          {printf("Expr\n");}
| Expr COMMA Expr_List                          {printf("Expr COMMA Expr_List\n");}
;              

Set          : 
  LCBR Element_List RCBR                        {printf("LCBR Element_List RCBR\n");}
;

Element_List :
  Element COMMA Element_List                    {printf("Element COMMA Element_List\n");}
| Element                                       {printf("Element\n");}
;

Element      : 
  Expr                                          {printf("Expr\n");}
| Expr DOTDOT Expr                              {printf("Expr DOTDOT Expr\n");}
;

Else_If_Block:
  ELSEIF Expr THEN Statement_Sequence Else_If_Block     {printf("ELSEIF Expr THEN Statement_Sequence Else_If_Block\n");}
|                                                       {printf("Else_If_Block_Nothing\n");}
;

Else:
  ELSE Statement_Sequence                        {printf("ELSE Statement_Sequence\n");}
|                                                {printf("Else_Nothing\n");}
;

Case_Parameters:
  Case_Single                                     {printf("Case_Single\n");}
| Case_Single OR_SYM Case_Parameters              {printf("Case_Single OR_SYM Case_Parameters\n");}
;

Case_Single: 
  Case_Expression_List COLON Statement_Sequence   {printf("Case_Expression_List COLON Statement_Sequence\n");}
|                                                 {printf("Case_Single_Nothing\n");}
;

Case_Expression_List:                // Case label list beacuse of the expression matching could be to a integer but also to a list of integers or list of expressions
  Case_Expression                                 {printf("Case_Expression\n");}
| Case_Expression COMMA Case_Expression_List      {printf("Case_Expression COMMA Case_Expression_List\n");}
;

Case_Expression: 
  Expr                                            {printf("Expr\n");}
| Expr DOTDOT Expr                                {printf("Expr DOTDOT Expr\n");}
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
  } OF Type 
  {
    $$ = p->last;
    remove_last(p);
  }
| ARRAY
   {
      insert_last(p,create_typeEntry(ARRAY_TYPE,NULL,NULL));
   } Const_Expr_List OF Type    
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
    {add_type_FormalParameter(p, createTableEntry($1, NULL, passType, NUMBER, order,NULL,NULL,NULL,NULL,NULL));}    
  }
| Const_Expr 
  { 
    {add_type_FormalParameter(p, createTableEntry($1, NULL, passType, NUMBER, order,NULL,NULL,NULL,NULL,NULL));}    
  }
;


Field_List    : 
  fi_Identifier_List COLON Type { change_type_FormalParamType(p, $3); } SEMIC Field_List
| fi_Identifier_List COLON Type { change_type_FormalParamType(p, $3); }
|                                                 {printf("Field_List_Nothing\n");}
;

fi_Identifier_List:
  ident fi_Identifier_List_Aux      { add_type_FormalParameter(p, createTableEntry($1->node_value, NULL, passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,NULL));}    
;
z
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
      struct tableEntry *cr = createTableEntry($2->node_value, p->last , VAL, PROC_NAME, 0, NULL, 0, ++scopeCount, NULL,own->last);
      addSymbolTableEntry(&symbolTable, cr);
      currentScope = scopeCount;
      tableEntry *n = own->first;
      while (n != NULL){
        n=n->next_owner;
      }
      n->next_owner = cr;
      own->last = cr;
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
  ident fp_Identifier_List_Aux                  { add_type_FormalParameter(p, createTableEntry($1->node_value, NULL , passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,NULL));}
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
  ident fp_Identifier_List_Aux_Dec      { add_type_FormalParameter(p, createTableEntry($1->node_value, NULL , passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,NULL));}
;

fp_Identifier_List_Aux_Dec:
COMMA fp_Identifier_List_Dec              
|
;

Identifier_List:
  ident Identifier_List_Aux         { addSymbolTableEntry(&symbolTable, createTableEntry($1->node_value, NULL, VAL, IDENTIFIER, 0, NULL, currentScope, currentScope, NULL,NULL)); }
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
  createSymbolTable(symbolTable);
  p = create_typeEntry();
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
  print_Symbol(&symbolTable);
  return 0;
}