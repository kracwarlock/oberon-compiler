// Please write the name of the definitions using underscore if specifying more than two words in your program
// First letter after every underscore shud be capital

%token SEMIC COMMA COLON RIGHTBRAC LEFTBRAC DOTSYM LSQBR RSQBR LCBR RCBR CARR
%token EQ_COMP UNEQ
%token TILDA ASSIGN DOTDOT
%token REPEAT UNTIL FOR TO BY DOCASE END
%token WHILE IF_COND THEN ELSEIF ELSE CASE_COND OF
%token STRLEN STRCAT STRCMP STRREV STRCPY
%token ARRAY RECORD SET BEG CONST EXIT
%token IMPORT LOOP MODULE NIL
%token POINTER PROCEDURE RETURN TYPE
%token VAR WITH ABS ODD LEN LSL ASR ROR FLOOR FLT ORD CHR LONG SHORT 
%token INC DEC INCL EXCL COPY NEW ASSERT PACK UNPK
%token BOOLEAN CHAR INTEGER LONGREAL REAL
%token BOOLEAN_VAL CHAR_VAL INTEGER_VAL REAL_VAL STRING_VAL IDENT
// %token IDENT    OF
// %token REPEAT
// %token UNTIL    FOR     TO
// %token BY       DO      END
// %token WHILE    IF_COND THEN
// %token ELSEIF   ELSE    CASE_COND
// %token BOOLEAN  CHAR    INT
// %token REAL     STRING  LONGREAL
// %token ARRAY    BEG     CONST
// %token EXIT     IMPORT  LOOP
// %token MODULE   NIL     POINTER
// %token RETURN   TYPE    PROCEDURE
// %token VAR      WITH
// %token OR       
// %token ASSIGN   LE    GE    DOTDOT
// %token RECORD

%nonassoc EQ_COMP  UNEQ  LT  LE  GT  GE  IN  IS
%left PLUS_SYM  MINUS_SYM  OR
%left MULTIPLY_SYM  DIVIDE_SYM  DIV  MOD  AND_SYM OR_SYM

%{

#include<stdio.h>
void yyerror(const char *);
int yylex(void);

%}

%%

// Defining Module and all other blocks in a Oberon File

Module:
    cast_away Main_Block END IDENT DOTSYM     {printf("haahs1\n");}
    ;

cast_away:
    MODULE IDENT SEMIC  {printf("haahs2\n");}
    ;

Main_Block:
       Import_Modules Decl_Seq Stat_Block   {printf("haahs3\n");}
    ;

Import_Modules: 
    IMPORT Import_Modules_List SEMIC    {printf("haahs4\n");}
    |
    ;

Import_Modules_List: 
    Import_Modules_List COMMA Import    {printf("haahs5\n");}
    | Import   {printf("haahs6\n");}
    ;

Import:
    IDENT ASSIGN IDENT    {printf("haahs7\n");}
    | IDENT      {printf("haahs8\n");}
    ;

Stat_Block:
    BEG Statement_Sequence     {printf("haahs lkjj\n");}
    | 
    ;

Statement_Sequence:
    Statement SEMIC Statement_Sequence
    | Statement SEMIC
    ;

Statement    : 
  Designator ASSIGN Expr {printf("idhae see bhi\n");}
| Designator
| IF_COND Expr THEN Statement_Sequence Else_If_Block Else END 
| CASE_COND Expr OF Case_Parameters Else END 
| WHILE Expr DOCASE Statement_Sequence END 
| REPEAT Statement_Sequence UNTIL Expr
| FOR IDENT ASSIGN Expr TO Expr BY Const_Expr DOCASE Statement_Sequence END 
| FOR IDENT ASSIGN Expr TO Expr DOCASE Statement_Sequence END 
| LOOP Statement_Sequence END
| EXIT 
| RETURN Expr
| RETURN
|
;

Expr         : 
/* Relations */
  Expr EQ_COMP Expr
| Expr UNEQ Expr
| Expr LT Expr
| Expr LE Expr
| Expr GT Expr
| Expr GE Expr
| Expr IN Expr
| Expr IS Expr
// | PLUS_SYM Expr %prec UPLUS             // have to take a look at this...
// | MINUS_SYM Expr %prec UMINUS
| Expr PLUS_SYM Expr           {printf("idhae see ++++++++++");}
| Expr MINUS_SYM Expr
| Expr OR Expr
| Expr MULTIPLY_SYM Expr
| Expr DIVIDE_SYM Expr
| Expr DIV Expr
| Expr MOD Expr
| Expr AND_SYM Expr
| Factor                {printf("idhae see\n");}
;

