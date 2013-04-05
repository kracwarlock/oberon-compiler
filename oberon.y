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

SymbolTable symbolTable;

owner_list *own;

type_tableEntry *current_type;
type_tableEntry *current_type2;
type_tableEntry *current_type3;
type_tableEntry *current_type4;
type_tableEntry *current_type5;

tableEntry *owner_func;

tableEntry *current_ident;

type_EntryTable *p;
type_EntryTable *p_check;

char *name_p;

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
    ident ASSIGN ident { addSymbolTableEntry(&symbolTable, createTableEntry($1->node_value, NULL, NULL, IDENTIFIER, 0, NULL, 0,0,NULL,own->last)); }
    | ident
    ;

Stat_Block:
    BEG Statement_Sequence     { $$ = makeNode(OPR, "BEG", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $2);}
    |                          { $$ = NULL;}
    ;

Statement_Sequence:
    Statement SEMIC Statement_Sequence  { $$ = makeNode(OPR, ";", create_typeEntry(NOTSET,NULL,NULL), VAL, $1, $3);}
    | Statement SEMIC                   { $$ = makeNode(OPR, ";", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $1);}
    ;

Statement    : 
  Designator
  {
    $1->type=current_type;
  }
   ASSIGN Expr  {
    printf("finally_time_2_%d_%d_%s",$1->type->type,$4->type->type,$1->node_value);
    //printf("it_is_here_%s_%s_%d_%d",$1->node_value,$3->node_value,current_type->type,current_type4->type);
    //printf("print_%s %d",$1->node_value,current_type->type);
    if (type_check($1->type,$4->type)){
      printf("type_error in designation\n");
    }
    $$ = makeNode(OPR, "=", create_typeEntry(NOTSET,NULL,NULL), VAL, $1, $4); 
  }
| Designator              { $$ = $1;}
| IF_COND Expr THEN Statement_Sequence Else_If_Block Else END
  { 
    $$ = makeNode(OPR, "IF", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "THEN", create_typeEntry(NOTSET,NULL,NULL), VAL, $4 , makeNode(OPR, "REM_ELSE", create_typeEntry(NOTSET,NULL,NULL), VAL, $5 , $6) ));
  }
| CASE_COND Expr OF Case_Parameters Else END 
{
  $$ = makeNode(OPR, "CASE", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "CASE_PARAMS", create_typeEntry(NOTSET,NULL,NULL), VAL, $4, makeNode(OPR, "ELSE", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $5))); 
}
| WHILE Expr DOCASE Statement_Sequence END      
{
  $$ = makeNode(OPR, "WHILE", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "DOCASE_WHILE", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $4));
}
| REPEAT Statement_Sequence UNTIL Expr 
{
  $$ = makeNode(OPR, "REPEAT", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "UNTIL_REPEAT", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $4)); 
}
| FOR ident Statement_Aux             
{ 
  $$ = makeNode(OPR, "FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , $3);
}
| LOOP Statement_Sequence END         
{
 $$ = makeNode(OPR, "LOOP", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $2);
}
| EXIT                                
{
 $$ = makeNode(OPR, "EXIT", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, NULL); 
}
| RETURN Expr                         
{ 
  $$ = makeNode(OPR, "RETURN", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $2);
}
| RETURN                              
{ 
  $$ = makeNode(OPR, "RETURN", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, NULL);
}
|                                     
{ 
  $$ = NULL; 
}
;

Statement_Aux :
ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END  
{
 $$ = makeNode(OPR, "ASSIGN_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "TO_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $4, makeNode(OPR, "BY_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $6, makeNode(OPR, "DO_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $8, NULL ) ) )); 
} 
| ASSIGN Expr TO Expr DOCASE Statement_Sequence END     
{
$$ = makeNode(OPR, "ASSIGN_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "TO_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $4, makeNode(OPR, "DO_FOR", create_typeEntry(NOTSET,NULL,NULL), VAL, $6 , NULL ))); 
}
;

