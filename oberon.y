// Please write the name of the definitions using underscore if specifying more than two words in your program
// First letter after every underscore shud be capital

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
%token BOOLEAN CHAR INTEGER LONGREAL REAL
%token BOOLEAN_VAL CHAR_VAL INTEGER_VAL REAL_VAL STRING_VAL IDENT

%nonassoc EQ_COMP  UNEQ  LT  LE  GT  GE  IN  IS
%left PLUS_SYM  MINUS_SYM  OR
%left MULTIPLY_SYM  DIVIDE_SYM  DIV  MOD  AND_SYM OR_SYM

%{

#include<stdio.h>
#include "symbol_table.h"
#include "ast.h"
#include "ast.c"
void yyerror(const char *);
int yylex(void);

extern char * yytext; 

%}

%%

// Defining Module and all other blocks in a Oberon File

Module:
    cast_away Main_Block END ident DOTSYM     {printf("start \n");}
    ;

cast_away:
    MODULE ident SEMIC  {printf("Module\n");}
    ;

Main_Block:
       Import_Modules Decl_Seq Stat_Block   {printf("Import_Modules Decl_Seq Stat_Block\n");}
    ;

Import_Modules: 
    IMPORT Import_Modules_List SEMIC    {printf("IMPORT Import_Modules_List SEMIC\n");}
    |                                   {printf("IMPORT Import_Modules_List SEMIC_nothing\n");}
    ;

Import_Modules_List: 
    Import_Modules_List COMMA Import    {printf("Import_Modules_List COMMA Import\n");}
    | Import   {printf("Import\n");}
    ;

Import:
    ident Import_Aux
    ;

Import_Aux:
    ASSIGN ident  {printf("IDENT ASSIGN IDENT\n");}
    |
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
| INTEGER_VAL   {printf("integer val is %d",$1);}
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
  Identifier_List EQ_COMP Type SEMIC Type_List      {printf("Identifier_List EQ_COMP Type SEMIC Type_List\n");}
|                                                   {printf("Type_List_Nothing\n");}
;

Var_List  : 
  Identifier_List COLON Type SEMIC Var_List         {printf("Identifier_List COLON Type SEMIC Var_List\n");}
|                                                   {printf("Var_List_Nothing\n");}
;

// this Qualident contains the various various type declaration methods like array, record , 
// pointer and procedure declarations

Type: 
Qualident                           {printf("Qualident\n");}
| INTEGER                           {printf("INTEGER\n");}
| CHAR                              {printf("CHAR\n");}
| BOOLEAN                           {printf("BOOLEAN\n");}
| REAL                              {printf("REAL\n");}
| LONGREAL                          {printf("LONGREAL\n");}
| ARRAY Const_Expr_List OF Type     {printf("ARRAY Const_Expr_List OF Type\n");}
| ARRAY OF Type                     {printf("ARRAY OF Type\n");}
| RECORD LEFTBRAC Qualident RIGHTBRAC Field_List END           {printf("RECORD LEFTBRAC Qualident RIGHTBRAC Field_List END\n");}// Changes Look at it
| RECORD Field_List END             {printf("RECORD Field_List END\n");}
| POINTER TO Type                   {printf("POINTER TO Type\n");}
| PROCEDURE Formal_Pars             {printf("PROCEDURE Formal_Pars\n");}
| SET                               {printf("SET\n");}
;

Qualident    :             // For referencing a particular data type
  ident Qualident_Aux                 
;

Qualident_Aux:
  DOTSYM ident {printf("IDENT DOTSYM IDENT\n");}// For referencing an object within in a different module 
  |
;  


Const_Expr    :                                   
  Expr                                            {printf("Expr\n");}
;

Const_Expr_List :
  Const_Expr COMMA Const_Expr_List                {printf("Const_Expr COMMA Const_Expr_List\n");}
| Const_Expr                                      {printf("Const_Expr\n");}
;


Field_List    : 
  Identifier_List COLON Type SEMIC Field_List     {printf("Identifier_List COLON Type SEMIC Field_List\n");}
| Identifier_List COLON Type                      {printf("Identifier_List COLON Type\n");}
|                                                 {printf("Field_List_Nothing\n");}
;

// Now it is th part where we would be declaring the procedures...

Proc_List     :
  Proc_Decl SEMIC Proc_List     {printf("Proc_Decl SEMIC Proc_List\n");}
|                               {printf("Proc_Decl_Nothing\n");}
;

Proc_Decl     : 
  PROCEDURE ident Formal_Pars SEMIC Decl_Seq Stat_Block END ident {printf("PROCEDURE IDENT Formal_Pars SEMIC Decl_Seq Stat_Block END IDENT\n");}
;

// In this part we are writing the grammar for the FORMAL PARMAMETERS of the procedure dclarartion in data_list

Formal_Pars: 
  LEFTBRAC FP_section_List RIGHTBRAC COLON Type    {printf("LEFTBRAC FP_section_List RIGHTBRAC COLON Type\n");}
| LEFTBRAC FP_section_List RIGHTBRAC {printf("LEFTBRAC FP_section_List RIGHTBRAC\n");}
|  LEFTBRAC RIGHTBRAC  {printf("LEFTBRAC RIGHTBRAC\n");}
|  {printf("Formal_Pars_nothing\n");}
;

FP_section_List:
  FP_section SEMIC FP_section_List    {printf("FP_section SEMIC FP_section_List");}
| FP_section   {printf("FP_section");}
;

FP_section:
  Identifier_List COLON Type         {printf("Identifier_List COLON Type\n");}
| VAR Identifier_List COLON Type     {printf("VAR Identifier_List COLON Type\n");}
;

Identifier_List:
  ident Identifier_List_Aux
;

Identifier_List_Aux:
COMMA Identifier_List        {printf("IDENT COMMA Identifier_List\n");}
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
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
}