Factor       : 
  Designator
| INTEGER_VAL   {printf("integer val is %d",$1);}
| CHAR_VAL
| NIL 
| Set 
| LEFTBRAC Expr RIGHTBRAC 
| TILDA Factor
;

Designator   : 
  IDENT optSuffix
;

optSuffix :
  DOTSYM IDENT  optSuffix
| LSQBR Expr_List RSQBR  optSuffix
| CARR  optSuffix
| LEFTBRAC Expr_List RIGHTBRAC optSuffix   /* Changes from original grammar */
| LEFTBRAC RIGHTBRAC                      /* Changes from original grammar */
|
;

Expr_List     : 
  Expr 
| Expr COMMA Expr_List
;              

Set          : 
  LCBR Element_List RCBR
;

Element_List :
  Element COMMA Element_List
| Element 
;

Element      : 
  Expr 
| Expr DOTDOT Expr
;

Else_If_Block:
  ELSEIF Expr THEN Statement_Sequence Else_If_Block
|
;

Else:
  ELSE Statement_Sequence
|
;

Case_Parameters:
  Case_Single
| Case_Single OR_SYM Case_Parameters
;

Case_Single: 
  Case_Expression_List COLON Statement_Sequence
|
;

Case_Expression_List:                // Case label list beacuse of the expression matching could be to a integer but also to a list of integers or list of expressions
  Case_Expression  
| Case_Expression COMMA Case_Expression_List
;

Case_Expression: 
  Expr 
| Expr DOTDOT Expr
;


// This section declares the various sections of the declaration Part...
// In this part there are two types of sections namely:  Data declation list and procedure declaration list.

Decl_Seq: 
  Data_List Proc_List  {printf("haahs  999\n");}
;

Data_List:
  CONST Const_List Data_List  {printf("haahs\n");}
| TYPE  Type_List  Data_List
| VAR   Var_List Data_List
| {printf("ddddd\n");}
;


// In this region we are declaring various types of declaration namely "const declaration,var decaration and type declaration"

Const_List :
  Identifier_List EQ_COMP Const_Expr SEMIC Const_List {printf("haahs\n");}
| 
;

Type_List : 
  Identifier_List EQ_COMP Type SEMIC Type_List
|
;

Var_List  : 
  Identifier_List COLON Type SEMIC Var_List
| 
;

// this Qualident contains the various various type declaration methods like array, record , 
// pointer and procedure declarations

Type: 
Qualident
| INTEGER
| CHAR
| BOOLEAN
| REAL
| LONGREAL
| ARRAY Const_Expr_List OF Type 
| ARRAY OF Type 
| RECORD LEFTBRAC Qualident RIGHTBRAC Field_List END           // Changes Look at it
| RECORD Field_List END
| POINTER TO Type
| PROCEDURE Formal_Pars
;

Qualident    :             // For referencing a particular data type
  IDENT       
| IDENT DOTSYM IDENT          {printf("loada a\n");}// For referencing an object within in a different module 
;

Const_Expr    : 
  Expr
;

Const_Expr_List :
  Const_Expr COMMA Const_Expr_List
| Const_Expr
;


Field_List    : 
  Identifier_List COLON Type SEMIC Field_List
| Identifier_List COLON Type
|
;

// Now it is th part where we would be declaring the procedures...

Proc_List     :
  Proc_Decl SEMIC Proc_List
|
;

Proc_Decl     : 
  PROCEDURE IDENT Formal_Pars SEMIC Decl_Seq Stat_Block END IDENT    {printf("dsksdksd");}
;

// In this part we are writing the grammar for the FORMAL PARMAMETERS of the procedure dclarartion in data_list

Formal_Pars: 
  LEFTBRAC FP_section_List RIGHTBRAC COLON Type    {printf("formail pappaassss");}
| LEFTBRAC FP_section_List RIGHTBRAC {printf("formail pappaasssssssssssssssssss");}
|  LEFTBRAC RIGHTBRAC  {printf("formail pappaasssssssssssssss");}
|  {printf("formail pappaasssssssssssssssssss");}
;

FP_section_List:
  FP_section SEMIC FP_section_List
| FP_section   {printf("formail pappaa");}
;

FP_section:
  Identifier_List COLON Type 
| VAR Identifier_List COLON Type
;

Identifier_List:
  IDENT                             {printf("haahs akela ident\n");}
| IDENT COMMA Identifier_List        {printf("haahs iden\n");}
;


%%

int main()
{
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
  else
    printf("Encountered errors\n");
}

