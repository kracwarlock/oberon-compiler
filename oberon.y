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
%token BOOLEAN_VAL CHAR_VAL INTEGER_VAL REAL_VAL STRING_VAL ident
// %token ident    OF
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
    MODULE ident ';' ImportList DeclSeq StatBlock END ident '.'
    ;

ImportList: 
    IMPORT ImportListTemp ';'
    |
    ;

ImportListTemp: 
    ImportListTemp ',' Import  
    | Import
    ;

Import:
    ident ASSIGN ident
    | ident
    ;

StatBlock:
    BEG StatementSeq
    | 
    ;

DeclSeq: 
  DataList ProcList
;

DataList:
  CONST ConstList DataList 
| TYPE  TypeList  DataList
| VAR   VarList DataList
|
;

ConstList :
  IdentDef EQ_COMP ConstExpr ';' ConstList
| 
;

TypeList : 
  IdentDef EQ_COMP Type ';' TypeList
|
;

VarList  : 
  IdentDefList ':' Type ';' VarList
| 
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

Type: 
Qualident
| ARRAY ConstExprList OF Type 
| ARRAY               OF Type 
| RECORD '('Qualident')' FieldList END
| RECORD                 FieldList END
| POINTER TO Type
| PROCEDURE FormalPars
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

StatementSeq : 
  Statement ';' StatementSeq
| Statement
;

Statement    : 
  Designator ASSIGN Expr 
| Designator
| IF_COND Expr THEN StatementSeq ElseIfBlock Else END 
| CASE_COND Expr OF CaseList Else END 
| WHILE Expr DOCASE StatementSeq END 
| REPEAT StatementSeq UNTIL Expr 
| FOR ident ASSIGN Expr TO Expr BY ConstExpr DOCASE StatementSeq END 
| FOR ident ASSIGN Expr TO Expr DOCASE StatementSeq END 
| LOOP StatementSeq END
| WITH GuardStatList Else END
| EXIT 
| RETURN Expr
| RETURN
|
;

ElseIfBlock:
  ELSEIF Expr THEN StatementSeq ElseIfBlock
|
;

Else:
  ELSE StatementSeq
|
;

CaseList:
  Case
| Case OR_SYM CaseList
;

Case: 
  CaseLabelList ':' StatementSeq
|
;

CaseLabelList:
  CaseLabels
| CaseLabels ',' CaseLabelList
;

CaseLabels: 
  ConstExpr 
| ConstExpr DOTDOT ConstExpr
;

GuardStatList :
  Guard DOCASE StatementSeq OR_SYM GuardStatList
| Guard DOCASE StatementSeq 
;

Guard        : 
  Qualident ':' Qualident
;

ConstExpr    : 
  Expr
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
| INTEGER
| CHAR
| NIL 
| Set 
| '(' Expr ')' 
| TILDA Factor
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

Designator   : 
  ident optSuffix
;

optSuffix :
  '.' ident  optSuffix
| '[' ExprList ']'  optSuffix
| '^'  optSuffix
| '(' ExprList ')' optSuffix   /* Changes from original grammar */
| '(' ')'                      /* Changes from original grammar */
|
;

ExprList     : 
  Expr 
| Expr ',' ExprList
;

IdentDefList    : 
  IdentDef      
| IdentDef ',' IdentDefList
                
;

Qualident    : 
  ident         
| ident '.' ident
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

