%{
  extern char *yytext;
  extern int yylineno;
  int yyerror(char *msg);

%}

%token IDENT    OF
%token REPEAT   UNTIL   REPEAT
%token UNTIL    FOR     TO
%token BY       DO      END
%token WHILE    IF_COND THEN
%token ELSEIF   ELSE    CASE_COND
%token BOOLEAN  CHAR    INT
%token REAL     STRING  LONGREAL
%token ARRAY    BEG     CONST
%token EXIT     IMPORT  LOOP
%token MODULE   NIL     POINTER
%token RETURN   TYPE    PROCEDURE
%token VAR      WITH
%token OR       
%token ASSIGN   LE    GE    DOTDOT

%nonassoc '='  '#'  LT  LE  GT  GE  IN  IS
%nonassoc UPLUS UMINUS
%left '+'  '-'  OR
%left '*'  '/'  DIV  MOD  '&'


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
    BBEGIN StatementSeq
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
  IdentDef '=' ConstExpr ';' ConstList
| 
;

TypeList : 
  IdentDef '=' Type ';' TypeList
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
| IF Expr THEN StatementSeq ElseIfBlock Else END 
| CASE Expr OF CaseList Else END 
| WHILE Expr DO StatementSeq END 
| REPEAT StatementSeq UNTIL Expr 
| FOR ident ASSIGN Expr TO Expr BY ConstExpr DO StatementSeq END 
| FOR ident ASSIGN Expr TO Expr DO StatementSeq END 
| LOOP StatementSeq END
| WITH GuardStatList Else END
| EXIT 
| RETURN Expr
| RETURN
|
;

ElseIfBlock:
  ELSIF Expr THEN StatementSeq ElseIfBlock
|
;

Else:
  ELSE StatementSeq
|
;

CaseList:
  Case
| Case '|' CaseList
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
| ConstExpr DOTS ConstExpr
;

GuardStatList :
  Guard DO StatementSeq '|' GuardStatList
| Guard DO StatementSeq 
;

Guard        : 
  Qualident ':' Qualident
;

ConstExpr    : 
  Expr
;

Expr         : 
/* Relations */
  Expr '=' Expr
| Expr '#' Expr
| Expr LT Expr
| Expr LE Expr
| Expr GT Expr
| Expr GE Expr
| Expr IN Expr
| Expr IS Expr
| '+' Expr %prec UPLUS
| '-' Expr %prec UMINUS
| Expr '+' Expr
| Expr '-' Expr
| Expr OR Expr
| Expr '*' Expr
| Expr '/' Expr
| Expr DIV Expr
| Expr MOD Expr
| Expr '&' Expr
| Factor
;

Factor       : 
  Designator
| CONSTnum 
| CONSTchar 
| CONSTstring 
| NIL 
| Set 
| '(' Expr ')' 
| '~' Factor
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
| Expr DOTS Expr
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
| ident '*'    
| ident '-'
;


%%

int main()
{
  int res = yyparse();
  if (res==0)
    printf("Successful parse\n");
  else
    printf("Encountered errors\n");
  exit(res);
}


