// Please write the name of the definitions using underscore if specifying more than two words in your program
// First letter after every underscore shud be capital

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
void yyerror(char *);
int yylex(void);
int sym[26];

%}

%%

Module: 
    MODULE IDENT ';' Main_Block END IDENT '.'
    ;

Main_Block:
       Import_Modules Decl_Seq Stat_Block
    ;

Import_Modules: 
    IMPORT Import_Modules_List ';'
    |
    ;

Import_Modules_List: 
    Import_Modules_List ',' Import  
    | Import
    ;

Import:
    IDENT ASSIGN IDENT
    | IDENT
    ;

Stat_Block:
    BEG Statement_Sequence
    | 
    ;

Statement_Sequence:
    Statement ';' Statement_Sequence
    | Statement ';'
    ;

Statement    : 
  Designator ASSIGN Expr 
| Designator
| IF_COND Expr THEN Statement_Sequence Else_If_Block Else END 
| CASE_COND Expr OF Case_Parameters Else END 
| WHILE Expr DOCASE Statement_Sequence END 
| REPEAT Statement_Sequence UNTIL Expr
| FOR IDENT ASSIGN Expr TO Expr BY ConstExpr DOCASE Statement_Sequence END 
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
| Expr PLUS_SYM Expr
| Expr MINUS_SYM Expr
| Expr OR Expr
| Expr MULTIPLY_SYM Expr
| Expr DIVIDE_SYM Expr
| Expr DIV Expr
| Expr MOD Expr
| Expr AND_SYM Expr
| Factor
;

Factor       : 
  Designator
| INTEGER_VAL
| CHAR_VAL
| NIL 
| Set 
| '(' Expr ')' 
| TILDA Factor
;
  
Designator   : 
  IDENT optSuffix
;

optSuffix :
  '.' IDENT  optSuffix
| '[' ExprList ']'  optSuffix
| '^'  optSuffix
| '(' ExprList ')' optSuffix   /* Changes from original grammar */
| '(' ')'                      /* Changes from original grammar */
|
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
  Case_Expression_List ':' Statement_Sequence
|
;

Case_Expression_List:                // Case label list beacuse of the expression matching could be to a integer but also to a list of integers or list of expressions
  Case_Expression  
| Case_Expression ',' Case_Expression_List
;

Case_Expression: 
  Expr 
| Expr DOTDOT Expr
;

Decl_Seq: 
  Data_List ProcList
;

Data_List:
  CONST Const_List Data_List 
| TYPE  Type_List  Data_List
| VAR   Var_List Data_List
|
;

Const_List :
  Identifier_list EQ_COMP ConstExpr ';' Const_List
| 
;

// We have to commence from here....
// We have to commence from here....
// We have to commence from here....
// We have to commence from here....


Type_List : 
  Identifier_List EQ_COMP Type ';' Type_List
|
;

VarList  : 
  IdentDefList ':' Type ';' VarList
| 
;

Identifier_List:
  IDENT      
| IDENT ',' Identifier_List
;

Type: 
Qualident
| ARRAY ConstExprList OF Type 
| ARRAY               OF Type 
| RECORD Type_List END                         // Changes Look at it
| RECORD                 FieldList END
| POINTER TO Type
| PROCEDURE FormalPars
;

Qualident    :             // For referencing a particular data type
  IDENT       
| IDENT '.' IDENT          // For referencing an object within in a different module 
;

ProcList     :
  ProcDecl ';' ProcList
| ForwardDecl ';' ProcList
|
;

ProcDecl     : 
  PROCEDURE Receiver IdentDef FormalPars ';' 
            DeclSeq StatBlock
  END ident
;

ForwardDecl :
  PROCEDURE '^' Receiver IdentDef FormalPars
;


FormalPars: 
  '(' FPsectionList ')' ':' Qualident
| '(' FPsectionList ')' 
|  '(' ')'
|
;

FPsectionList:
  FPsection ';' FPsectionList
| FPsection
;

FPsection:
  IdentList ':' Type 
| VAR IdentList ':' Type
;

IdentList:
  IdentList ',' ident
| ident
;

Receiver: 
  '(' ident ':' ident ')'
| '(' VAR ident ':' ident ')'
| 
;


ConstExprList :
  ConstExpr ',' ConstExprList
| ConstExpr
;

FieldList    : 
  IdentDefList ':' Type ';' FieldList
| IdentDefList ':' Type
|
;

ConstExpr    : 
  Expr
;

Set          : 
  '{' optElementList '}'
;

optElementList :
  ElementList
| 
;

ElementList :
  Element ',' ElementList
| Element 
;

Element      : 
  Expr 
| Expr DOTDOT Expr
;

ExprList     : 
  Expr 
| Expr ',' ExprList
;

IdentDefList    : 
  IdentDef      
| IdentDef ',' IdentDefList
                
;

IdentDef     : 
  ident      
| ident MULTIPLY_SYM
| ident MINUS_SYM
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