Expr         : 
/* Relations */
  Expr EQ_COMP Expr       
  { 
    // printf("new_mridul_type %d_%s\n",current_type->type,$3->node_value);
    // // if (current_type->type == BOOLEAN){
    // //   current_type3 = current_type;
    // // }
    // // else{
    // //   printf("type_error2\n");
    // // }
    // // current_type = create_typeEntry(BOOLEAN,NULL,NULL);
    if ($1->type->type==$3->type->type && $1->type->type==BOOLEAN){
      $$ = makeNode(OPR, "=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
    }
    else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
    }
    printf("finally_times_%d_%d_%s",$1->type->type,$3->type->type,$1->node_value);
  }
| Expr UNEQ Expr         
  { 
    // printf("new_mridul_type%d_%s\n",current_type->type,$4->node_value);
    // if (current_type->type == BOOLEAN){
    //   current_type3 = current_type;
    // }
    // else{
    //   printf("type_error4\n");
    // }
    // current_type = create_typeEntry(BOOLEAN,NULL,NULL);
    if ($1->type->type==$3->type->type && $1->type->type==BOOLEAN){
      $$ = makeNode(OPR, "=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
    }
    else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
    }
  }
| Expr LT Expr            
{
  if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, "<", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, "<", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr LE Expr            
{ 
    if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, "<=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, "<=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr GT Expr            
{
  if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, ">", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, ">", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr GE Expr            
{ 
    if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, ">=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, ">=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr IN Expr            
{
  if (($1->type->type==INTEGER || $1->type->type==SET)){
        $$ = makeNode(OPR, "IN", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr IS Expr            
{ 
  printf("lopo%s",$3->node_value);
  type_tableEntry *lk = type_lookup(&symbolTable,$3->node_value,currentScope);
  //printf("lopo%d",lk->type);
  if (($1->type==lk)){
        printf("andar_hain");
        // value is TRUE
        $$ = makeNode(OPR, "IS", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3); 
  }
  else{
      // value is FALSE
      $$ = makeNode(OPR, "IS", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3); 
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
// | PLUS_SYM Expr %prec UPLUS             // have to take a look at this...
// | MINUS_SYM Expr %prec UMINUS
| Expr PLUS_SYM Expr           
{
  if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, "+", create_typeEntry(INTEGER,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, "+", create_typeEntry(REAL,NULL,NULL), VAL, $1, $3);
  }
  else if($1->type->type==SET_TYPE && $3->type->type==SET_TYPE){
      $$ = makeNode(OPR, "+", create_typeEntry(SET,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s,%d,%d",$1->node_value,$3->node_value,$1->type->type,$3->type->type);
  }
}
| Expr MINUS_SYM Expr          
{ 
    if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, "-", create_typeEntry(INTEGER,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, "-", create_typeEntry(REAL,NULL,NULL), VAL, $1, $3);
  }
  else if($1->type->type==SET_TYPE && $3->type->type==SET_TYPE){
      $$ = makeNode(OPR, "-", create_typeEntry(SET,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr OR Expr                 
{ 
    if ($1->type->type==$3->type->type && $1->type->type==BOOLEAN){
      $$ = makeNode(OPR, "=", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
    }
    else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
    }
}
| Expr MULTIPLY_SYM Expr       
{ 
  if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, "*", create_typeEntry(INTEGER,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, "*", create_typeEntry(REAL,NULL,NULL), VAL, $1, $3);
  }
  else if($1->type->type==SET_TYPE && $3->type->type==SET_TYPE){
      $$ = makeNode(OPR, "*", create_typeEntry(SET,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr DIVIDE_SYM Expr         
{ 
  if (($1->type->type==INTEGER || $1->type->type==REAL) && ($3->type->type==INTEGER || $3->type->type==REAL)){
      if ($1->type->type==INTEGER && $3->type->type==INTEGER)
        $$ = makeNode(OPR, "/", create_typeEntry(INTEGER,NULL,NULL), VAL, $1, $3);
      else
        $$ = makeNode(OPR, "/", create_typeEntry(REAL,NULL,NULL), VAL, $1, $3);
  }
  else if($1->type->type==SET_TYPE && $3->type->type==SET_TYPE){
      $$ = makeNode(OPR, "/", create_typeEntry(SET,NULL,NULL), VAL, $1, $3);
  }
  else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr DIV Expr                
{ 
  if ($1->type->type==$3->type->type && $1->type->type==INTEGER){
    $$ = makeNode(OPR, "DIV", create_typeEntry(INTEGER,NULL,NULL), VAL, $1, $3);
  }
  else{
    printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr MOD Expr                
{
  if ($1->type->type==$3->type->type && $1->type->type==INTEGER){
    $$ = makeNode(OPR, "MOD", create_typeEntry(INTEGER,NULL,NULL), VAL, $1, $3);
  }
  else{
    printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
  }
}
| Expr AND_SYM Expr            
{ 
    if ($1->type->type==$3->type->type && $1->type->type==BOOLEAN){
      $$ = makeNode(OPR, "AND", create_typeEntry(BOOLEAN,NULL,NULL), VAL, $1, $3);
    }
    else{
      printf("Error in type checking : Incompatible type%s,%s",$1->node_value,$3->node_value);
    }
}
| Factor                       { $$ = $1;printf("checkin_%s_%d_",$1->node_value,$1->type->type);}
;

Factor       : 
  Designator    
  { 
    printf("current_is_my %d_%s",current_type->type,$1->node_value);
    $1->type=current_type;
    $$=$1;
    printf("kop_%d",$1->type->type);
  }
| BOOLEAN_VAL   { $$ = makeNode(NUM, yytext, create_typeEntry(BOOLEAN,NULL,NULL), VAL, NULL, NULL); }
| REAL_VAL      { $$ = makeNode(NUM, yytext, create_typeEntry(REAL,NULL,NULL), VAL, NULL, NULL); }
| CHAR_VAL      { $$ = makeNode(NUM, yytext, create_typeEntry(CHAR,NULL,NULL), VAL, NULL, NULL); }
| INTEGER_VAL   { $$ = makeNode(NUM, yytext, create_typeEntry(INTEGER,NULL,NULL), VAL, NULL, NULL); }
| NIL           { $$ = makeNode(NUM, yytext, create_typeEntry(NO,NULL,NULL), VAL, NULL, NULL); }
| Set           { $$ = makeNode(NUM, yytext, create_typeEntry(SET_TYPE,NULL,NULL), VAL, NULL, $1); }      
| LEFTBRAC Expr RIGHTBRAC   { $$ = makeNode(OPR, "()", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL , $2); }
| TILDA Factor  { $$ = makeNode(OPR, "~", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL , $2); }
;

Designator   : 
  ident 
  {
    tableEntry *m = findEntry(&symbolTable, $1->node_value ,own->first);

    current_type = m->type;
    printf("pop_%s_%d",$1->node_value,m->type->type);
    if (m->type == NULL)
      printf("l_ho_gaya");
    printf("all_ident");
  } 
  optSuffix     { $$ = make_new_node($1,$3);}
;

optSuffix :
  DOTSYM ident 
  {
          printf("done\n");
         if (current_type->type == RECORD_TYPE){
          if (current_type->formal_params != NULL)
              printf("ghkll %d\n",current_type->formal_params->type->type);
           tableEntry *ip2 = find_formal_entry($2->node_value,current_type->formal_params);
           if (ip2 == NULL)
              printf("klklklkl");
          else
             current_type = ip2->type;
           printf("current_type->type is %d",current_type->type);
           printf("all_record\n");
         }

  }
  optSuffix  { $$ = makeNode(OPR, ".", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, make_new_node($2,$4));}
| LSQBR Expr_List RSQBR
{
        if (current_type->type == ARRAY_TYPE){
          current_type = current_type->tp;
          printf("all_array\n");
        }
}
  optSuffix  { $$ = makeNode(OPR, "[]", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, make_new_node($2,$5));}
| CARR
{
  if (current_type->type == POINTER_TYPE){
    current_type = current_type->tp;
    printf("all_pointer\n");
  }
  else{
    printf("error_pointer\n");
  }
} 
 optSuffix    
{ 
  $$ = makeNode(OPR, "^", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $3);
}
| LEFTBRAC Expr_List RIGHTBRAC optSuffix   { $$ = makeNode(OPR, "()", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, make_new_node($2,$4));}
|   
{ 
  current_type = current_type;
  $$ = NULL;
}
;

Expr_List     : 
  Expr                                          { $$ = $1; }
| Expr COMMA Expr_List                          { $$ = makeNode(OPR, ",", create_typeEntry(NOTSET,NULL,NULL), VAL, $1, $3); }
;              

Set          : 
  LCBR Element_List RCBR                        { $$ = makeNode(OPR, ",", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , NULL); }
;

Element_List :
  Element COMMA Element_List                    { $$ = makeNode(OPR, ",", create_typeEntry(NOTSET,NULL,NULL), VAL, $1, $3); }
| Element                                       { $$ = $1; }
;

Element      : 
  Expr                                          
  { 
    if ($1->type->type==INTEGER)
      $$ = $1; 
    else
      printf("Error in type checking : Incompatible type : Only Integer Allowed,%s",$1->node_value);
  }
| Expr DOTDOT Expr                              
{ 
    if ($1->type->type==INTEGER && $1->type->type==INTEGER)
      $$ = makeNode(OPR, "..", create_typeEntry(NOTSET,NULL,NULL), VAL, $1, $3); 
    else
      printf("Error in type checking : Incompatible type : Only Integer Allowed,%s",$1->node_value);
}
;

Else_If_Block:
  ELSEIF Expr THEN Statement_Sequence Else_If_Block     { $$ = makeNode(OPR, "ELSEIF", create_typeEntry(NOTSET,NULL,NULL), VAL, $2 , makeNode(OPR, "ELSEIF_AUX", create_typeEntry(NOTSET,NULL,NULL), VAL, $4 , $5)); }
|                                                       { $$ = NULL; }
;

Else:
  ELSE Statement_Sequence                        { $$ = makeNode(OPR, "ELSE", create_typeEntry(NOTSET,NULL,NULL), VAL, NULL, $2);}
|                                                { $$ = NULL; }
;

Case_Parameters:
  Case_Single                                     { $$ = $1; }
| Case_Single OR_SYM Case_Parameters              { $$ = makeNode(OPR, "OR", create_typeEntry(NOTSET,NULL,NULL), VAL, $1 , $3);}
;

Case_Single: 
  Case_Expression_List COLON Statement_Sequence   { $$ = makeNode(OPR, ";", create_typeEntry(NOTSET,NULL,NULL), VAL, $1, $3); }
|                                                 { $$ = NULL;}
;

Case_Expression_List:                // Case label list beacuse of the expression matching could be to a integer but also to a list of integers or list of expressions
  Case_Expression                                 { $$ = $1; }
| Case_Expression COMMA Case_Expression_List      { $$ = makeNode(OPR, ",", create_typeEntry(NOTSET,NULL,NULL), VAL, $1 , $3);}
;

Case_Expression: 
  Expr                                            { $$ = $1; }
| Expr DOTDOT Expr                                { $$ = makeNode(OPR, "..", create_typeEntry(NOTSET,NULL,NULL), VAL, $1 , $3);}
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
  if (p->first == NULL)
    printf("first_null1\n");
 insert_last(p,$1);
 $$ = p->last;
 remove_last(p);
}
| INTEGER_TYPE                      
{ 
    if (p->first == NULL)
    printf("first_null2\n");
  insert_last(p,create_typeEntry(INTEGER,NULL,NULL));{printf("Var_List_Nothing\n");}
  $$ = p->last; 
  remove_last(p);
}
| CHAR_TYPE                         
{ 
    if (p->first == NULL)
    printf("first_null3\n");
  insert_last(p,create_typeEntry(CHAR,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| BOOLEAN_TYPE                      
{ 
  if (p->first == NULL)
    printf("first_null4\n");
  insert_last(p,create_typeEntry(BOOLEAN,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| REAL_TYPE                         
{ 
  if (p->first == NULL)
    printf("first_null5\n");
  insert_last(p,create_typeEntry(REAL,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| LONGREAL_TYPE
{
  if (p->first == NULL)
    printf("first_null6\n");
  insert_last(p,create_typeEntry(LONGREAL,NULL,NULL));
  $$ = p->last;
  remove_last(p);
}
| ARRAY 
  {
    if (p->first == NULL)
    printf("first_null7\n");
    insert_last(p,create_typeEntry(ARRAY_TYPE,NULL,NULL));
  } 
  OF Type 
  {
    p->last->tp=$4;
    $$ = p->last;
    remove_last(p);
  }
| ARRAY
   {
    if (p->first == NULL)
    printf("first_null8\n");
      insert_last(p,create_typeEntry(ARRAY_TYPE,NULL,NULL));
   } 
   Const_Expr_List OF Type    
   { 
      p->last->tp=$5;
      $$ = p->last;
      remove_last(p);
   }
| RECORD 
  {
    if (p->first == NULL)
    printf("first_null9\n");
    insert_last(p,create_typeEntry(RECORD_TYPE,NULL,NULL));
  }
  Field_List END             
  {
    $$ = p->last;
    remove_last(p);
  }
| POINTER 
  {
    if (p->first == NULL)
    printf("first_null10\n");
    insert_last(p,create_typeEntry(POINTER_TYPE,NULL,NULL));
  }
  TO Type                   
  { 
    p->last->tp=$4;
    $$ = p->last;
    remove_last(p);
  }
| PROCEDURE
{
  if (p->first == NULL)
    printf("first_null11\n");
  insert_last(p,create_typeEntry(PROC_TYPE,NULL,NULL));
}
Formal_Pars_Dec             
{ 
  $$ = p->last;
  remove_last(p);
}
| SET                               
{
  if (p->first == NULL)
    printf("first_null12\n");
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
  printf("correp_%s",$1->node_value);
  $$ = type_lookup(&symbolTable,$1->node_value,currentScope);
}                 
;

Const_Expr    :                                   
  Expr                                            {printf("Expr\n");}
;

Const_Expr_List :
  Const_Expr COMMA Const_Expr_List    
  { 
    {add_type_FormalParameter(p->last , createTableEntry($1, NULL, passType, NUMBER, order,NULL,NULL,NULL,NULL,own->last));}    
  }
| Const_Expr 
  { 
    {add_type_FormalParameter(p->last, createTableEntry($1, NULL, passType, NUMBER, order,NULL,NULL,NULL,NULL,own->last));}    
  }
;


Field_List    : 
  fi_Identifier_List COLON Type { change_type_FormalParamType(p, $3); } SEMIC Field_List
| fi_Identifier_List COLON Type { change_type_FormalParamType(p, $3); }
|                                                 {printf("Field_List_Nothing\n");}
;

fi_Identifier_List:
  ident { add_type_FormalParameter(p->last, createTableEntry($1->node_value, NULL, passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,own->last));}  fi_Identifier_List_Aux  
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
        while (n->next_owner != NULL){
          n=n->next_owner;
        }
        n->next_owner = cr;
        own->last = cr;
      printf(" mera_owner_%s_%s",own->first->name,own->last->name);
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
        //free(i);
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
  ident fp_Identifier_List_Aux                  
  { 
    add_type_FormalParameter(p->last,createTableEntry($1->node_value, NULL , passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,own->last));
  }
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
  ident fp_Identifier_List_Aux_Dec      { add_type_FormalParameter(p->last, createTableEntry($1->node_value, NULL , passType, IDENTIFIER, order,NULL,NULL,NULL,NULL,own->last));}
;

fp_Identifier_List_Aux_Dec:
COMMA fp_Identifier_List_Dec              
|
;

Identifier_List:
  ident { addSymbolTableEntry(&symbolTable, createTableEntry($1->node_value, NULL, VAL, IDENTIFIER, 0, NULL, currentScope, currentScope, NULL,own->last)); } Identifier_List_Aux
;

Identifier_List_Aux:
COMMA Identifier_List               {printf("IDENT COMMA Identifier_List\n");}
|
;

ident:
  IDENT
  {
    $$ = makeNode(IDENT, yytext, create_typeEntry(NOTSET,NULL,NULL), REF, NULL, NULL); 
  }
;

%%

void yyerror(const char *s){
    fprintf(stderr, "************************** %s **************************\n", s);
}

int main()
{
  own = (owner_list*)malloc(sizeof(owner_list));
  own->first = createTableEntry("mera__hain_main", VOID ,NULL, NULL , 0, NULL, 0, 0, NULL, NULL);
  own->last = own->first;
  createSymbolTable(&symbolTable);
  p = createtypeEntry();
  p_check = createtypeEntry();
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
  type_printf(&symbolTable);
  return 0;
}